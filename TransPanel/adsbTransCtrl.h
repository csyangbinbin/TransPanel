#ifndef __TRANSPANEL_ADSBTRANSCTRL_INCLUDE__
#define __TRANSPANEL_ADSBTRANSCTRL_INCLUDE__



typedef struct ICAO_TAG
{
	unsigned char m1;
	unsigned char m2;
	unsigned char m3;
}ICAO;

class adsbTransCtrl
{
public:
	adsbTransCtrl();
	~adsbTransCtrl() ;

	void process_data(const std::string& data) ; //处理硬件发送数据

	std::string cmd_emit_enable(bool enable); //开启发射
	std::string cmd_emit_test(bool enable) ;  //发射测试
	std::string cmd_emit_mode(bool syncMode); //发射模式
	std::string cmd_adsb_upload_enable(bool enable); //接收上传
	std::string	cmd_adsb_upload_mode(bool enable); //上传模式
	std::string cmd_gps_source(bool enable); //GPS源
	std::string cmd_connect_test(); //连接测试
	std::string cmd_save_config(const std::string& icao , const std::string& id ,unsigned int frequency) ; //保存配置
public :

		int lmx_state; //频率源已锁定
		int adsb_trans_state; //发射已开启
		int adsb_trans_test_state; //发射测试启动
		int adsb_trans_sync_state; //同步发射模式
		int adsb_upload_en_state; //接收上传开启
		int adsb_upload_mode_state ;//接收解码上传
		int location_system_state; //定位系统正常
		int location_source_state; //使用外部定位系统
		int temper_state ; //温度传感器正常
		int press_state ;  //气压传感器正常
		int rcvnum ;  //共接收报文数量
		int lost_cnt ; //错误报文数量
		ICAO icao ;		//ICAO编号
		char flight_id[9] ; //航班号
		int Gps_Num ; //GPS搜星个数
		double plat_lon;//GPS经度
		double plat_lat ; //GPS纬度
		double plat_alt ; //GPS高度
		int Msg_Num ; //消息数量
		double Temp ; //温度
		double Press ; //压力
		struct tm current_gps_time ; //当前时间
};




#endif
