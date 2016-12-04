#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include "functions.h"

int main(int argc, char *argv[]) {
	int sockfd = 0;
	char recvBuff[16];
	struct sockaddr_in serv_addr;

	int (*receving)(int);
	receving = receive_data;

	if (argc != 5) {
		puts(
				"\n Usage: <ip of server>  <first number>  <second number>  <operation symbol:\n1. Add    2. Substract    3. Multiply    4. Divide\n >  \n");
		return 1;
	}

	memset(recvBuff, '0', sizeof(recvBuff));
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Error : Could not create socket \n");
		return 1;
	}

	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);

	if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
		printf("\n inet_pton error occured\n");
		return 1;
	}

	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))
			< 0) {
		printf("\nError : Connect Failed \n");
		fprintf(stderr, "connect() failed: %s\n", strerror(errno));
		return 1;
	}
	/********************************************************/
	unsigned char buffer[3];
	int result, a, b, c;

	a = atoi(argv[2]);
	b = atoi(argv[3]);
	c = atoi(argv[4]);

	buffer[0] = a & 0xFF;
	buffer[1] = b & 0xFF;
	buffer[2] = c & 0xFF;
	send_data(sockfd, buffer);
	/********************************************************/
	result = receving(sockfd);
	printf("Result: %d\n\n", result);

	if (fputs(recvBuff, stdout) == EOF) {
		printf("\n Error : Fputs error\n");
	}

	close(sockfd);
	return 0;
}
