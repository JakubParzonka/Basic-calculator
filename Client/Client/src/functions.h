/*
 * Functions.h
 *
 *  Created on: Nov 20, 2016
 *      Author: parzon
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void send_data(int socket_fd, unsigned char buffor[]);
int receive_data(int socket_fd);

#endif /* FUNCTIONS_H_ */
