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
	CHAR myChar = 'a';                    /*   1���ֽ�, -128��127 ���� 0��255*/
	BYTE  myByte = 'b';/*unsigned char*/  /*   1���ֽ�,	               0��255*/  /*UCHAR*/
	signed char myHasChar = 'c';          /*   1���ֽ�  -128��127            */

	//short�Ӳ���int��һ����
	short int myShort = '1'; /*SHORT SHORT INT*/       /* 2���ֽ�        -32768 �� 32767*/  
	WORD myWord = '0';/*unsigned short int*/           /* 2���ֽ�             0 �� 65535*/
	INT32 myHasShort = '1';/*INT16 signed short int*/  /* 2���ֽ�	    -32768 �� 32767*/  

	INT myInt = 255;                     /* 4���ֽ�	-2147483648 �� 2147483647*/
	UINT myUint = 512;/*unsigned int*/   /* 4���ֽ�	          0 �� 4294967295*/
	signed int myHasInt = 1024;          /* 4���ֽ�	-2147483648 �� 2147483647*/
	
	FLOAT myFloat = 1;    /* 4���ֽ�	������ռ4���ֽڣ�32λ���ڴ�ռ䣬+/- 3.4e +/- 38 (~7 ������)*/
	
	//�Ӳ���int��һ��
	LONG myLong = 1;/*LONG*/                       /*8���ֽ�	-9,223,372,036,854,775,808 �� 9,223,372,036,854,775,807*/
	unsigned long myUlong = 1;/*ULONG*/             /*8���ֽ�	                         0 �� 18,446,744,073,709,551,615*/
	signed long myHasLong = 1;/*LONG32*/           /*8���ֽ�	-9,223,372,036,854,775,808 �� 9,223,372,036,854,775,807*/
	unsigned long int myDword = 1;/*DWORD*/         /*8���ֽ�                            0 �� 18,446,744,073,709,551,615*/
	LONG64 myLlong = 1; /*LONG64 INT64 LONGLONG*/    /*8���ֽ�  -9,223,372,036,854,775,808 �� 9,223,372,036,854,775,807*/              
	
	DOUBLE myDouble = 1;	/*8 ���ֽ�	˫������ռ8 ���ֽڣ�64λ���ڴ�ռ䣬 + / -1.7e + / -308 (~15 ������)*/
	long double  mylongDouble = 1;	/*16���ֽ�	��˫������ 16 ���ֽڣ�128λ���ڴ�ռ䣬���ṩ18 - 19λ��Ч���֡�*/
	//char16_t i = 1;

	BOOL myBOOL = 0;/*BOOL ����int BOOL����char16_t*/
	BOOLEAN myBoolean = '0';/*BYTE����BOOLEAN*/

	bool myBool = TRUE;
	
	WCHAR  myWchar = 1;/*wchar_t(SHORT INT) */   /*wchar_t	2��4���ֽ�	1�����ַ�*/
	
	
	
	PrintNumericLimits<int>();
	PrintNumericLimits<float>();
	PrintNumericLimits<double>();
	
	printf("Ushrot=%c,size = % d\n", myLlong,sizeof(myLlong));

	
	return 0;
}
