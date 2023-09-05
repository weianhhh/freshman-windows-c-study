#include <winsock2.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#pragma comment(lib,"ws2_32.lib")
//��ʼ��socket��
void init_socket()
{
	//wsa -> windows socket async
	//param1 ��Ҫ���������socket�汾 2.2 WORD |2|2|
	//param2 ��������İ汾��Ϣ
	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0) {
		printf("WSAStartup failed:%d\n", WSAGetLastError());
	};
	//printf("%u %u %s %s\n",data.wVersion,data.wHighVersion,data.szDescription,data.szSystemStatus);
}
//����socket��
void clean_socket()
{
	WSACleanup();
}


//�����:
SOCKET startServer(UINT16 port)
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("Socket Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
	//��IP�Ͷ˿ں�
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = ADDR_ANY; //addr_any ���������ַ���󶨱������������ĵ�ַ
	if (bind(sock, (struct sockaddr*)&addr, sizeof addr) != 0)
	{
		printf("Bind Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	};
	//3.����
	if (listen(sock, SOMAXCONN) != 0)
	{
		printf("Listen Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
}

//��ȡϵͳʱ��
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
	//����������Ҫ��������еģ�һֱ�ȴ��ͻ��˵����ӵ�
	while (1)
	{

		//���տͻ��˵�����
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