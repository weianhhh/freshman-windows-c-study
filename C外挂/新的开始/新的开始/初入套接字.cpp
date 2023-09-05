/*
���� �� int WSAStartup(
WORD wVersionRequested,//wVersionRequested ��������ָ����Ҫ���� WINSOCK ��İ汾
LPWSADATA lpWSAData);// lpWSAData ����ָ��һ��LPWSADATA �ṹ���ָ��,��������WSAStartup����
						���ص�WinSock�İ汾��Ϣ
�˺������óɹ�����0,ʧ�ܿɵ���WSAGetLastError ����ȷ��ԭ��,
װ��WinSock ��Ĵ�������:
*/
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <windows.h>
#include <cstdio>



int main()
{
	WSAData wsaData;
	WORD sockVersion = MAKEWORD(2, 2);
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}
	/*
	SOCKET socket{
	int af, //af ��������ָ���׽��ֵ�ʹ�õĵ�ַ��ʽ,����ֻ����AF_INET ==>ipv4 .
	int type.//Type ��������ָ���׽��ֵ�����.������������:
				SOCK_STREAM: ==>TCP	
				SOCK_DGRAM: ==> UDP
				SOCK_RAW: ==>ԭʼ�׽���
	int protocol // protocol�����typeʹ�õ�TCP ==>IPPROTO_TCP
											UDP ==>IPPROTO_UDP
		};				
		//���������óɹ�ʱ����һ���µ�SOCKET���,ʧ���򷵻�INVALID_SOCKET
	}
	*/
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET) {
		printf("socket error.\n");
		return 0;
	}
	/*
	int bind{
	SOCKET s, //s������ָ��һ����Ч���׽��־��,��socket��������.
	const struct sockaddr FAR *addr,// ADDR ����ָ��Ҫ�����ı��ص�ַ,������һ��sockaddr�ṹ,
									�˽ṹ��������:
									struct sockaddr_in{
									short int sin_family; //sin_family ���������ΪAF_INET.
									unsigned short int sin_port;//sin_port ��ָ����TCP��UDPͨ�ŷ���Ķ˿ں�
									struct in_addr sin_addr;//sin_addr�������洢32λIP��ַ,
									������ṹ�а�����һ������S_un��������һ��u_long����S_addr����
													�洢32λ�Ķ�����������ʾ��IP��ַ,����inet_addr()
													��һ��С�����10����ipת32λ������
									//inet_ntoa()��inet_addr���溯��,��һ��32λ�Ķ�����תС�����10����
									

									unsigned char sin_zero[8];//sin_zero��û�б�ʹ�á�
									}
	int namelen //NameLEN ����ָ��һ��sockaddr�ṹ�Ĵ�С,����sizeof()ȡ�á�
	};
	//�������óɹ�ʱ����0,����ʧ��ʱ����SOCKET_ERROR. ��������󶨱���ip�ľ������:
	*/
	sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(4500);//htons������������unsigned short int ת����network�ֽ�˳��
	sockaddr.sin_addr.S_un.S_addr = INADDR_ANY; //INADDR_ANY ��ʾ���п��õ�ַ
	if (bind(sock, (LPSOCKADDR)&sockaddr, sizeof(sockaddr)) == SOCKET_ERROR)
	{
		printf("bind error \n");
		return 0;
	}
	/*
	��һ�����Ǽ���
	int listen(SOCKET s,int Backlog);//�������óɹ�ʱ����0�����򷵻�SOCKET_ERROR
	TCP���;�Ҫ����listen 
	UDP�Ͳ���
	*/
	if (listen(sock, 5) == SOCKET_ERROR) {
		printf("listen error \n");
	}
	/*
	SOCKET accpet{
	SOCKET s, //�׽��־��
	struct sockaddr* addr,//addr����ָ��һ��sockaddr�ṹָ��,������ſͻ��˵ĵ�ַ��Ϣ
	int* addrlen //addrlen����ָ��һ��sockaddr�ṹ���ָ��,sizeofȡ��
	};//���ú�������mode�¾�һֱ�ȴ�,ֱ�������ӲŻ�����ִ��,ͨ�����Ϳ��������ܺͷ��ͣ�
	*/

	//recv and send
	/*
		int recv(SOCKET s,char FAR *buf,int len,int flags);
		int send(SOCKET s,char FAR *buf,int len,int flags);
	
	*/

	return 0;
}
