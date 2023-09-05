#pragma warning(disable:4996)
#include <windows.h>
#include <stdio.h>
#define MAX_PATH 256
void HideFile(char* fileName, char* bmpFIleName);
void recoverFile(char* fileName, char* bmpFileName);
void recoverFile(char* fileName, DWORD* bmpFileName);
char* getFileContent(char* fileName, DWORD* fileSize);
void saveFile(char* fpBmp,DWORD bmpFileSize,char* bmpFileName);
int main()
{
	char fileName[MAX_PATH];
	char bmpFileName[MAX_PATH];
	int n;
	while (1) {
		printf("����(1) or �ָ�(2):");
		scanf("%d",&n);
		if (1 == n) {
			printf("������Ҫ���ص��ļ���:");
			scanf("%s",bmpFileName);
			printf("please for hide bmpfileName:");
			HideFile(fileName, bmpFileName);
			DeleteFileA(fileName);
		}
		else if (2 == n) {
			printf("������Ҫ�ָ����ļ���:");
			scanf("%s",fileName);
			recoverFile(fileName,bmpFileName);
		}
	}
	return 0;
}
void HideFile(char* fileName, char* bmpFileName) {
	//1.��ȡ�����ļ��Ĵ�С������
	DWORD fileSize;
	DWORD bmpFileSize;
	
	char* fpFile;
	char* fpBmp;
	fpFile = getFileContent(fileName, &fileSize);
	fpBmp = getFileContent(bmpFileName,&bmpFileSize);

	char* fpCurrentFile = fpFile;
	char* fpCurrentBmp = fpBmp;
	DWORD* pOffBits = (DWORD*)(fpCurrentBmp + 10);
	fpCurrentBmp += ((*pOffBits) +3);
	*((DWORD*)fpCurrentBmp) = fileSize;
	fpCurrentBmp += 6;
	while (1) {
		if (fpCurrentBmp >= (fpBmp + bmpFileSize) ||
			fpCurrentFile >= (fpFile + fileSize))
			break;
	
	}
	//2.��fileName�ļ������� �������ǵĺ͹���������
	//д��3���ֽ�
	*fpCurrentBmp = *fpCurrentFile;
	*(fpCurrentBmp + 1) = *(fpCurrentFile + 1);
	*(fpCurrentBmp + 2) = *(fpCurrentFile + 2);
	//bmp����Ų3�ֽ�
	fpCurrentFile += 3;
	fpCurrentFile += 6;


	saveFile(fpBmp,bmpFileSize,bmpFileName);
	delete[] fpFile;
	delete[] fpBmp;
	return;
void recoverFile(char* fileName, char* bmpFileName) {

}
char* getFileContent(char* fileName, DWORD* fileSize) {
	//1.���ļ�
	HANDLE hFile = CreateFileA(fileName, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL);
	if (INVALID_HANDLE_VALUE == hFile) {
		printf("getFileCOntent ������%s���ļ�ʧ�ܣ�\n",fileName);
		return NULL;
	}
	//2.��ȡ�ļ���С
	DWORD fileSizeHigh;
	DWORD fileSizeLow;
	fileSizeLow = GetFileSize(hFile, &fileSizeHigh);
	*fileSize = fileSizeLow;
	char* fileData  = new char[fileSizeLow];
	//3.��ȡ����
	DWORD readSize;
	ReadFile(hFile, fileData, fileSizeLow, &readSize, NULL);
	if (readSize == fileSizeLow) {
		printf("read Success!");
	}
	else {
		printf("read Failed!");
		delete[] fileData;
		return NULL;
	}
	//�ر��ļ�
	CloseHandle(hFile);
	return 0;
}