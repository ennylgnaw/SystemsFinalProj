#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#ifndef NETWORKING_H
#define NETWORKING_H

#define SIDE 16
#define BUFFER_SIZE 256
#define PORT "10002"
#define TEST_IP "127.0.0.1"

void error_check(int i, char *s);
int server_setup();
int server_connect(int sd);
int client_setup(char * server);

void generatebombs(char *b[][SIDE]);
void generateboard(char *b[][SIDE]);
void printboard( char * b[][SIDE]);
void addbombcount(char *b[][SIDE]);
int checkscores(char *ansboard[][SIDE],char *userboard[][SIDE], int row, int col);


#endif
