#include "networking.h"
#include <stdbool.h>

bool gameOver(char * uboard[][SIDE], char * aboard[][SIDE]) {
  int ct = 0;
  for(int r = 0; r < SIDE; r++)
      for(int c = 0; c < SIDE; c++)
	if (strcmp(uboard[r][c], "-") == 0 || strcmp(uboard[r][c], "*") == 0)
	  ct += 1;
  if (ct == 40)
    return true;
  return false;
}

int main(int argc, char **argv) {

  int lives = 3;
  int server_socket;
  char buffer[BUFFER_SIZE];

  if (argc == 2) {
    server_socket = client_setup( argv[1]);
  }
  else {
    server_socket = client_setup( TEST_IP );
  }
 
  char * aboard[SIDE][SIDE];
  char * user[SIDE][SIDE];
  generateboard(aboard);
  generateboard(user);
  generatebombs(aboard);
  while (1) {
    if (lives <= 0) {
      printf("Game Over. Try Again.\n");
      return 0;
    }
    printboard(user);
    addbombcount(aboard);
    //    printboard(aboard);
    printf("enter data: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    write(server_socket, buffer, sizeof(buffer));
    read(server_socket, buffer, sizeof(buffer));
    printf("received: [%d]\n", *(buffer));
    printf("received: [%d]\n", *(buffer+1));

    if (gameOver(user, aboard)) {
      printf("You have finished this board.\n");
      return 0;
    }
    
    int livesold = lives;

    int a = *(buffer) - 1;
    int b = *(buffer + 1) - 1;
    lives += checkscores(aboard, user, a, b);
    if (lives < 0) lives = 0;
    if (lives > 3) lives = livesold;
    printf("Lives Remaining : %d\n", lives);

    //CALL FUNCTION checkscores() here with parameters: ( answerboard, userboard, *(buffer), *(buffer+1) )
    

  }
}
