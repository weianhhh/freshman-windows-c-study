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
//�ͻ��ˣ����ӵ�������
SOCKET connectToHost(const char* ip, UINT16 port)
{
	//1.����һ��socket
	//param1 af ָ����ַЭ���� IPv4 IPv6 AF_INET AF_INET6
	//param2 type �������� ��TCP ���ݱ�UDP SOCK_STREAM SOCK_DGRAM 
	//param3 protocol Э�飺 TCP UDP

	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("Socket Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
	//2.���ӵ�������(IP��ַ port�˿ں�)
	//IP��ַ���������ʾΨһ̨����       192��168��0��1 [0 �� 255]
	//port�˿ںţ��������б�ʾΨһӦ�ó��� uint16[0 �� 65535]
	SOCKADDR_IN addr = { 0 };//
	addr.sin_family = AF_INET; //�����socket���ݵ�Э����һ��
	addr.sin_port = htons(port);//[0 �� 1024] �Ǳ����˿ں�(֪���˿ں�)
	addr.sin_addr.S_un.S_addr = inet_addr(ip);

	int size = sizeof addr;
	if (connect(sock, (struct sockaddr*)&addr, size) != 0)
	{
		printf("Connect Failed:%d\n", WSAGetLastError());
		return INVALID_SOCKET;
	}
	return sock;
}


//��ȡϵͳʱ��
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
	//��������
	char buf[1024];
	int len = recv(sock, buf, 1024, 0);
	if (len > 0)//������������
	{
		printf("now time:%s\n", buf);
		closesocket(sock);
	}
	else if (len == 0) //�����ر�������
	{
		printf("normal close\n");
		closesocket(sock);
	}
	else//len <0 //�����˴���
	{
		printf("Recv Error:%d\n", WSAGetLastError());
	}
	clean_socket();
	return 0;
}