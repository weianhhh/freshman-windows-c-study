#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <float.h>
using namespace std;
#include <iostream>
#include <limits>

template<typename T>
void PrintNumericLimits() {
	std::cout << "min = " << (std::numeric_limits<T>::min)() << std::endl;
	std::cout << "max = " << (std::numeric_limits<T>::max)() << std::endl;
}

int main()
{
	CHAR myChar = 'a';                    /*   1个字节, -128到127 或者 0到255*/
	BYTE  myByte = 'b';/*unsigned char*/  /*   1个字节,	               0到255*/  /*UCHAR*/
	signed char myHasChar = 'c';          /*   1个字节  -128到127            */

	//short加不加int都一样！
	short int myShort = '1'; /*SHORT SHORT INT*/       /* 2个字节        -32768 到 32767*/  
	WORD myWord = '0';/*unsigned short int*/           /* 2个字节             0 到 65535*/
	INT32 myHasShort = '1';/*INT16 signed short int*/  /* 2个字节	    -32768 到 32767*/  

	INT myInt = 255;                     /* 4个字节	-2147483648 到 2147483647*/
	UINT myUint = 512;/*unsigned int*/   /* 4个字节	          0 到 4294967295*/
	signed int myHasInt = 1024;          /* 4个字节	-2147483648 到 2147483647*/
	
	FLOAT myFloat = 1;    /* 4个字节	精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字)*/
	
	//加不加int都一样
	LONG myLong = 1;/*LONG*/                       /*8个字节	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807*/
	unsigned long myUlong = 1;/*ULONG*/             /*8个字节	                         0 到 18,446,744,073,709,551,615*/
	signed long myHasLong = 1;/*LONG32*/           /*8个字节	-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807*/
	unsigned long int myDword = 1;/*DWORD*/         /*8个字节                            0 到 18,446,744,073,709,551,615*/
	LONG64 myLlong = 1; /*LONG64 INT64 LONGLONG*/    /*8个字节  -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807*/              
	
	DOUBLE myDouble = 1;	/*8 个字节	双精度型占8 个字节（64位）内存空间， + / -1.7e + / -308 (~15 个数字)*/
	long double  mylongDouble = 1;	/*16个字节	长双精度型 16 个字节（128位）内存空间，可提供18 - 19位有效数字。*/
	//char16_t i = 1;

	BOOL myBOOL = 0;/*BOOL 就是int BOOL就是char16_t*/
	BOOLEAN myBoolean = '0';/*BYTE就是BOOLEAN*/

	bool myBool = TRUE;
	
	WCHAR  myWchar = 1;/*wchar_t(SHORT INT) */   /*wchar_t	2或4个字节	1个宽字符*/
	
	
	
	PrintNumericLimits<int>();
	PrintNumericLimits<float>();
	PrintNumericLimits<double>();
	
	printf("Ushrot=%c,size = % d\n", myLlong,sizeof(myLlong));

	
	return 0;
}
