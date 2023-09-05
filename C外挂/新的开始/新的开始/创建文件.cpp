#include <windows.h>
#include <string>
#pragma warning(disable:4996)
int main()
{
	wchar_t Path[255];
	wchar_t FileName[255];
	char Data[512] = "_______________by认真的雪________________\n \
		________________________http://www.baidu.com_______________\n";
	for (int i = 0; i < 10; i++) {
		GetWindowsDirectory(Path, sizeof(Path));//LPWSTR  UINT
		wsprintf(FileName,L"\\%d.txt",i);
	
		strcat((char*)Path, (char*)FileName);
		HANDLE hFile;
		hFile = CreateFile(Path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);
		//INVALID_HANDLE_VALUE若前面得到了一个句柄，则应关闭掉,
		//INVALID_HANDLE_VALUE表示无效句柄值，如果句柄不存在，IsOpen（）调用就会报错 
		if (hFile == INVALID_HANDLE_VALUE)
		{
			continue;
		}
		//unsigned long DWORD
		//unsigned char BYTE
		//unsigned short WORD
		DWORD dwWrite;
		WriteFile(  hFile,//句柄
					&Data,//指向包含要写入文件或设备的数据的缓冲区的指针。
					sizeof(Data),//要写入文件或设备的字节数。
					&dwWrite,//指向使用同步 hFile 参数时写入的字节数的变量的指针
					NULL//如果使用 FILE_FLAG_OVERLAPPED打开 hFile 参数，
						//则需要指向 OVERLAPPED 结构的指针，
						//否则此参数可以为 NULL
			);
		CloseHandle(hFile);
		memset(Path, 0x00, 255);
		memset(FileName,0x00,255);
	}
	return 0;
}