/*
 * functions.h
 *
 *  Created on: Nov 20, 2016
 *      Author: parzon
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int operation_result(char buff[]);
char* receive_data(int socket_fd, char buffor[]);
void send_data(int socket_fd, char buffor[]);

#endif /* FUNCTIONS_H_ */
