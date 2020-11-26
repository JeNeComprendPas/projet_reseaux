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

void test_iftun(int src, int dst) {
    int fd = open("/dev/net/tun", O_RDWR);

    char c;

    while(read(fd, &c, 1) <= 0) {
        printf("zbeub");
        
    }

    read(fd, &c, 1);
    printf("%c", c);
  
}

void main(int argc, char** argv) {
    if(argc < 2) return;
    printf("ici");
    test_iftun(1, 1);
}


