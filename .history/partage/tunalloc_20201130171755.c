#include "tunalloc.h"

int main (int argc, char** argv){
  int fd = createInterface(argc, argv);
  printf("Interface crée, descripteur : %d\n", fd);
  pthread_create(&serverThread, NULL, extout, (void *)&serverThread);

  int pidServer = fork();
  srand(pidServer);
  if(pidServer < 0) { perror("Fork"); exit(0); }
  else if (pidServer) {
    extout();
  }
  else {
    //extin(fd);
  }
  getchar();
  return 0;
}
