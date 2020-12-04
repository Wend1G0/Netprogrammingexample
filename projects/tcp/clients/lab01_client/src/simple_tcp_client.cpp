#include "simple_tcp_client.h"
void exit_handler();
SOCKET client_socket;
int main(int argc, char* argv[])
{
    atexit(common_exit_handler);
    atexit(exit_handler);
	short port;
	char host[128] = "";
	int argc2 = 5;
	char* argv2[argc2];
	argv2[0] = argv[0];
	argv2[1] = argv[1];
	argv2[2] = argv[2];
	argv2[3] = "-p";
	for(int i = 5550;i<10000;i++){
		printf("Connection to the server :%d\n", i);
		char char_arr [100];
		sprintf(char_arr, "%d", i);
		argv2[4] = char_arr;
		bool parse_cmd_result = parse_cmd(argc2, argv2, host, &port);
    	common_init_handler();
		client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		struct sockaddr_in server_addr;
		init_inet_address(&server_addr, host, port);
		//Connect to the server
		if (!connect(client_socket, (sockaddr*)&server_addr, sizeof(sockaddr))) {
			printf("Connection to the server %s:%d success\n", host, port);
		}

		close_socket(client_socket);

	
	}
	return 0;
}

void exit_handler()
{
	close_socket(client_socket);
}
