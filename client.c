#include "networking.h"

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];

  if (argc == 2) {
    server_socket = client_setup( argv[1]);
  }
  else {
    server_socket = client_setup( TEST_IP );
  }
 
  char * aboard[SIDE][SIDE];
  generateboard(aboard);
  generatebombs(aboard);
  while (1) {
    printboard(aboard);
    printf("enter data: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    write(server_socket, buffer, sizeof(buffer));
    read(server_socket, buffer, sizeof(buffer));
    printf("received: [%d]\n", *(buffer));
    printf("received: [%d]\n", *(buffer+1));

    //CALL FUNCTION checkscores() here with parameters: ( answerboard, userboard, *(buffer), *(buffer+1) )


  }
}
