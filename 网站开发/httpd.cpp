#pragma warning(distable:4996) 
#define _CRT_NONSTDC_NO_DEPRECATE 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <WinSock2.h>
#pragma comment(lib,"WS2_32.lib")


#define PRINTF(str) printf("[%s - %d]"#str"=%s\n", __func__, __LINE__, buff)
void error_die(const char* str) {
	perror(str);
	exit(1);
}
int startup(unsigned short* port) {
	WSADATA data;
	int ret = WSAStartup(MAKEWORD(1,1),&data);
	if (ret) { /*return -1;*/error_die("WSAStartup"); }
	int server_socket = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (server_socket == -1) { error_die("套接字"); }
	int opt = 1;
	setsockopt(server_socket,SOL_SOCKET,SO_REUSEADDR,(const char*)&opt, sizeof(opt));
	if (ret == -1) { error_die("setsockopt"); }
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(*port);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);


	if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		error_die("bind");
	}
	int nameLen = sizeof(server_addr);
	if (*port == 0) {
		if (getsockname(server_socket, (struct sockaddr*)&server_addr, &nameLen) < 0) { 
			error_die("getsockname"); 
		}
		*port = server_addr.sin_port;
	}

	if(listen(server_socket,5) < 0)
	{
		error_die("error_die");
	}
	return server_socket;
}
int get_line(int sock, char* buff, int size){
	char c = 0;
	int i = 0;


	while (i < size - 1 && c != '\n') {
		int n = recv(sock, &c, 1, 0);
		if (n > 0) {
			if (c == '\r') {
				n = recv(sock, &c, 1, MSG_PEEK);
				if (n > 0 && c == '\n') {
					recv(sock,&c,1,0);
				}
				else {
					c == '\n';
				}
			}
			buff[i++] = c;
		}
		else {
			c = '\n';
		}
	}
	buff[i] = 0;
	return i;
}
void unimplement(int client) {

}
void not_found(int client) {

}
void headers(int client) {
	char buff[1024];

	strcpy(buff,"HTTP/1.0 200 Ok\r\n");
	send(client,buff,strlen(buff),0);
	strcpy(buff,"Server:hrhhttpd0.1\r\n");
	send(client, buff, strlen(buff), 0);
	strcpy(buff,"Content-type:text/html\n");
	send(client, buff, strlen(buff), 0);
	strcpy(buff,"\r\n");
	send(client, buff, strlen(buff), 0);
}
void cat(int client, FILE* resource) {
	char buff[4096];
	int count = 0;
	while (1)
	{
		int ret = fread(buff, sizeof(char), 1, resource);
	
		if (ret <= 0) {
			break;
		}
		send(client,buff,ret,0);
		count += ret;
	}
	printf("一共发送了[%d]字节给浏览器\n",count);
}
void server_file(int client, const char* fileName) {
	char numchars = 1;
	char buff[1024];
	while (numchars > 0 && strcmp(buff, "\n")) {
			numchars = get_line(client, buff, sizeof(buff));
			PRINTF(buff);
	}

	FILE* resource = fopen(fileName, "r");
	if (resource == NULL) {
		not_found(client);
	}
	else {
		headers(client);
		cat(client,resource);
		printf("资源发送完毕！\n");
	}
	fclose(resource);
}
DWORD WINAPI accept_request(LPVOID arg) {
	char buff[1024];
	int client = (SOCKET)arg;
	int numchars = get_line(client,buff,sizeof(buff));
	PRINTF(buf);
	char method[255]; int i=0, j=0;
	while( !isspace(buff[j]) && i < sizeof(method)-1)
	{
		method[i++] = buff[j++];
	}
	method[i] = 0;
	PRINTF(method);

	if (stricmp(method, "GET") && stricmp(method, "POST")) {
		unimplement(client);

		return 0;
	}

	char url[255];
	i = 0;
	while (isspace(buff[j]) && j < sizeof(buff))
	{
		j++;
	}
	while (!isspace(buff[j]) && i < sizeof(url) - 1 && j < sizeof(buff)) {
		url[i++] = buff[j++];
	}
	url[i] = 0;
	PRINTF(url);
	char path[512];
	sprintf(path,"htdocs%s", url);
	if (path[strlen(path) - 1] == '/') {
		strcat(path, "index.html");
	}
	PRINTF(path);
	struct stat status;
	if (stat(path, &status) == -1) {
		while (numchars > 0 && strcmp(buff, "\n")) {
			numchars = get_line(client, buff, sizeof(buff));
		}

			not_found(client);

	}
	else {
		if ((status.st_mode & S_IFMT) == S_IFDIR) {
			strcat(path,"/index.html");
		}
		server_file(client,path);
	}
	closesocket(client);
	return 0; 
}
int main()
{
	unsigned short port = 80;
	int server_sock = startup(&port);
	printf("httpd服务已经启动，正在监听%d端口。。。",port);
	struct sockaddr_in client_addr;
	int client_addr_len = sizeof(client_addr);
	while (true)
	{
		int client_sock = accept(server_sock,(struct sockaddr*)&client_addr,&client_addr_len);
		if (client_sock == -1) { error_die("accept"); }
		DWORD threadId = 0;
		CreateThread(0,0,accept_request,(void*)client_sock,0,&threadId);
	}
	closesocket(server_sock);
	system("pause");
	return 0;
}