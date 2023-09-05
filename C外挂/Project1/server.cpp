#include <winsock2.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#pragma comment(lib,"ws2_32.lib")
//初始化socket库
void init_socket()
{
	//wsa -> windows socket async
	//param1 需要传递请求的socket版本 2.2 WORD |2|2|
	//param2 返回请求的版本信息
	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0) {
		printf("WSAStartup failed:%d\n", WSAGetLastError());
	};
	//printf("%u %u %s %s\n",data.wVersion,data.wHighVersion,data.szDescription,data.szSystemStatus);
}
//清理socket库
void clean_socket()
{
	WSACleanup();
}


//服务端:
SOCKET startServer(UINT16 port)
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("Socket Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
	//绑定IP和端口号
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = ADDR_ANY; //addr_any 代表任意地址，绑定本地所有网卡的地址
	if (bind(sock, (struct sockaddr*)&addr, sizeof addr) != 0)
	{
		printf("Bind Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	};
	//3.监听
	if (listen(sock, SOMAXCONN) != 0)
	{
		printf("Listen Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
}

//获取系统时间
const char* getLocalTime()
{
	static char buf[BUFSIZ] = { 0 };
	time_t t_ = time(NULL);
	struct tm* tm_ = localtime(&t_);
	sprintf(buf, "%d-%d-%d %d:%d:%d\n", tm_->tm_year, tm_->tm_mon, tm_->tm_mday, tm_->tm_hour, tm_->tm_min, tm_->tm_sec);
	return buf;
}
using namespace std;
int main()
{

	init_socket();
	//server
	SOCKET sock = startServer(8080);
	//服务器是需要不间断运行的，一直等待客户端的连接的
	while (1)
	{

		//接收客户端的连接
		SOCKET clientSock = accept(sock, NULL, NULL);
		if (clientSock != INVALID_SOCKET)
		{
			const char* time = getLocalTime();
			if (send(clientSock, time, strlen(time), 0) == SOCKET_ERROR)
			{
				printf("send error : % d\n", WSAGetLastError());
			}
			closesocket(clientSock);
		}

	}

	clean_socket();
	return 0;
}