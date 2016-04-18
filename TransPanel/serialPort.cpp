#include "stdafx.h"
#include "serialPort.h"
#include <boost/thread.hpp>
#include "utility.h"

SerialPort::SerialPort(unsigned int  com_num ,unsigned int baud)
	:com_num_(com_num) 
	,baud_(baud)
	,rcv_data_cb_(0)
	,rcv_error_cb_(0)
{

}
SerialPort::~SerialPort() 
{
	if(pSerialPort)
	{

		pSerialPort->close();
	}
	pSerialPort = NULL ; 
}
void SerialPort::set_recv_data_callback(rcv_data_cb cb)
{
	rcv_data_cb_ = cb ;
}
void SerialPort::set_recv_error_callback(rcv_error_cb cb)
{
	rcv_error_cb_ = cb;
}

void SerialPort::handle_read(boost::asio::serial_port* port,const boost::system::error_code& ec,size_t byte_read)
{
	if (ec)
	{
		if(rcv_error_cb_)
			rcv_error_cb_(ec);
		return;
	}

	if(rcv_data_cb_)
		rcv_data_cb_(std::string(data,byte_read) );

	pSerialPort->async_read_some(boost::asio::buffer(data),
		boost::bind(&SerialPort::handle_read,this ,pSerialPort,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));
}



bool SerialPort::open()
{
	pSerialPort = new serial_port( m_ios );  
	if(pSerialPort == NULL)
	{
		return false ; 
	}
	boost::system::error_code ec;
	char com_str[20];
	sprintf_s(com_str ,20 , "COM%d" , com_num_);

	try
	{
		pSerialPort->open( com_str/*, ec*/ ); 

		pSerialPort->set_option( serial_port::baud_rate( baud_ )/*, ec*/ ); 
		pSerialPort->set_option( serial_port::flow_control( serial_port::flow_control::none )/*, ec*/ ); 
		pSerialPort->set_option( serial_port::parity( serial_port::parity::none )/*, ec*/ ); 
		pSerialPort->set_option( serial_port::stop_bits( serial_port::stop_bits::one )/*, ec*/); 
		pSerialPort->set_option( serial_port::character_size( 8 )/*, ec*/);  
	}
	catch (boost::system::system_error e)
	{
		std::cout<<"打开指定的串口失败，错误原因："<<e.what()<<std::endl;
		last_error_msg_ = e.what() ; 
		delete pSerialPort ; 
		pSerialPort = NULL ; 
		return false ; 

	}


	pSerialPort->async_read_some(boost::asio::buffer(data),
		boost::bind(&SerialPort::handle_read,this ,pSerialPort,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));

	//boost::thread t (boost::bind(&boost::asio::io_service::run,boost::ref(m_ios) ) ) ; 
	boost::thread t (boost::bind(&SerialPort::run ,this ) ) ;


	return true ; 
}

void SerialPort::run()
{
	try
	{
		m_ios.reset();
		m_ios.run() ;
	}
	catch (boost::system::system_error e)
	{
	}

}

void SerialPort::close()
{

	if(pSerialPort)
	{
		pSerialPort->cancel();
		pSerialPort->close() ; 
	}
}

std::size_t SerialPort::write(const char* data , unsigned int data_size)
{
	boost::system::error_code ec;
	std::size_t ret = 	boost::asio::write(*pSerialPort,boost::asio::buffer(data ,data_size),ec);
	if (ec)
	{
		std::cout<<"数据写入串口失败："<<ec.message()<<std::endl;
		return 0;
	}
	return ret ;
}

std::size_t  SerialPort::write(const std::string& data)
{
	return		write(data.c_str() ,data.size() );
}