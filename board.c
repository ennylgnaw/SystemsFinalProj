#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <errno.h>


#define SIDE 24
#define BOMB 99


void generatebombs(char * b[][SIDE]) {
  int x = 0;
  int num;
  srand(time(NULL));
  while(rand()%17

	}
