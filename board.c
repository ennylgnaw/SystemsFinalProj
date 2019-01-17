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
#include <time.h>


#define SIDE 24
#define BOMB 99

void generatebombs(char *b[][SIDE]) {
  int numofbombs = 99;
  srand(time(NULL));
  while (numofbombs) {
    int x = rand() % SIDE;
    int y = rand() % SIDE;
    if (strcmp(b[x][y], "_") == 0)
      b[x][y] = "*";
    numofbombs--;
  }
}

int countbombs(char *b[][SIDE],int row,int col){
  int counter = 0;
  if (row != 0) {
    char * n = b[row - 1][col];
    if(strcmp(n, "*") == 0){
      counter += 1;
    }
  }

  if (row != SIDE - 1) {
    char * s = b[row + 1][col];
    if(strcmp(s, "*") == 0){
      counter += 1;
    }
  }

  if (col != 0) {
    char * e = b[row][col-1];
    if(strcmp(e, "*") == 0){
      counter += 1;
    }
  }

  if (col != SIDE - 1) {
    char * w = b[row][col + 1];
    if(strcmp(w, "*") == 0){
      counter += 1;
    }
  }

  if (! (row == 0 || col == 0)) {
    char * ne = b[row - 1][col - 1];
    if(strcmp(ne, "*") == 0){
      counter += 1;
    }
  }

  if (! (row == 0 || col == SIDE - 1)) {
    char * nw = b[row - 1][col + 1];
    if(strcmp(nw, "*") == 0){
      counter += 1;
    }
  }

  if (! (row == SIDE - 1 || col == 0)) {
    char * se = b[row + 1][ col - 1];
    if(strcmp(se, "*") == 0){
      counter += 1;
    }
  }

  if (! (row == SIDE - 1 || col == SIDE - 1)) {
    char * sw = b[row + 1][col + 1];
    if(strcmp(sw, "*") == 0){
      counter += 1;
    }
  }

  return counter;

}

void generateboard(char *b[][SIDE]) {
  for(int r = 0; r < SIDE; r++)
    for(int c = 0; c < SIDE; c++)
      b[r][c] = "_";
}

void addbombcount(char *b[][SIDE]) {
  for(int r = 0; r < SIDE; r++)
    for(int c = 0; c < SIDE; c++)
      if (strcmp(b[r][c], "*") != 0) {
	*b[r][c] = (char) countbombs(b, r, c);
      }
}

void printboard(char *b[][SIDE]) {
  int r, c;
  printf("    ");
  for(c = 0; c < SIDE; c++)
    printf("%-4d", c);
  printf("\n\n");
  for(r = 0; r < SIDE; r++) {
    printf("%-4d", r);
    for(c = 0; c < SIDE; c++)
      printf("%-4s", b[r][c]);
    printf("\n\n");
  }
}


int main(){
  char *aboard[SIDE][SIDE];
  generateboard(aboard);
  generatebombs(aboard);
  printboard(aboard);
  printf("%d\n", countbombs(aboard, 0, 0));
  printf("%d\n", countbombs(aboard, 12, 12));
  addbombcount(aboard);
  /*
    countbombs(aboard, 12, 12);
    generateboard(aboard);
    printboard(aboard);
    return 0;
  */
}
