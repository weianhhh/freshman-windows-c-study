/*
首先 是 int WSAStartup(
WORD wVersionRequested,//wVersionRequested 参数用来指定想要加载 WINSOCK 库的版本
LPWSADATA lpWSAData);// lpWSAData 参数指向一个LPWSADATA 结构体的指针,用来保存WSAStartup函数
						返回的WinSock的版本信息
此函数调用成功返回0,失败可调用WSAGetLastError 函数确定原因,
装载WinSock 库的代码如下:
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
	int af, //af 参数用来指定套接字的使用的地址格式,这里只能用AF_INET ==>ipv4 .
	int type.//Type 参数用来指定套接字的类型.具体类型如下:
				SOCK_STREAM: ==>TCP	
				SOCK_DGRAM: ==> UDP
				SOCK_RAW: ==>原始套接字
	int protocol // protocol是配合type使用的TCP ==>IPPROTO_TCP
											UDP ==>IPPROTO_UDP
		};				
		//当函数调用成功时返回一个新的SOCKET句柄,失败则返回INVALID_SOCKET
	}
	*/
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET) {
		printf("socket error.\n");
		return 0;
	}
	/*
	int bind{
	SOCKET s, //s参数是指向一个有效的套接字句柄,由socket函数返回.
	const struct sockaddr FAR *addr,// ADDR 参数指向要关联的本地地址,这里是一个sockaddr结构,
									此结构具体如下:
									struct sockaddr_in{
									short int sin_family; //sin_family 域必须设置为AF_INET.
									unsigned short int sin_port;//sin_port 域指定了TCP或UDP通信服务的端口号
									struct in_addr sin_addr;//sin_addr域用来存储32位IP地址,
									在这个结构中包含了一个联合S_un联合中有一个u_long类型S_addr用来
													存储32位的二进制数所表示的IP地址,可用inet_addr()
													将一个小数点的10进制ip转32位二进制
									//inet_ntoa()是inet_addr的逆函数,将一个32位的二进制转小数点的10进制
									

									unsigned char sin_zero[8];//sin_zero域还没有被使用。
									}
	int namelen //NameLEN 参数指向一个sockaddr结构的大小,可由sizeof()取得。
	};
	//函数调用成功时返回0,调用失败时返回SOCKET_ERROR. 下面给出绑定本地ip的具体代码:
	*/
	sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(4500);//htons函数将主机的unsigned short int 转换成network字节顺序
	sockaddr.sin_addr.S_un.S_addr = INADDR_ANY; //INADDR_ANY 表示所有可用地址
	if (bind(sock, (LPSOCKADDR)&sockaddr, sizeof(sockaddr)) == SOCKET_ERROR)
	{
		printf("bind error \n");
		return 0;
	}
	/*
	下一步就是监听
	int listen(SOCKET s,int Backlog);//函数调用成功时返回0，否则返回SOCKET_ERROR
	TCP类型就要调用listen 
	UDP就不用
	*/
	if (listen(sock, 5) == SOCKET_ERROR) {
		printf("listen error \n");
	}
	/*
	SOCKET accpet{
	SOCKET s, //套接字句柄
	struct sockaddr* addr,//addr参数指向一个sockaddr结构指针,用来存放客户端的地址信息
	int* addrlen //addrlen参数指向一个sockaddr结构体的指针,sizeof取得
	};//调用后在阻塞mode下就一直等待,直到有连接才会往下执行,通过它就可以来接受和发送：
	*/

	//recv and send
	/*
		int recv(SOCKET s,char FAR *buf,int len,int flags);
		int send(SOCKET s,char FAR *buf,int len,int flags);
	
	*/

	return 0;
}
