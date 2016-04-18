#include "stdafx.h"
#include "transpanel.h"
#include "utility.h"

TransPanel::TransPanel(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
	,serialPort_(NULL)
{
	ui.setupUi(this);

	initWidget() ; //初始化控件

	connect(ui.pushButton_com_open, SIGNAL(clicked()), this, SLOT(onClickBtnSerialPortOpen()));  //串口打开
	connect(ui.pushButton_connect_test, SIGNAL(clicked()), this, SLOT(onClickBtnConnectTest()));  //连接测试
	connect(ui.pushButton_emit, SIGNAL(clicked()), this, SLOT(onClickBtnEnableEmit()));  //开启发射
	connect(ui.pushButton_emit_test, SIGNAL(clicked()), this, SLOT(onClickBtnEmitTest())); //发射测试
	connect(ui.pushButton_emit_mode, SIGNAL(clicked()), this, SLOT(onClickBtnEmitMode())); //发射模式
	connect(ui.pushButton_rcv_upload, SIGNAL(clicked()), this, SLOT(onClickBtnAdsbUploadEnable())); //接收上传开启
	connect(ui.pushButton_rcv_upload_mode, SIGNAL(clicked()), this, SLOT(onClickBtnAdsbUploadMode())); //上传模式
	connect(ui.pushButton_save_cfg, SIGNAL(clicked()), this, SLOT(onClickBtnSaveConfig())); //保存配置
	connect(ui.pushButton_help, SIGNAL(clicked()), this, SLOT(onClickBtnHelp())); //帮助
	connect(ui.pushButton_gps_source, SIGNAL(clicked()), this, SLOT(onClickBtnGPSSource())); //GPS源
	connect(ui.pushButton_exit, SIGNAL(clicked()), this, SLOT(onClickBtnExit())); //退出
	connect(ui.pushButton_about, SIGNAL(clicked()), this, SLOT(onClickBtnAbout())); //关于
	connect(this, SIGNAL(devStatusChange(std::string)), this, SLOT(onDevStatusChange(std::string))); 


}

TransPanel::~TransPanel()
{

}

void TransPanel::recvSerialPortErrorCB(boost::system::error_code ec)
{
	if(ec.value() != 995)
	{
		LOG( "%d - %s" , ec.value() ,   ec.message().c_str());

		QString com_error;
		com_error.sprintf("串口读取错误:%s" ,ec.message().c_str() );
		SERROR(com_error);
	}


}


void TransPanel::onDevStatusChange(std::string data)
{
	adsb_trans_ctrl_.process_data(data);

	//更新界面信息
	//1.时间
	QString str ; 
	if(adsb_trans_ctrl_.location_system_state)
	{
		str.sprintf("时间:%04d/%02d/%02d %02d:%02d:%02d" , 
			adsb_trans_ctrl_.current_gps_time.tm_year ,
			adsb_trans_ctrl_.current_gps_time.tm_mon ,
			adsb_trans_ctrl_.current_gps_time.tm_mday ,
			adsb_trans_ctrl_.current_gps_time.tm_hour ,
			adsb_trans_ctrl_.current_gps_time.tm_min ,
			adsb_trans_ctrl_.current_gps_time.tm_sec
			);
	}
	else
	{
		str ="设备时间:未知";
	}

	ui.label_si_devtime->setText(str);

	//2.ICAO地址

	str.sprintf("ICAO号:%02X%02X%02X" ,
		adsb_trans_ctrl_.icao.m1 ,
		adsb_trans_ctrl_.icao.m2 ,
		adsb_trans_ctrl_.icao.m3);
	ui.label_si_icaoaddr->setText(str);

	//3.ID号
	str.sprintf("ID号:%s" , adsb_trans_ctrl_.flight_id);
	ui.label_si_ID->setText(str);

	//4.搜星个数
	str.sprintf("搜星:%d" ,adsb_trans_ctrl_.Gps_Num);
	ui.label_si_satcount->setText(str);

	//经度，纬度，高度

	if(adsb_trans_ctrl_.location_system_state)
	{
		str.sprintf("经度:%.6f" , adsb_trans_ctrl_.plat_lon) ; 
		ui.label_si_lon->setText(str);

		str.sprintf("纬度:%.6f" , adsb_trans_ctrl_.plat_lat) ; 
		ui.label_si_lat->setText(str);


		str.sprintf("高度:%.2f" , adsb_trans_ctrl_.plat_alt) ; 
		ui.label_si_alt->setText(str);
	}
	else
	{
		ui.label_si_lon->setText("经度:--");
		ui.label_si_lat->setText("纬度:--");
		ui.label_si_alt->setText("高度:--");

	}

	//接收量
	str.sprintf("接收量:%d" ,adsb_trans_ctrl_.Msg_Num);
	ui.label_si_revcount->setText(str);

	//温度
	str.sprintf("温度:%.2f ℃" , adsb_trans_ctrl_.Temp);
	ui.label_si_tmp->setText(str);

	//气压
	str.sprintf("气压:%.4f hPa",adsb_trans_ctrl_.Press );
	ui.label_si_hpa->setText(str);

#define LABEL_WARN(n)	n->setStyleSheet("color:red");
#define LABEL_NORMAL(n) n->setStyleSheet("color:white");

#define SHOW_LABEL(s,b ,s1 ,s2 ,k) \
	do {\
	if(s){\
	b->setText(s1);\
	LABEL_NORMAL(b);}\
	else{\
	b->setText(s2);\
	if(k) \
	LABEL_WARN(b) ;}\
	} while (0);


	//频率源
	SHOW_LABEL(adsb_trans_ctrl_.lmx_state ,ui.label_zi_frp ,"频率源已锁定" , "频率源未锁定" ,1 );
	//定位状态
	SHOW_LABEL(adsb_trans_ctrl_.location_system_state ,ui.label_zi_loc ,"定位系统正常" , "定位系统异常"  ,1);
	//温度传感器
	SHOW_LABEL(adsb_trans_ctrl_.temper_state ,ui.label_zi_tmp ,"温度传感器正常" , "温度传感器异常" ,1 );
	//气压传感器
	SHOW_LABEL(adsb_trans_ctrl_.press_state ,ui.label_zi_hpa ,"气压传感器正常" , "气压传感器异常"  ,1);

	//发射机状态
	SHOW_LABEL(adsb_trans_ctrl_.adsb_trans_state ,ui.label_jh_emit ,"发射已开启" , "发射已关闭"  ,0);
	//发射测试
	SHOW_LABEL(adsb_trans_ctrl_.adsb_trans_test_state ,ui.label_jh_emit_test ,"发射测试启动" , "发射测试关闭"  ,0);
	//发射模式
	SHOW_LABEL(adsb_trans_ctrl_.adsb_trans_sync_state ,ui.label_jh_nor_emit ,"同步发射模式" , "正常发射模式" ,0 );
	//上传
	SHOW_LABEL(adsb_trans_ctrl_.adsb_upload_en_state ,ui.label_jh_upload ,"接收上传开启" , "接收上传关闭" ,0 );
	//上传模式
	SHOW_LABEL(adsb_trans_ctrl_.adsb_upload_mode_state ,ui.label_jh_rcv_upload ,"接收解码上传" , "接收原始上传" ,0 );
	//GPS数据源
	SHOW_LABEL(adsb_trans_ctrl_.location_source_state ,ui.label_jh_out_loc ,"使用外部定位系统" , "使用内部定位系统" ,0 );



#define SET_BTN_TEXT(s,n,s1,s2) \
	do { \
	if(s)\
	n->setText(s1); \
	else\
	n->setText(s2);\
	} while (0);

	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_trans_state , ui.pushButton_emit , "关闭发射" ,"开启发射");
	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_trans_sync_state , ui.pushButton_emit_mode , "正常发射模式" ,"正常发射模式");
	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_upload_en_state , ui.pushButton_rcv_upload , "接收上传关闭" ,"接收上传开启");
	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_upload_mode_state , ui.pushButton_rcv_upload_mode , "接收原始上传" ,"接收解码上传");
	SET_BTN_TEXT(adsb_trans_ctrl_.location_source_state , ui.pushButton_gps_source , "使用内部定位" ,"使用外部定位");
	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_trans_test_state , ui.pushButton_emit_test , "发射测试关闭" ,"发射测试启动");

	//更新消息接收数量
	//| 报文状态> 错误报文:--- 全部报文:---
	str.sprintf("| 报文状态> 错误报文:%d 全部报文:%d" ,adsb_trans_ctrl_.lost_cnt , adsb_trans_ctrl_.rcvnum );
	ui.label_msg_info->setText(str);
}

void TransPanel::recvSerialPortDataCB(std::string	data)
{
	if(data.size() > 0)
	{
			LOG("recv data- %d" ,data.size() );
	emit devStatusChange(data);
	}

}

void TransPanel::onClickBtnSerialPortOpen()
{
	QComboBox* spCombox = ui.comboBox_serialport ; 
	int currentIdx = spCombox->currentIndex() ; 
	int portNum =spCombox->itemData(currentIdx).toInt();
	LOG("选择串口:%d\r\n" ,portNum );

	if(serialPort_==NULL)
	{
		serialPort_ = new SerialPort(portNum ,DEFAULT_SERIALPORT_BAUD);
		if(serialPort_ == NULL)
			return ;

		serialPort_->set_recv_data_callback(boost::bind(&TransPanel::recvSerialPortDataCB ,this,_1));//数据回调
		serialPort_->set_recv_error_callback(boost::bind(&TransPanel::recvSerialPortErrorCB ,this,_1)); //错误回调

	
		bool openSuccess = serialPort_->open() ;  //打开串口
		if(!openSuccess)
		{
			std::string error_msg = serialPort_->get_last_error_message() ;
			char errorMessage[512] ; 
			sprintf_s(errorMessage,512 , "COM%d 打开失败,错误原因:%s" ,portNum , error_msg.c_str()  );
			LOG(errorMessage);
			SERROR(errorMessage);

			ui.pushButton_com_open->setText("打开串口");
			delete serialPort_ ;
			serialPort_ =NULL ; 

		}
		else
		{
			char message[512] ; 
			sprintf_s(message , 512 ,"COM%d 打开成功!" , portNum);
			LOG(message);
			SINFO(message);

			ui.pushButton_com_open->setText("关闭串口");
			spCombox->setEnabled(false);
		}
	}
	else
	{
	
		serialPort_->close() ;
		delete serialPort_ ;
		serialPort_ = NULL ; 

		char message[512] ; 
		sprintf_s(message , 512 ,"COM%d 已经关闭!" , portNum);
		LOG(message);
		SINFO(message);

		ui.pushButton_com_open->setText("打开串口");
		spCombox->setEnabled(true);
	}

}

void TransPanel::showMessage(const QString& msg ,int level)
{
	QString headStr ; 
	QString styleStr ;

	if(level == SHOW_INFO)
	{
		headStr ="[信息]:";
		styleStr = "color:green" ; 
	}
	else if(level == SHOW_WARN)
	{
		headStr ="[警告]:";
		styleStr = "color:yello" ;
	}
	else
	{
		headStr ="[错误]:";
		styleStr= "color:red" ;
	}

	ui.label_info_show->setText(headStr + msg);
	ui.label_info_show->setStyleSheet(styleStr);
}


void TransPanel::initWidget() 
{
	std::vector<int> portsu ; 
	std::vector<int> portse ; 
	std::vector<int> ports ; 

	//枚举存在的串口
	EnumerateSerialPorts(portsu , portse , ports);

	//添加串口到列表
	for(std::vector<int>::const_iterator it = ports.begin() ; it!=ports.end() ; ++ it)
	{
		int port_num = *it ; 
		QString ComStr ;
		ComStr.sprintf("COM%d" , port_num) ; 
		ui.comboBox_serialport->addItem(ComStr , port_num) ;
	}
}


void TransPanel::sendCMD(std::string cmd)
{
	if(serialPort_ == NULL)
		return ; 
	std::size_t c = serialPort_->write(cmd);
	if(c)
		cmdSendInfo(cmd);
	else
	{
		SERROR("命令发送失败!");
	}
}

void TransPanel::onClickBtnConnectTest()
{
	std::string cmd = adsb_trans_ctrl_.cmd_connect_test();
	sendCMD(cmd);

}
void TransPanel::onClickBtnEnableEmit()
{
	std::string cmd = adsb_trans_ctrl_.cmd_emit_enable(!adsb_trans_ctrl_.adsb_trans_state);
	sendCMD(cmd);
}
void TransPanel::onClickBtnEmitTest()
{
	std::string cmd = adsb_trans_ctrl_.cmd_emit_test(!adsb_trans_ctrl_.adsb_trans_test_state);
	sendCMD(cmd);
}
void TransPanel::onClickBtnEmitMode()
{
	std::string cmd = adsb_trans_ctrl_.cmd_emit_mode(!adsb_trans_ctrl_.adsb_trans_sync_state);
	sendCMD(cmd);
}
void TransPanel::onClickBtnAdsbUploadEnable()
{
	std::string	cmd = adsb_trans_ctrl_.cmd_adsb_upload_enable(!adsb_trans_ctrl_.adsb_upload_en_state);
	sendCMD(cmd);
}
void TransPanel::onClickBtnAdsbUploadMode()
{
	std::string	cmd = adsb_trans_ctrl_.cmd_adsb_upload_mode(!adsb_trans_ctrl_.adsb_upload_mode_state);
	sendCMD(cmd);
}
void TransPanel::onClickBtnSaveConfig()
{
#define MIN_FREQUENCY_VALUE	1080
#define MAX_FREQUENCY_VALUE	1100

	QString ICAO_str = ui.lineEdit_icaoaddr->text() ;
	QString ID_str = ui.lineEdit_trID->text() ; 
	unsigned int frequency = ui.lineEdit_ply->text().toUInt() ;

	if(frequency>MAX_FREQUENCY_VALUE || frequency<MIN_FREQUENCY_VALUE)
	{
		QMessageBox::critical(this , "错误" , "频率源设置错误,取值范围[1080-1100]!");
		return	 ; 
	}

	bool icao_valid = validICAO(ICAO_str);
	if(!icao_valid)
	{
		QMessageBox::critical(this , "错误" , "ICAO地址必须为6个字节长度,0-F十六进制字符!");
		return	;
	}

	bool id_valid = validID(ID_str);
	if(!id_valid)
	{
		QMessageBox::critical(this , "错误" , "ID号长度不能超过8个字符!");
		return	;
	}

	std::string cmd = adsb_trans_ctrl_.cmd_save_config(ICAO_str.toStdString() ,ID_str.toStdString() ,frequency);


	sendCMD(cmd);



}
void TransPanel::onClickBtnHelp()
{
}
void TransPanel::onClickBtnGPSSource()
{
	std::string	cmd = adsb_trans_ctrl_.cmd_gps_source(!adsb_trans_ctrl_.location_source_state);
	sendCMD(cmd);
	cmdSendInfo(cmd);
}
void TransPanel::onClickBtnExit()
{
	close();
}
void TransPanel::onClickBtnAbout() 
{
}

bool TransPanel::validICAO(const QString& icao_addr)
{
#define  ICAO_ADDR_LENGTH	(6)
	if(icao_addr.size()!=ICAO_ADDR_LENGTH)
		return false; 

	char*  data;
	QByteArray ba = icao_addr.toLatin1();    
	data=ba.data();
	for(int i=0;i<6;i++)
	{
		if( !(  
			(data[i]>='0'&&data[i]<='9')
			||(data[i]>='a'&&data[i]<='f') 
			||(data[i]>='A'&&data[i]<='F')
			) )
			return false ;
	}

	return true ;
}
bool TransPanel::validID(const QString& id)
{
#define ID_MAX_LENGTH	8
	return id.size()<=ID_MAX_LENGTH ;
}

void TransPanel::cmdSendInfo(const std::string& cmd)
{
	QString tmp ;
	for(int i=0;i<cmd.size();i++)
	{
		QString str ;
		str.sprintf("%02X " ,(unsigned char)(cmd.at(i)));
		tmp.append(str);
	}

	QString info_str = "命令已发送:[" +tmp + "]" ;

	SINFO(info_str);

}