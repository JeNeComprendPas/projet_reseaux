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

void main(int argc, char** argv) {
    if(argc < 2) return;

    
}

void test_iftun(int src, int dst) {
  ssize_t r = read(src);
  
}
