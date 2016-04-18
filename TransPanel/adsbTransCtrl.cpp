#include "stdafx.h"
#include "adsbTransCtrl.h"
#include "utility.h"


adsbTransCtrl::adsbTransCtrl()
{
	lmx_state = 0; //频率源已锁定
	adsb_trans_state= 0; //发射已开启
	adsb_trans_test_state= 0; //发射测试启动
	adsb_trans_sync_state= 0; //同步发射模式
	adsb_upload_en_state= 0; //接收上传开启
	adsb_upload_mode_state =0;//接收解码上传
	location_system_state= 0; //定位系统正常
	location_source_state= 0; //使用外部定位系统
	temper_state = 0; //温度传感器正常
	press_state = 0;  //气压传感器正常

	rcvnum =0 ;
	lost_cnt = 0 ;

	icao.m1 =0;
	icao.m2 =0;
	icao.m3 =0;
	memset(flight_id ,0 , 9 ) ; 

	Gps_Num = 0 ;
	Msg_Num = 0 ;
	Temp = 0;
	Press = 0 ;

	memset(&current_gps_time , 0 ,sizeof(tm));
}
adsbTransCtrl::~adsbTransCtrl()
{

}
typedef unsigned char BYTE ; 
BYTE Convert2Byte(const BYTE* pByte,int Index)//???:Index?????1
{

	if(Index%2==1) //????
	{
		return pByte[Index/2];
	}
	else //???
	{
		BYTE Ret = 0;
		BYTE a = pByte[Index/2-1]; 
		BYTE b = pByte[Index/2];

		BYTE t1 = a&0x0F;
		Ret = Ret|t1;
		Ret = Ret<<4;
		BYTE t2 = b&0xF0;
		t2 =t2>>4;
		Ret = Ret|t2;
		return Ret;
	}
}
static const char CharLookup[] =  " ABCDEFGHIJKLMNOPQRSTUVWXYZ                     0123456789     ";


void adsbTransCtrl::process_data(const std::string& data) 
{
#define BIT1(b,i)  ((b>>i)&0x01)

	rcvnum++ ;  //接收报文计数

	if(data.size()!=40)
	{
		//printf("process_data error:data size != 40\r\n");

		LOG("接收报文长度错误-[%d]!" ,data.size() );
		lost_cnt++ ;  //错误报文计数
		return	 ; 
	}

	const  unsigned  char* dataPtr = (const unsigned char*)(data.c_str());

	unsigned char flagH  =dataPtr[2] ;
	unsigned char flagL  =dataPtr[3] ;

	//数据有效标志位
	lmx_state = BIT1(flagH , 7);
	adsb_trans_state = BIT1(flagH , 6);
	adsb_trans_test_state =BIT1(flagH , 5);
	adsb_trans_sync_state = BIT1(flagH , 4);
	adsb_upload_en_state = BIT1(flagH , 3);
	adsb_upload_mode_state = BIT1(flagH ,2);
	location_system_state = BIT1(flagH , 1);
	location_source_state = BIT1(flagH , 0);
	temper_state = BIT1(flagL , 7);
	press_state = BIT1(flagL , 6);

	if(location_system_state )
	{
		//系统时间
		current_gps_time.tm_year = dataPtr[13] +2000;
		current_gps_time.tm_mon= dataPtr[14] ;
		current_gps_time.tm_mday= dataPtr[15] ;
		current_gps_time.tm_hour = dataPtr[16] ;
		current_gps_time.tm_min = dataPtr[17] ;
		current_gps_time.tm_sec= dataPtr[18] ;
	}
	else
	{
		memset(&current_gps_time , 0 ,sizeof(tm));
	}

	//ICAO 编号
	icao.m1 = dataPtr[4] ;
	icao.m2 = dataPtr[5];
	icao.m3 = dataPtr[6] ; 

	//航班号
	flight_id[0] = CharLookup[Convert2Byte(dataPtr,15)>>2];
	flight_id[1] = CharLookup[Convert2Byte(dataPtr,16)%64];
	flight_id[2] = CharLookup[Convert2Byte(dataPtr,18)>>2];
	flight_id[3] = CharLookup[Convert2Byte(dataPtr,19)%64];
	flight_id[4] = CharLookup[Convert2Byte(dataPtr,21)>>2];
	flight_id[5] = CharLookup[Convert2Byte(dataPtr,22)%64];
	flight_id[6] = CharLookup[Convert2Byte(dataPtr,24)>>2];
	flight_id[7] = CharLookup[Convert2Byte(dataPtr,25)%64];

	//GPS搜星个数
	Gps_Num = location_system_state?dataPtr[19]:0;


	//GPS定位信息
	if(location_system_state ==1)
	{
		const unsigned char* LocDataPtr = &dataPtr[20];
		int lon_flag = (LocDataPtr[0]>>7)&0x01;
		int lat_flag = (LocDataPtr[0]>>6)&0x01;
		int alt_flag = (LocDataPtr[0]>>5)&0x01 ;

		unsigned long  lon_Z = SplitStr2Bin(LocDataPtr , 6,15);
		unsigned long lon_X = SplitStr2Bin(LocDataPtr , 21,14);
		unsigned long lat_Z = SplitStr2Bin(LocDataPtr , 35,15);
		unsigned long lat_X = SplitStr2Bin(LocDataPtr , 50,14);
		unsigned long int alt = SplitStr2Bin(LocDataPtr , 64,16);

		plat_lon = GPS_DM_2_DOT(lon_flag , lon_Z , lon_X);
		plat_lat = GPS_DM_2_DOT(lat_flag , lat_Z , lat_X);
		plat_alt = alt_flag?( alt):(-1.0 *alt) ; 

	}
	else
	{
		plat_lon =0;
		plat_lat = 0;
		plat_alt =0 ;
	}

	Msg_Num =   htons(*((unsigned short*)&dataPtr[32])) ; //2字节
	Temp = (dataPtr[34]*256 +dataPtr[35])*0.03125 ; 
	Press = ((dataPtr[36]*256+dataPtr[37])-1638)* 0.0789  ; 
}

std::string adsbTransCtrl::cmd_emit_enable(bool enable)
{
	char disable_cmd[] = "\x14\x6F\x05\x33\x48\x52\x44\x01";
	char enable_cmd[] = "\x14\x6F\x05\x33\x48\x52\x44\x02";

	return enable?enable_cmd:disable_cmd ; 
}

std::string adsbTransCtrl::cmd_emit_test(bool enable) 
{
	char disable_cmd[] = "\x14\x6F\x05\x33\x48\x52\x44\x0b";
	char enable_cmd[] = "\x14\x6F\x05\x33\x48\x52\x44\x0c";

	return enable?enable_cmd:disable_cmd ;
}

std::string adsbTransCtrl::cmd_emit_mode(bool syncMode)
{ 
	char sync_cmd[] =   "\x14\x6F\x05\x33\x48\x52\x44\x04";
	char normal_cmd[] = "\x14\x6F\x05\x33\x48\x52\x44\x03";

	return syncMode?sync_cmd:normal_cmd;

}

std::string adsbTransCtrl::cmd_adsb_upload_enable(bool enable)
{
	char disable_cmd[] = "\x14\x6F\x05\x33\x48\x52\x44\x05";
	char enable_cmd[] =  "\x14\x6F\x05\x33\x48\x52\x44\x06";

	return enable?enable_cmd:disable_cmd ;
}

std::string	adsbTransCtrl::cmd_adsb_upload_mode(bool enable)
{
	char disable_cmd[] = "\x14\x6F\x05\x33\x48\x52\x44\x07";
	char enable_cmd[] =  "\x14\x6F\x05\x33\x48\x52\x44\x08";

	return enable?enable_cmd:disable_cmd ;
}

std::string adsbTransCtrl::cmd_gps_source(bool enable)
{
	char disable_cmd[] = "\x14\x6F\x05\x33\x48\x52\x44\x09";
	char enable_cmd[] =  "\x14\x6F\x05\x33\x48\x52\x44\x0A";

	return enable?enable_cmd:disable_cmd ;
}

std::string adsbTransCtrl::cmd_connect_test()
{
	char cmd[] =  "\x14\x6F\x05\x33\x48\x52\x44\x00";
	return	cmd ;
}

std::string adsbTransCtrl::cmd_save_config(const std::string& icao , const std::string& id ,unsigned int frequency)
{
	char config_info = 0 ;
	BIT_SET(config_info , 5, adsb_trans_test_state);
	BIT_SET(config_info , 4, adsb_trans_state);
	BIT_SET(config_info , 3, adsb_trans_sync_state);
	BIT_SET(config_info , 2, adsb_upload_en_state);
	BIT_SET(config_info , 1, adsb_upload_mode_state);
	BIT_SET(config_info , 0, location_source_state);

	char ID[9] ;
	memset(ID ,' ',9); //空白填充空格
	for(int i_i = id.size()-1 , i=7 ;i_i>=0&&i>=0 ; i--,i_i-- )
	{
	ID[i] = id.at(i_i);
	}

	char cmd_tmp[] = "\x14\x6F\x15\x33\x48\x52\x44\xAA" ;

	char cmd[24] ;
	memcpy(cmd , cmd_tmp , 8);
	memcpy(&cmd[8] ,icao.c_str() , 6 );
	memcpy(&cmd[14] , ID , 8);
	cmd[22] = frequency -1080;
	cmd[23] =config_info ; 

	return std::string(cmd , 24);
}