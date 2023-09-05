#include <stdio.h>
#include <stdlib.h>
#include <WinSock.h>
#pragma comment(lib,"ws2_32.lib")
int main()
{
	WORD wVersionEequseted;
	wVersionEequseted = MAKEWORD(2, 2);
	WSADATA wsadata;
	DWORD dwError;
	WSAStartup(wVersionEequseted,&wsadata);
	if(dwError != 0)
	{
		return 0;
	}
	if (LOBYTE(wsadata.wVersion) ! = 2 || HIBYTE(wsadata.wVersion) != 2)
	{
		WSACleanup();
		return 0;
	}
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrinfo;
	addrinfo.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrinfo.sin_family = AF_INET;
	addrinfo.sin_port = htons(24567);

	bind(sock,(SOCKADDR*)&addrinfo,sizeof(SOCKADDR));
	listen(sock,5);
	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	while (true)
	{
		printf("====================等待连接======================");
		SOCKET sockconn = accept(sock,(SOCKADDR*)&addrClient,&len);
		char sendBuffer[100] = "";
		sprintf_s(sendBuffer,"欢迎链接服务器，客户端ID：%s",inet_ntoa(addrClient.sin_addr));
		send(sockconn,sendBuffer,strlen(sendBuffer),0);
		DWORD dwFalg = shutdown(sockconn,SD_SEND);
		if(dwFalg == )
	
	}
}