#include "tunnel64d.h"

int main (int argc, char** argv){
  char name[50];
  char inip[50]; 
  char inport[50];
  char options[50];
  char outip[50];
  char outport[50];

  
  loadConfiguration(name, inip, inport, options, outip, outport);
  
printf("%s\n", name);
  // printf("%s %s %s %s %s\n", name, inip, inport, outip, outport);

  int fd = createInterface(name);
  printf("Interface crée, descripteur : %d\n", fd);
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
