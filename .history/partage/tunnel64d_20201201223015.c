#include "tunnel64d.h"

int main (int argc, char** argv){
  char * name;
  char * inip; 
  char * inport;
  char * options;
  char * outip;
  char * outport;
  loadConfiguration(name, inip, inport, options, outip, outport);

  int fd = createInterface(name);
  printf("Interface crée, descripteur : %d\n", fd);
getchar();
  int pid = fork();
  srand(pid);
  if(pid < 0) { perror("Fork"); exit(0); }
  else if (pid) {
    
    extout(fd, inport, options);
  }
  else {
    extin(fd, outip, outport);
  }

  getchar();
  return 0;
}
