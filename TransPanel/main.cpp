#include "stdafx.h"
#include "transpanel.h"
#include <windows.h>
#include <QtGui/QApplication>
#include <string>
#include "utility.h"


int main(int argc, char *argv[])
{
	printf("APP Running ....\r\n");

	 QApplication::setStyle(QStyleFactory::create("CDE"));  
	 QApplication a(argc, argv);
	
	 qRegisterMetaType<std::string>("std::string");

	 QApplication::addLibraryPath("./plugins");
	 QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
	 QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
	 QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));


	TransPanel w;
	w.show();
	return a.exec();
}
