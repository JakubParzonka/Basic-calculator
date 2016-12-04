#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "functions.h"

int main(int argc, char *argv[]) {
	int listenfd = 0, connfd = 0, i, result;
	struct sockaddr_in serv_addr;
	char *p;
	char sendBuff[1], recvBuff[3];

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);

	if (inet_pton(AF_INET, "127.0.0.7", &serv_addr.sin_addr) <= 0) {
		printf("\n inet_pton error occured\n");
		return 1;
	}

	if (bind(listenfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "bind() failed: %s\n", strerror(errno));
	}

	if (listen(listenfd, 10) < 0) {
		fprintf(stderr, "listen() failed: %s\n", strerror(errno));
	}

	while (1) {
		connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
		if (connfd < 0) {
			fprintf(stderr, "accept() failed: %s\n", strerror(errno));
		}

		p = receive_data(connfd, recvBuff);
		for (i = 0; i < sizeof(recvBuff); i++) {
			recvBuff[i] = *(p + i);
			printf("%x", recvBuff[i]);
		}

		result = operation_result(recvBuff);
		printf("\nResult to send is %d\n", result);
		sendBuff[0] = result & 0xFF;

		send_data(connfd, sendBuff);
	}

	close(connfd);
	//close(listenfd);
	sleep(1);
}
