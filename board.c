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
	//strcpy(b[r][c], (const char *) countbombs(b, r, c));
	if (countbombs(b, r, c) > 0) {
	  int i = countbombs(b, r, c);
	  char * a;
	  //char ch = i + '0';
	  //printf("%c\n", *(&ch));
	  if (i == 1) a = "1";
	  if (i == 2) a = "2";
	  if (i == 3) a = "3";
	  if (i == 4) a = "4";
	  if (i == 5) a = "5";
	  if (i == 6) a = "6";
	  if (i == 7) a = "7";
	  if (i == 8) a = "8";
	  b[r][c] = a;
	}
      }
}

void printboard(char *b[][SIDE]) {
  int r, c;
  printf("\n    ");
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
/*
int userscore = 0;
int checkscores(char *ansboard[][SIDE],char *userboard[][SIDE], int row, int col){
  if (strcmp(userboard[row][col], "_")!= 0){
    printf("NON-VALID USER INPUT. ENTER VALID COORDINATES:\n");
  }
  if (strcmp(ansboard[row][col],"_") == 0){
    userscore += 2;
    //if it's an empty box
    //int directions[8][2] = {{row-1,col},{row+1,col},{row,col-1},{row,col+1},{row-1,col-1},{row-1,col+1},{row+1,col-1},{row+1,col+1}};
    //explore the different directions
    //ADD TO SCORE
    checkscores(ansboard,userboard,row-1,col);
    checkscores(ansboard,userboard,row+1,col);
    checkscores(ansboard,userboard,row,col-1);
    checkscores(ansboard,userboard,row,col+1);
    checkscores(ansboard,userboard,row-1,col-1);
    checkscores(ansboard,userboard,row+1,col+1);
    checkscores(ansboard,userboard,row-1,col+1);
    checkscores(ansboard,userboard,row+1,col-1);
    //recursive function:
    //base case: if there is a BOMB or NUMBER
    return 0;

  }
  else if(strcmp(ansboard[row][col],"*") == 0){
    userscore -= 4;
    userboard[row][col] = "*";
    //SUBTRACT FROM THE USER SCORE!!!!!
    //IMPLEMENT LATER!!!!!
    return 0;
  }
  else{
    //if it's a number
    //ADD TO SCORE
    userscore += 2;
    userboard[row][col] = ansboard[row][col];
    return 0;
    }

}
*/



int main(){
  char *aboard[SIDE][SIDE];
  //char *aboard = malloc(sizeof(char[SIDE][SIDE]));
  generateboard(aboard);
  generatebombs(aboard);
  printboard(aboard);
  printf("%c\n", countbombs(aboard, 0, 0));
  printf("%c\n", countbombs(aboard, 12, 12));
  addbombcount(aboard);
  printboard(aboard);
  /*
    countbombs(aboard, 12, 12);
    generateboard(aboard);
    printboard(aboard);
    return 0;
  */
}
