#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int operation_result(char buff[]) {
	int first_number = buff[0] & 0xFF;
	int second_number = buff[1] & 0xFF;
	int operation = buff[2] & 0xFF;
	printf("Received numbers: %d, %d, %d", first_number, second_number,
			operation);
	if (operation == 1) {
		printf("\nReceived operation is addition");
		return first_number + second_number;
	} else if (operation == 2) {
		printf("\nReceived operation is subtraction");
		return first_number - second_number;
	} else if (operation == 3) {
		printf("\nReceived operation is multiplication");
		return first_number * second_number;
	} else if (operation == 4) {
		printf("\nReceived operation is division");
		return first_number / second_number;
	} else {
		return 0;
	}
}

char* receive_data(int socket_fd, char buffor[]) {

	int n = read(socket_fd, buffor, sizeof(buffor));
	if (n < 0) {
		fprintf(stderr, "%d read() failed: %s\n", n, strerror(errno));
	} else {
		printf("Message received correctly\n");
	}
	return buffor;
}

void send_data(int socket_fd, char buffor[]) {

	int n = write(socket_fd, buffor, 1);
	if (n < 0) {
		fprintf(stderr, "write() failed: %s\n", strerror(errno));
	} else {
		printf("Message send correctly\n");
	}

	if (n == -1) {
		printf("Error read");
		exit(1);
	}
}

