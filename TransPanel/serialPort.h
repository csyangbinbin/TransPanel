#ifndef __TRANSPANEL_SERIALPORT_INCLUDE__
#define __TRANSPANEL_SERIALPORT_INCLUDE__

#include <boost/asio.hpp> 
#include <boost/bind.hpp>  
#include <boost/function.hpp>
#include <string>
using namespace boost::asio; 

  typedef boost::function<void (std::string)>	rcv_data_cb ;   //接收数据回调函数
  typedef boost::function<void (boost::system::error_code)>	rcv_error_cb ;  //数据接收错误回调函数

class SerialPort
{
public:
	SerialPort(unsigned int  com_num ,unsigned int baud);
	~SerialPort() ; 

	bool open() ;
	void close() ; 
	void set_recv_data_callback(rcv_data_cb cb);
	void set_recv_error_callback(rcv_error_cb cb);
	std::size_t write(const char* data , unsigned int data_size);
	std::size_t write(const std::string& data) ; 
	std::string get_last_error_message() const { return last_error_msg_ ; }
private:
	void run() ;
	void handle_read(boost::asio::serial_port* port,const boost::system::error_code& ec,size_t byte_read) ;
private :
	unsigned int com_num_ ; 
	unsigned int baud_ ; 
	boost::asio::io_service m_ios; 
	boost::asio::serial_port *pSerialPort; 
	char data[1024];
	rcv_data_cb rcv_data_cb_ ;
	rcv_error_cb	rcv_error_cb_ ;
	std::string last_error_msg_ ; 

} ; 


#endif