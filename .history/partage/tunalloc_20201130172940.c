#include "tunalloc.h"

int main (int argc, char** argv){
  int fd = createInterface(argc, argv);
  printf("Interface crée, descripteur : %d\n", fd);

  int pid = fork();
  srand(pid);
  if(pid < 0) { perror("Fork"); exit(0); }
  else if (pid) {
    extout();
  }
  else {
    // extin(fd);
  }
  getchar();
  return 0;
}
