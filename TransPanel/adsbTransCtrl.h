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

	void process_data(const std::string& data) ; //����Ӳ����������

	std::string cmd_emit_enable(bool enable); //��������
	std::string cmd_emit_test(bool enable) ;  //�������
	std::string cmd_emit_mode(bool syncMode); //����ģʽ
	std::string cmd_adsb_upload_enable(bool enable); //�����ϴ�
	std::string	cmd_adsb_upload_mode(bool enable); //�ϴ�ģʽ
	std::string cmd_gps_source(bool enable); //GPSԴ
	std::string cmd_connect_test(); //���Ӳ���
	std::string cmd_save_config(const std::string& icao , const std::string& id ,unsigned int frequency) ; //��������
public :

		int lmx_state; //Ƶ��Դ������
		int adsb_trans_state; //�����ѿ���
		int adsb_trans_test_state; //�����������
		int adsb_trans_sync_state; //ͬ������ģʽ
		int adsb_upload_en_state; //�����ϴ�����
		int adsb_upload_mode_state ;//���ս����ϴ�
		int location_system_state; //��λϵͳ����
		int location_source_state; //ʹ���ⲿ��λϵͳ
		int temper_state ; //�¶ȴ���������
		int press_state ;  //��ѹ����������
		int rcvnum ;  //�����ձ�������
		int lost_cnt ; //����������
		ICAO icao ;		//ICAO���
		char flight_id[9] ; //�����
		int Gps_Num ; //GPS���Ǹ���
		double plat_lon;//GPS����
		double plat_lat ; //GPSγ��
		double plat_alt ; //GPS�߶�
		int Msg_Num ; //��Ϣ����
		double Temp ; //�¶�
		double Press ; //ѹ��
		struct tm current_gps_time ; //��ǰʱ��
};




#endif
