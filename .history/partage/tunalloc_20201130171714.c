#include "tunalloc.h"

int main (int argc, char** argv){
  int fd = createInterface(argc, argv);
  printf("Interface crée, descripteur : %d\n", fd);
  pthread_create(&serverThread, NULL, extout, (void *)&serverThread);

  int pidServer = fork();
  srand(pidServer);
  if(pid < 0) { perror("Fork"); exit(0); }
  else if (pid) {
    
  }

  

  // If can read datas (tun0)

  // Look socket

  // extout();
  extin(fd);
  
  printf("ZBOUB\n");
  getchar();
  return 0;
}
