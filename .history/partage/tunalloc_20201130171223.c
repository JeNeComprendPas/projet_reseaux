#include "tunalloc.h"

int main (int argc, char** argv){
  int fd = createInterface(argc, argv);

  pthread_t serverThread;

  printf("Interface crée, descripteur : %d\n", fd);
  pthread_create(&serverThread, NULL, extout, (void *)&tid);

  // If can read datas (tun0)

  // Look socket

  // extout();
  extin(fd);
  
  return 0;
}
