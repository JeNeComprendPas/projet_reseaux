#include "tunalloc.h"

int main (int argc, char** argv){
  int fd = createInterface(argc, argv);
  printf("Interface crée, descripteur : %d\n", fd);
  

  // while(1) {
  //   // If can read datas (tun0)

  //   // Look socket

  // }
  extout();
  extin(fd);
  
  return 0;
}
