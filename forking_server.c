#include "networking.h"

void process(char *s);
void subserver(int from_client);

int main() {

  int listen_socket;
  int f;
  listen_socket = server_setup();

  while (1) {

    int client_socket = server_connect(listen_socket);
    f = fork();
    if (f == 0)
      subserver(client_socket);
    else
      close(client_socket);
  }
}

void subserver(int client_socket) {
  char buffer[BUFFER_SIZE];

  while (read(client_socket, buffer, sizeof(buffer))) {

    printf("[subserver %d] received: [%s]\n", getpid(), buffer);
    process(buffer);
    printf("Buffer is: %s\n", buffer);
    write(client_socket, buffer, sizeof(buffer));
  }//end read loop
  close(client_socket);
  exit(0);
}

void process(char * s) {
  char * retVal;
  int ctr, total;
  retVal = strtok(s, " .,'*!@$%^&()_+-");

  char foo[100];
  ctr = 0;
  while (retVal != NULL) {
    int i = atoi(retVal);
    if ( i > 0 ) {
      //printf("Value was %d\n", i);
      foo[ctr] = i;
      ctr++;
    }
    retVal = strtok(NULL, " ./'");
    
  }
  printf("Total numbers: %d\n", ctr);

  printf("[ ");
  for (total = 0; total < ctr; total++) {
    printf("%d ", foo[total]);
  }
  printf("]\n");

  while (*s) {
    for (int j = 0; j < ctr; j++) {
      //printf("Adding %d \n", foo[j]);
      sprintf(s, "%d ", foo[j]);
    }
    s++;
  }

  s = foo;
  printf("%s\n", s);
}
