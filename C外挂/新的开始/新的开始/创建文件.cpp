#include <windows.h>
#include <string>
#pragma warning(disable:4996)
int main()
{
	wchar_t Path[255];
	wchar_t FileName[255];
	char Data[512] = "_______________by�����ѩ________________\n \
		________________________http://www.baidu.com_______________\n";
	for (int i = 0; i < 10; i++) {
		GetWindowsDirectory(Path, sizeof(Path));//LPWSTR  UINT
		wsprintf(FileName,L"\\%d.txt",i);
	
		strcat((char*)Path, (char*)FileName);
		HANDLE hFile;
		hFile = CreateFile(Path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);
		//INVALID_HANDLE_VALUE��ǰ��õ���һ���������Ӧ�رյ�,
		//INVALID_HANDLE_VALUE��ʾ��Ч���ֵ�������������ڣ�IsOpen�������þͻᱨ�� 
		if (hFile == INVALID_HANDLE_VALUE)
		{
			continue;
		}
		//unsigned long DWORD
		//unsigned char BYTE
		//unsigned short WORD
		DWORD dwWrite;
		WriteFile(  hFile,//���
					&Data,//ָ�����Ҫд���ļ����豸�����ݵĻ�������ָ�롣
					sizeof(Data),//Ҫд���ļ����豸���ֽ�����
					&dwWrite,//ָ��ʹ��ͬ�� hFile ����ʱд����ֽ����ı�����ָ��
					NULL//���ʹ�� FILE_FLAG_OVERLAPPED�� hFile ������
						//����Ҫָ�� OVERLAPPED �ṹ��ָ�룬
						//����˲�������Ϊ NULL
			);
		CloseHandle(hFile);
		memset(Path, 0x00, 255);
		memset(FileName,0x00,255);
	}
	return 0;
}