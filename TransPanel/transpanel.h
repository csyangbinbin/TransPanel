#ifndef TRANSPANEL_H
#define TRANSPANEL_H

#include <QtGui/QDialog>
#include "ui_transpanel.h"
#include "serialPort.h"
#include "utility.h"
#include "adsbTransCtrl.h"

#define SHOW_INFO 1
#define SHOW_WARN 2
#define SHOW_ERROR 3

#define  SINFO(m)	do{showMessage(m,SHOW_INFO);}while(0) ; 
#define  SWARN(m)	do{showMessage(m,SHOW_WARN);}while(0) ; 
#define  SERROR(m)	do{showMessage(m,SHOW_ERROR);}while(0) ; 

//Ĭ��ʹ�õĴ��ڲ�����
#define  DEFAULT_SERIALPORT_BAUD	(115200)

class TransPanel : public QDialog
{
	Q_OBJECT

public:
	TransPanel(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TransPanel();

private:
	void initWidget() ; 
	void showMessage(const QString& msg ,int level = 1); 
	void recvSerialPortDataCB(std::string	data);
	void recvSerialPortErrorCB(boost::system::error_code ec);
	void sendCMD(std::string cmd);
	void cmdSendInfo(const std::string& cmd);

	bool validICAO(const QString& icao_addr);
	bool validID(const QString& id) ; 

signals: 
	void devStatusChange(std::string); 

	private slots:
		void onClickBtnSerialPortOpen() ;  //�򿪴���
		void onClickBtnConnectTest() ; //���Ӳ���
		void onClickBtnEnableEmit() ; //��������
		void onClickBtnEmitTest() ; //�������
		void onClickBtnEmitMode() ; //����ģʽ
		void onClickBtnAdsbUploadEnable() ; //ADS-B�����ϴ�
		void onClickBtnAdsbUploadMode() ;//ADS-B�ϴ�ģʽ
		void onClickBtnSaveConfig() ; //��������
		void onClickBtnHelp() ; //������ť
		void onClickBtnGPSSource() ; //GPSԴ
		void onClickBtnExit() ;//�˳�
		void onClickBtnAbout() ;//����

		void onDevStatusChange(std::string data);
		

private:
	Ui::TransPanelClass ui;
	SerialPort* serialPort_ ; 
	adsbTransCtrl adsb_trans_ctrl_ ;
};

#endif // TRANSPANEL_H
