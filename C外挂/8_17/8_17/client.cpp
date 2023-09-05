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
//客户端：连接到服务器
SOCKET connectToHost(const char* ip, UINT16 port)
{
	//1.创建一个socket
	//param1 af 指定地址协议族 IPv4 IPv6 AF_INET AF_INET6
	//param2 type 传输类型 流TCP 数据报UDP SOCK_STREAM SOCK_DGRAM 
	//param3 protocol 协议： TCP UDP

	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("Socket Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
	//2.连接到服务器(IP地址 port端口号)
	//IP地址：在网络表示唯一台主机       192，168，0，1 [0 到 255]
	//port端口号：在主机中表示唯一应用程序 uint16[0 到 65535]
	SOCKADDR_IN addr = { 0 };//
	addr.sin_family = AF_INET; //必须和socket传递的协议族一样
	addr.sin_port = htons(port);//[0 到 1024] 是保留端口号(知名端口号)
	addr.sin_addr.S_un.S_addr = inet_addr(ip);

	int size = sizeof addr;
	if (connect(sock, (struct sockaddr*)&addr, size) != 0)
	{
		printf("Connect Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
	return sock;
}


//获取系统时间
const char* getLocalTime()
{
	static char buf[BUFSIZ] = { 0 };
	time_t t_ = time(NULL);
	tm* tm_ = localtime(&t_);
	sprintf(buf, "%d-%d-%d %d:%d:%d\n", tm_->tm_year, tm_->tm_mon, tm_->tm_mday, tm_->tm_hour, tm_->tm_min, tm_->tm_sec);
	return buf;
}
using namespace std;
int main()
{

	init_socket();
	SOCKET sock = connectToHost("127.0.0.1", 8080);
	//接受数据
	char buf[1024];
	int len = recv(sock, buf, 1024, 0);
	if (len > 0)//正常接收数据
	{
		printf("now time:%s\n", buf);
		closesocket(sock);
	}
	else if (len == 0) //正常关闭了链接
	{
		printf("normal close\n");
		closesocket(sock);
	}
	else//len <0 //发生了错误
	{
		printf("Recv Error:%d\n", WSAGetLastError());
	}
	clean_socket();
	return 0;
}