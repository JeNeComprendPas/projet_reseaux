#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h> 
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>

void writeSrcInDst(int src, int dst) {
  char buf[2000];
  int nbytes;

  nbytes = read(src, buf, sizeof(buf));
  if(nbytes > 0) {
    write(dst, buf, sizeof(buf));
    
    // printf("\n\n Read %d bytes \n\n", nbytes);
  }
}