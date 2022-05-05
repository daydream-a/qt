#include "mod_send.h"
#pragma comment(lib, "ws2_32.lib")

char* mod_send(char* frame, int len, int r_w)
{
	//加载套接字
	WSADATA wsaData;
	char buff[1024];
	memset(buff, 0, sizeof(buff));

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("Failed to load Winsock");
	}

	sockaddr_in addrServer;
	inet_pton(AF_INET, "127.0.0.1", &addrServer.sin_addr);
	addrServer.sin_port = htons(502);
	addrServer.sin_family = AF_INET;

	//创建套接字
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == sockClient) {
		printf("Socket() error:%d", WSAGetLastError());
	}

	//向服务器发出连接请求
	if (connect(sockClient, (struct  sockaddr*)&addrServer, sizeof(addrServer)) == INVALID_SOCKET) {
		//printf("Connect failed:%d\n", WSAGetLastError());
		return 0;
	}
	else
	{
		for (int i = 0; i < len; i++) {
			send(sockClient, frame + i, 1, 0);
		}
		if (r_w == 1) {
			recv(sockClient, buff, sizeof(buff), 0);
		}
		else {
			return frame;
		}
	}

	//发送数据

	//关闭套接字
	closesocket(sockClient);
	WSACleanup();
	return buff;
}