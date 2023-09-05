
#include <stdio.h>
#include <windows.h>
char* ReadFileContent(char* filename, DWORD filesize)
{
	HANDLE hfile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		printf("打开文件%s失败\n",filename);
		return NULL;
	}
	DWORD dwRead;
	DWORD dwSize = GetFileSize(hfile, &dwRead);
	*filename = dwSize;
	char* buf = new char[dwSize];
	RtlZeroMemory(buf, dwSize);
	ReadFile(hfile,buf,dwSize,&dwRead,0);
	if (dwRead != dwSize) 
	{
		printf("读取文件内容出错\n");
		return NULL;
	}
	CloseHandle(hfile);
	return buf;
}
bool SaveFile(char* filename,char * buf, int len)
{
	HANDLE hfile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CREATE_ALWAYS, 0, 0);
	if (hfile != INVALID_HANDLE_VALUE)
	{
		printf("打开文件%s失败\n", filename);
		return false;
	}
	DWORD dwWrite;
	SetFilePointer(hfile, 0, 0, FILE_BEGIN);
	WriteFile(hfile,buf,len,&dwWrite,0);
	CloseHandle(hfile);
}
bool Hide(char * bmpFileName, char* secretFileName)
{
	DWORD dwBMPSize, dwSecretSize;
	char* pBMP = ReadFileContent(bmpFileName,(DWORD)&dwBMPSize);
	char* pSercretFile = ReadFileContent(secretFileName, (DWORD)&dwSecretSize);
	DWORD* lpFristPointerOffest = (DWORD*)(pBMP + 10);
	printf("第一个像素的偏移地址:%d\n", lpFristPointerOffest);
	char* pCurrentBMP = pBMP + *lpFristPointerOffest;
	char* pCurrentSecret = pSercretFile;
	*(DWORD*)pCurrentBMP = dwSecretSize;
	pCurrentBMP += 6;
	for ( ; pCurrentBMP < (pBMP + dwBMPSize)&& pCurrentSecret <=(pSercretFile + dwSecretSize);pCurrentBMP += 6)
	{
		*pCurrentBMP = *pCurrentSecret;
		*(pCurrentBMP + 1) = *(pCurrentSecret + 1);
		*(pCurrentBMP + 2) = *(pCurrentSecret + 2);
		pCurrentSecret += 3;
	}
	SaveFile(bmpFileName,pBMP,dwBMPSize);
	delete[] pBMP;
	delete[] pSercretFile;
	return true;
}
bool Recovery(char * bmpFileName, char * secretFileName)
{
	DWORD dwBMPSize;
	char* pBMP = ReadFileContent(bmpFileName, (DWORD)&dwBMPSize);
	DWORD* pFristPoint = (DWORD*)(pBMP + 10);
	printf("第一个像素的偏移地址:%d\n", *pFristPoint);
	DWORD dwSercretSize = *(DWORD*)(pBMP + *pFristPoint + 3);
	char* buf = new char[dwSercretSize];
	char* pCurrentBMP = pBMP + *pFristPoint + 6;
	for (int i = 0; pCurrentBMP < pBMP + dwBMPSize;pCurrentBMP += 6)
	{
		buf[i] = *pCurrentBMP;
		buf[i+1] = *(pCurrentBMP + 1);
		buf[i+2] = *(pCurrentBMP + 2);
		i += 3;
	}
	SaveFile(secretFileName,buf,dwBMPSize);
	delete[] pBMP;
	delete[] buf;

	return true;
}
int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("Usage %s Encrypt secret file_name BMP_filename\n",argv[0]);
		printf("Usage %s Decrypt BMP_filename secrret_file_name\n",argv[0]);
		return -1;
	}
	if (strcmp(argv[1], "Encrypt") == 0)
	{
		Hide(argv[2], argv[3]);
	}
	else if (strcmp(argv[1], "Decrypt") == 0)
	{
		Recovery(argv[2], argv[3]);
	}
	else
		printf("Error");
	printf("搞定\n");
	return 0;
}