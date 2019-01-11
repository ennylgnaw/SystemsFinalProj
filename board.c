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
  int numofbombs = 99;
  srand(time(NULL));
  while(numofbombs){
    for(int r = 0; r < SIDE; r++)
      for(int c = 0; c < SIDE; c++)
	if (rand()%17 == 1 && strcmp(b[r][c], "_") == 0) {
	  b[r][c] = "*";
	  numofbombs -= 1;
        }
  }
}

char countbombs(char * b[][SIDE],int row,int col){
  int counter = 0;
  char n = b[row - 1][col];
  if(strcmp(n, "*") == 0){
    counter += 1;
  }
  char s = b[row + 1][col];
  if(strcmp(s, "*") == 0){
    counter += 1;
  }
  char e = b[row][col-1];
  if(strcmp(e, "*") == 0){
    counter += 1;
  }
  char w = b[row][col + 1];
  if(strcmp(w, "*") == 0){
    counter += 1;
  }
  char ne = b[row - 1][col - 1];
  if(strcmp(ne, "*") == 0){
    counter += 1;
  }
  char nw = b[row - 1][col + 1];
  if(strcmp(nw, "*") == 0){
    counter += 1;
  }

  char se = b[row + 1][ col - 1];
  if(strcmp(se, "*") == 0){
    counter += 1;
  }
  char sw = b[row + 1][col + 1];
  if(strcmp(sw, "*") == 0){
    counter += 1;
  }
  return (char) counter;

}

void generateboard(char *b[][SIDE]) {
  for(int r = 0; r < SIDE; r++)
    for(int c = 0; c < SIDE; c++)
      if (strcmp(b[r][c], "*") != 0)
	b[r][c] = countbombs(b, r, c);
}

void printboard(char *b[][SIDE]) {
  int r, c;
  printf("    ");
  for(int r = 0; r < SIDE; r++)
    printf("%d ", r);
  printf("\n\n");
  for(int r = 0; r < SIDE; r++) {
    printf("%d ", r);
    for(c = 0; c < SIDE; c++)
      printf("%s ", b[r][c]);
    printf("\n");
  }
}


main(){
  char * aboard[24][24];
  generatebombs(aboard);
  generateboard(aboard);
  printboard(aboard);
  return 0;
}
