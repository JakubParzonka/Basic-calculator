/*
 * Functions.c
 *
 *  Created on: Nov 20, 2016
 *      Author: parzon
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void send_data(int socket_fd, unsigned char buffor[]) {
	int x = write(socket_fd, buffor, 3);
	if (x < 0) {
		printf("Error while sending");
	} else {
		printf("x: %d\n", x);
	}
}

int receive_data(int socket_fd) {
	char sendBuff[4];
	int n = read(socket_fd, sendBuff, sizeof(sendBuff));
	if (n < 0) {
		printf("Error while reading");
	}
	if (n < 0) {
		printf("\n Read error \n");
	}

	return sendBuff[0] & 0xFF;
}
