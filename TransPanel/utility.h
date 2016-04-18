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

//ö��ϵͳ�д��ڵĴ���
void EnumerateSerialPorts(serialPortList_t& portsu,  //���ڱ�ָʹ�õĴ���
	serialPortList_t& portse,	//δ��ʹ�õĴ���
	serialPortList_t& ports		//���еĴ���
	) ;	 


unsigned long  SplitStr2Bin(const unsigned char* data ,int  bit_idx ,int len) ;

double GPS_DM_2_DOT(int flag , unsigned long  F ,unsigned long B) ; 

//�ֽڵ�ָ��λ��1
#define BIT_SET(b,n ,i) \
	do {\
	if(i)\
{ b|=(1<<n) ;}\
	} while (0);

#endif