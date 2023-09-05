#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#pragma warning(disable:4996)
#pragma comment(lib, "Ws2_32.lib")
#define PORT 8888

int main()
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM,0);
    if (s == INVALID_SOCKET) {
        printf("Error: failed to create socket.\n");
        return 1;
    }

    struct sockaddr_in sock_addr;
    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = INADDR_ANY;
    sock_addr.sin_port = htons(PORT);

    if (bind(s, (struct sockaddr*)&sock_addr, sizeof(sock_addr)) == SOCKET_ERROR) {
        printf("Error failed to bind socket.\n");
        closesocket(s);
        WSACleanup();
        return -1;
    }

    if (listen(s, 5) == SOCKET_ERROR) {
        printf("Error : failed to listen on socket.\n");
        closesocket(s);
        WSACleanup();
        return -1;
    }

    struct sockaddr_in client;
    int c = sizeof(struct sockaddr_in);
    SOCKET new_socket = accept(s, (struct sockaddr*)&client, &c);
    if (new_socket == INVALID_SOCKET) {
        printf("Error : failed to accept socket.\n");
        closesocket(s);
        WSACleanup();
        return -1;
    }

    char* client_ip = inet_ntoa(client.sin_addr);
    int client_port = ntohs(client.sin_port);

    printf("New connection from %s:%d\n", client_ip, client_port);

    closesocket(s);
    WSACleanup();
    system("pause");
    return 0;
}
