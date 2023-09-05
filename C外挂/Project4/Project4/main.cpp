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
		printf("隐藏(1) or 恢复(2):");
		scanf("%d",&n);
		if (1 == n) {
			printf("请输入要隐藏的文件名:");
			scanf("%s",bmpFileName);
			printf("please for hide bmpfileName:");
			HideFile(fileName, bmpFileName);
			DeleteFileA(fileName);
		}
		else if (2 == n) {
			printf("请输入要恢复的文件名:");
			scanf("%s",fileName);
			recoverFile(fileName,bmpFileName);
		}
	}
	return 0;
}
void HideFile(char* fileName, char* bmpFileName) {
	//1.获取两个文件的大小和内容
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
	//2.把fileName文件的数据 按照我们的和规则来隐藏
	//写入3个字节
	*fpCurrentBmp = *fpCurrentFile;
	*(fpCurrentBmp + 1) = *(fpCurrentFile + 1);
	*(fpCurrentBmp + 2) = *(fpCurrentFile + 2);
	//bmp往后挪3字节
	fpCurrentFile += 3;
	fpCurrentFile += 6;


	saveFile(fpBmp,bmpFileSize,bmpFileName);
	delete[] fpFile;
	delete[] fpBmp;
	return;
void recoverFile(char* fileName, char* bmpFileName) {

}
char* getFileContent(char* fileName, DWORD* fileSize) {
	//1.打开文件
	HANDLE hFile = CreateFileA(fileName, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL);
	if (INVALID_HANDLE_VALUE == hFile) {
		printf("getFileCOntent 函数中%s打开文件失败！\n",fileName);
		return NULL;
	}
	//2.获取文件大小
	DWORD fileSizeHigh;
	DWORD fileSizeLow;
	fileSizeLow = GetFileSize(hFile, &fileSizeHigh);
	*fileSize = fileSizeLow;
	char* fileData  = new char[fileSizeLow];
	//3.获取内容
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
	//关闭文件
	CloseHandle(hFile);
	return 0;
}