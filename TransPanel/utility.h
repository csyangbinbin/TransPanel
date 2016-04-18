#ifndef __TRANSPANEL_UTILITY_INCLUDE__
#define __TRANSPANEL_UTILITY_INCLUDE__
#include <windows.h>
#include <vector>
#include <time.h>
#include <stdio.h>

#define LOG(...)\
	do {\
	char tmpbuf[9];\
	_strtime_s( tmpbuf, 9 );\
	fprintf(stdout,"[%s]-" ,tmpbuf );\
	fprintf(stdout ,__VA_ARGS__);\
	fprintf(stdout,"\r\n");} while (0);


typedef std::vector<int>	serialPortList_t ;

//枚举系统中存在的串口
void EnumerateSerialPorts(serialPortList_t& portsu,  //正在被指使用的串口
	serialPortList_t& portse,	//未被使用的串口
	serialPortList_t& ports		//所有的串口
	) ;	 


unsigned long  SplitStr2Bin(const unsigned char* data ,int  bit_idx ,int len) ;

double GPS_DM_2_DOT(int flag , unsigned long  F ,unsigned long B) ; 

//字节的指定位置1
#define BIT_SET(b,n ,i) \
	do {\
	if(i)\
{ b|=(1<<n) ;}\
	} while (0);

#endif