#include "tunalloc.h"

int main (int argc, char** argv){
  int fd = createInterface(argc, argv);

  int pidServer = fork();

  printf("Interface crée, descripteur : %d\n", fd);
  pthread_create(&serverThread, NULL, extout, (void *)&serverThread);

  // If can read datas (tun0)

  // Look socket

  // extout();
  extin(fd);
  
  printf("ZBOUB\n");
  getchar();
  return 0;
}
