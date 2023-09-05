#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
int main(void)
{
    //初始化网络
    WSADATA wd;
    WSAStartup(MAKEWORD(2, 2), &wd);
    //create scoket
    SOCKET client = socket(AF_INET, SOCK_STREAM, 0);
    //bind socket set address and port
    SOCKADDR_IN serAddr;
    serAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.4");//字节序转换 主机字节序-> 网络字节序

    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(6666);

    connect(client,(SOCKADDR*)&serAddr,sizeof(SOCKADDR));
    char buf[1024];
    int n = recv(client,buf,sizeof(buf),0);
    if (n > 0) {
        buf[n] = '\0';
        printf("收到命令: %s\n",n, buf);
    }
    
    return 0;
}