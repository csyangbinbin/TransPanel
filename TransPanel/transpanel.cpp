#include "stdafx.h"
#include "transpanel.h"
#include "utility.h"

TransPanel::TransPanel(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
	,serialPort_(NULL)
{
	ui.setupUi(this);

	initWidget() ; //��ʼ���ؼ�

	connect(ui.pushButton_com_open, SIGNAL(clicked()), this, SLOT(onClickBtnSerialPortOpen()));  //���ڴ�
	connect(ui.pushButton_connect_test, SIGNAL(clicked()), this, SLOT(onClickBtnConnectTest()));  //���Ӳ���
	connect(ui.pushButton_emit, SIGNAL(clicked()), this, SLOT(onClickBtnEnableEmit()));  //��������
	connect(ui.pushButton_emit_test, SIGNAL(clicked()), this, SLOT(onClickBtnEmitTest())); //�������
	connect(ui.pushButton_emit_mode, SIGNAL(clicked()), this, SLOT(onClickBtnEmitMode())); //����ģʽ
	connect(ui.pushButton_rcv_upload, SIGNAL(clicked()), this, SLOT(onClickBtnAdsbUploadEnable())); //�����ϴ�����
	connect(ui.pushButton_rcv_upload_mode, SIGNAL(clicked()), this, SLOT(onClickBtnAdsbUploadMode())); //�ϴ�ģʽ
	connect(ui.pushButton_save_cfg, SIGNAL(clicked()), this, SLOT(onClickBtnSaveConfig())); //��������
	connect(ui.pushButton_help, SIGNAL(clicked()), this, SLOT(onClickBtnHelp())); //����
	connect(ui.pushButton_gps_source, SIGNAL(clicked()), this, SLOT(onClickBtnGPSSource())); //GPSԴ
	connect(ui.pushButton_exit, SIGNAL(clicked()), this, SLOT(onClickBtnExit())); //�˳�
	connect(ui.pushButton_about, SIGNAL(clicked()), this, SLOT(onClickBtnAbout())); //����
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
		com_error.sprintf("���ڶ�ȡ����:%s" ,ec.message().c_str() );
		SERROR(com_error);
	}


}


void TransPanel::onDevStatusChange(std::string data)
{
	adsb_trans_ctrl_.process_data(data);

	//���½�����Ϣ
	//1.ʱ��
	QString str ; 
	if(adsb_trans_ctrl_.location_system_state)
	{
		str.sprintf("ʱ��:%04d/%02d/%02d %02d:%02d:%02d" , 
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
		str ="�豸ʱ��:δ֪";
	}

	ui.label_si_devtime->setText(str);

	//2.ICAO��ַ

	str.sprintf("ICAO��:%02X%02X%02X" ,
		adsb_trans_ctrl_.icao.m1 ,
		adsb_trans_ctrl_.icao.m2 ,
		adsb_trans_ctrl_.icao.m3);
	ui.label_si_icaoaddr->setText(str);

	//3.ID��
	str.sprintf("ID��:%s" , adsb_trans_ctrl_.flight_id);
	ui.label_si_ID->setText(str);

	//4.���Ǹ���
	str.sprintf("����:%d" ,adsb_trans_ctrl_.Gps_Num);
	ui.label_si_satcount->setText(str);

	//���ȣ�γ�ȣ��߶�

	if(adsb_trans_ctrl_.location_system_state)
	{
		str.sprintf("����:%.6f" , adsb_trans_ctrl_.plat_lon) ; 
		ui.label_si_lon->setText(str);

		str.sprintf("γ��:%.6f" , adsb_trans_ctrl_.plat_lat) ; 
		ui.label_si_lat->setText(str);


		str.sprintf("�߶�:%.2f" , adsb_trans_ctrl_.plat_alt) ; 
		ui.label_si_alt->setText(str);
	}
	else
	{
		ui.label_si_lon->setText("����:--");
		ui.label_si_lat->setText("γ��:--");
		ui.label_si_alt->setText("�߶�:--");

	}

	//������
	str.sprintf("������:%d" ,adsb_trans_ctrl_.Msg_Num);
	ui.label_si_revcount->setText(str);

	//�¶�
	str.sprintf("�¶�:%.2f ��" , adsb_trans_ctrl_.Temp);
	ui.label_si_tmp->setText(str);

	//��ѹ
	str.sprintf("��ѹ:%.4f hPa",adsb_trans_ctrl_.Press );
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


	//Ƶ��Դ
	SHOW_LABEL(adsb_trans_ctrl_.lmx_state ,ui.label_zi_frp ,"Ƶ��Դ������" , "Ƶ��Դδ����" ,1 );
	//��λ״̬
	SHOW_LABEL(adsb_trans_ctrl_.location_system_state ,ui.label_zi_loc ,"��λϵͳ����" , "��λϵͳ�쳣"  ,1);
	//�¶ȴ�����
	SHOW_LABEL(adsb_trans_ctrl_.temper_state ,ui.label_zi_tmp ,"�¶ȴ���������" , "�¶ȴ������쳣" ,1 );
	//��ѹ������
	SHOW_LABEL(adsb_trans_ctrl_.press_state ,ui.label_zi_hpa ,"��ѹ����������" , "��ѹ�������쳣"  ,1);

	//�����״̬
	SHOW_LABEL(adsb_trans_ctrl_.adsb_trans_state ,ui.label_jh_emit ,"�����ѿ���" , "�����ѹر�"  ,0);
	//�������
	SHOW_LABEL(adsb_trans_ctrl_.adsb_trans_test_state ,ui.label_jh_emit_test ,"�����������" , "������Թر�"  ,0);
	//����ģʽ
	SHOW_LABEL(adsb_trans_ctrl_.adsb_trans_sync_state ,ui.label_jh_nor_emit ,"ͬ������ģʽ" , "��������ģʽ" ,0 );
	//�ϴ�
	SHOW_LABEL(adsb_trans_ctrl_.adsb_upload_en_state ,ui.label_jh_upload ,"�����ϴ�����" , "�����ϴ��ر�" ,0 );
	//�ϴ�ģʽ
	SHOW_LABEL(adsb_trans_ctrl_.adsb_upload_mode_state ,ui.label_jh_rcv_upload ,"���ս����ϴ�" , "����ԭʼ�ϴ�" ,0 );
	//GPS����Դ
	SHOW_LABEL(adsb_trans_ctrl_.location_source_state ,ui.label_jh_out_loc ,"ʹ���ⲿ��λϵͳ" , "ʹ���ڲ���λϵͳ" ,0 );



#define SET_BTN_TEXT(s,n,s1,s2) \
	do { \
	if(s)\
	n->setText(s1); \
	else\
	n->setText(s2);\
	} while (0);

	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_trans_state , ui.pushButton_emit , "�رշ���" ,"��������");
	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_trans_sync_state , ui.pushButton_emit_mode , "��������ģʽ" ,"��������ģʽ");
	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_upload_en_state , ui.pushButton_rcv_upload , "�����ϴ��ر�" ,"�����ϴ�����");
	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_upload_mode_state , ui.pushButton_rcv_upload_mode , "����ԭʼ�ϴ�" ,"���ս����ϴ�");
	SET_BTN_TEXT(adsb_trans_ctrl_.location_source_state , ui.pushButton_gps_source , "ʹ���ڲ���λ" ,"ʹ���ⲿ��λ");
	SET_BTN_TEXT(adsb_trans_ctrl_.adsb_trans_test_state , ui.pushButton_emit_test , "������Թر�" ,"�����������");

	//������Ϣ��������
	//| ����״̬> ������:--- ȫ������:---
	str.sprintf("| ����״̬> ������:%d ȫ������:%d" ,adsb_trans_ctrl_.lost_cnt , adsb_trans_ctrl_.rcvnum );
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
	LOG("ѡ�񴮿�:%d\r\n" ,portNum );

	if(serialPort_==NULL)
	{
		serialPort_ = new SerialPort(portNum ,DEFAULT_SERIALPORT_BAUD);
		if(serialPort_ == NULL)
			return ;

		serialPort_->set_recv_data_callback(boost::bind(&TransPanel::recvSerialPortDataCB ,this,_1));//���ݻص�
		serialPort_->set_recv_error_callback(boost::bind(&TransPanel::recvSerialPortErrorCB ,this,_1)); //����ص�

	
		bool openSuccess = serialPort_->open() ;  //�򿪴���
		if(!openSuccess)
		{
			std::string error_msg = serialPort_->get_last_error_message() ;
			char errorMessage[512] ; 
			sprintf_s(errorMessage,512 , "COM%d ��ʧ��,����ԭ��:%s" ,portNum , error_msg.c_str()  );
			LOG(errorMessage);
			SERROR(errorMessage);

			ui.pushButton_com_open->setText("�򿪴���");
			delete serialPort_ ;
			serialPort_ =NULL ; 

		}
		else
		{
			char message[512] ; 
			sprintf_s(message , 512 ,"COM%d �򿪳ɹ�!" , portNum);
			LOG(message);
			SINFO(message);

			ui.pushButton_com_open->setText("�رմ���");
			spCombox->setEnabled(false);
		}
	}
	else
	{
	
		serialPort_->close() ;
		delete serialPort_ ;
		serialPort_ = NULL ; 

		char message[512] ; 
		sprintf_s(message , 512 ,"COM%d �Ѿ��ر�!" , portNum);
		LOG(message);
		SINFO(message);

		ui.pushButton_com_open->setText("�򿪴���");
		spCombox->setEnabled(true);
	}

}

void TransPanel::showMessage(const QString& msg ,int level)
{
	QString headStr ; 
	QString styleStr ;

	if(level == SHOW_INFO)
	{
		headStr ="[��Ϣ]:";
		styleStr = "color:green" ; 
	}
	else if(level == SHOW_WARN)
	{
		headStr ="[����]:";
		styleStr = "color:yello" ;
	}
	else
	{
		headStr ="[����]:";
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

	//ö�ٴ��ڵĴ���
	EnumerateSerialPorts(portsu , portse , ports);

	//��Ӵ��ڵ��б�
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
		SERROR("�����ʧ��!");
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
		QMessageBox::critical(this , "����" , "Ƶ��Դ���ô���,ȡֵ��Χ[1080-1100]!");
		return	 ; 
	}

	bool icao_valid = validICAO(ICAO_str);
	if(!icao_valid)
	{
		QMessageBox::critical(this , "����" , "ICAO��ַ����Ϊ6���ֽڳ���,0-Fʮ�������ַ�!");
		return	;
	}

	bool id_valid = validID(ID_str);
	if(!id_valid)
	{
		QMessageBox::critical(this , "����" , "ID�ų��Ȳ��ܳ���8���ַ�!");
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

	QString info_str = "�����ѷ���:[" +tmp + "]" ;

	SINFO(info_str);

}