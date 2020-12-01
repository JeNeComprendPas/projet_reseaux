#include "tunnel64d.h"

int main (int argc, char** argv){
  char * 



  int fd = createInterface(argc, argv);
  printf("Interface crée, descripteur : %d\n", fd);

  int pid = fork();
  srand(pid);
  if(pid < 0) { perror("Fork"); exit(0); }
  else if (pid) {
    extout(fd);
  }
  else {
    extin(fd, argv[2]);
  }
  getchar();
  return 0;
}
