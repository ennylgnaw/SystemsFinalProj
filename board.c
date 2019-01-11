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
	if (rand()%17 == 1 && b[r][c] == "_") {
	  b[r][c] = "*";
	  numofbombs -= 1;
        }
  }
}

int countbombs(char * b[][],int row,int col){
  int counter = 0;
  char n = b[row - 1][col];
  if(n == "*"){
    counter += 1;
  }
  char s = b[row + 1][col];
  if(s == "*"){
    counter += 1;
  }
  char e = b[row][col-1];
  if(e == "*"){
    counter += 1;
  }
  char w = b[row][col + 1];
  if(w == "*"){
    counter += 1;
  }
  char ne = b[row - 1][col - 1];
  if(ne == "*"){
    counter += 1;
  }
  char nw = [row - 1][col + 1];
  if(nw == "*"){
    counter += 1;
  }

  char se = [row + 1][ col - 1];
  if(se == "*"){
    counter += 1;
  }
  char sw = [row + 1][col + 1];
  if(sw == "*"){
    counter += 1;
  }
  return counter;

}




main(){
  char answerboard[24][24];
  return 0;
}
