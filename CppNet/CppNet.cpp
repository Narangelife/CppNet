// CppNet.cpp : アプリケーションのエントリ ポイントを定義します。
//
#include "CppNet.h"

using namespace std;
#pragma comment(lib, "ws2_32.lib")

int main()
{
	cout << "Hello CMake." << endl;

	WSADATA wsaData;
	SOCKET sockListen;
	WSAStartup(WINSOCK_VERSION, &wsaData);

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(25500);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	sockListen = socket(addr.sin_family, SOCK_STREAM, 0);

	if (sockListen == INVALID_SOCKET) {
		cout << "socket failed" << endl;
		return -1;
	}

	if (bind(sockListen, (struct sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		cout << "bind Error" << endl;
	}

	if (listen(sockListen, 5) == SOCKET_ERROR) {
		cout << "listen Error" << endl;
	}

	SOCKET sock;
	struct sockaddr_in client;
	int clientlen = sizeof(client);
	char buf[256];
	memset(buf, 0, sizeof(buf));

	sock = accept(sockListen, (struct sockaddr*)&client, &clientlen);
	cout << "Connected" << endl;

	while (true) {
		recv(sock, buf, sizeof(buf), 0);
		cout << buf << endl;
		if (buf == "END") break;
	}

	closesocket(sock);
	WSACleanup();

	return 0;
}
