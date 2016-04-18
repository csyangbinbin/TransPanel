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

//默认使用的串口波特率
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
		void onClickBtnSerialPortOpen() ;  //打开串口
		void onClickBtnConnectTest() ; //连接测试
		void onClickBtnEnableEmit() ; //开启发射
		void onClickBtnEmitTest() ; //发射测试
		void onClickBtnEmitMode() ; //发射模式
		void onClickBtnAdsbUploadEnable() ; //ADS-B接收上传
		void onClickBtnAdsbUploadMode() ;//ADS-B上传模式
		void onClickBtnSaveConfig() ; //保存配置
		void onClickBtnHelp() ; //帮助按钮
		void onClickBtnGPSSource() ; //GPS源
		void onClickBtnExit() ;//退出
		void onClickBtnAbout() ;//关于

		void onDevStatusChange(std::string data);
		

private:
	Ui::TransPanelClass ui;
	SerialPort* serialPort_ ; 
	adsbTransCtrl adsb_trans_ctrl_ ;
};

#endif // TRANSPANEL_H
