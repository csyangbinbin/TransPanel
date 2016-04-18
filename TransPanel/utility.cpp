#include "stdafx.h"
#include "utility.h"
#include <boost/dynamic_bitset.hpp>

typedef std::vector<int>	serialPortList_t ;
void EnumerateSerialPorts(serialPortList_t& portsu, serialPortList_t& portse, serialPortList_t& ports)  
{  
#define MAX_COM_PORT_IDX 50

	for (int i=1; i<MAX_COM_PORT_IDX; i++)  
	{  
		//Form the Raw device name  
		char sPort[MAX_PATH] ; 
		sprintf(sPort ,"\\\\.\\COM%d" , i ); 

		//Try to open the port  
		BOOL bSuccess = FALSE;  
		HANDLE hPort = ::CreateFileA(sPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);  
		if (hPort == INVALID_HANDLE_VALUE)  
		{  
			DWORD dwError = GetLastError();  

			if (dwError == ERROR_ACCESS_DENIED)  
			{  
				bSuccess = TRUE;  
				portsu.push_back(i);//已占用的串口  
			}  
		}  
		else  
		{  
			//The port was opened successfully  
			bSuccess = TRUE;  
			portse.push_back(i);      ////可用的串口  
			//Don't forget to close the port, since we are going to do nothing with it anyway  
			CloseHandle(hPort);  
		}  

		//Add the port number to the array which will be returned  
		if (bSuccess)  
			ports.push_back(i);   //所有存在的串口  
	}  
}  


unsigned long  SplitStr2Bin(const unsigned char* data ,int  bit_idx ,int len)
{
	boost:: dynamic_bitset<> bits(len) ;
	 
	for(int i=0,idx=bit_idx ;i<len ; i++,idx++)
	{
		bits[len-i-1] = (data[idx/8]>>(7-idx%8))&0x01 ; 
	}
	 return bits.to_ulong() ;
}

double GPS_DM_2_DOT(int flag , unsigned long   F , unsigned long  B) 
{
	int Z  = int(F/100);
	char buf[48];
	sprintf_s(buf , 48, "%d.%d" , F%100 , B) ;
	double min = atof(buf);
	double val = Z + min/60.0 ; 
	return flag?(val):(-1.0*val) ; 
}