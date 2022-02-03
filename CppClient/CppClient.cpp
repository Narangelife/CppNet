#include "CppClient.h"

using namespace std;
#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSADATA wsaData;
	WSAStartup(WINSOCK_VERSION, &wsaData);
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		cout << "Error socket" << endl;
		exit(1);
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(25500);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));

	while (true) {
		char s_str[] = "";
		cin >> s_str;
		send(sockfd, s_str, 12, 0);
		cout << "Send: " << s_str << endl;
		if (s_str == "END") break;
	}

	closesocket(sockfd);

	return 0;
}