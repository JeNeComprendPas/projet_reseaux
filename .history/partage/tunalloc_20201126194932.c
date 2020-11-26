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


int tun_alloc(char *dev)
{
  struct ifreq ifr;
  int fd, err;

  if( (fd = open("/dev/net/tun", O_RDWR)) < 0 ){
    perror("alloc tun");
    exit(-1);
  }

  memset(&ifr, 0, sizeof(ifr));

  /* Flags: IFF_TUN   - TUN device (no Ethernet headers) 
   *        IFF_TAP   - TAP device  
   *
   *        IFF_NO_PI - Do not provide packet information  
   */ 
  ifr.ifr_flags = IFF_TUN | IFF_NO_PI | IFF_TAP; 
  if( *dev )
    strncpy(ifr.ifr_name, dev, IFNAMSIZ);

  if( (err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0 ){
    close(fd);
    return err;
  }
  strcpy(dev, ifr.ifr_name);
  return fd;
}     

void writeSrcInDst(int src, int dst) {
  char buf[2000];
  int nbytes;

  while(1) {
    nbytes = read(src, buf, sizeof(buf));
    if(nbytes > 0) {
      write(dst, buf, sizeof(buf));
    }
    
    // printf("\n\n Read %d bytes \n\n", nbytes);
  }
}

int main (int argc, char** argv){

  int tunfd;
  printf("Création de %s\n",argv[1]);
  tunfd = tun_alloc(argv[1]);

  if(tunfd < 0) {
    printf("Erreur tunfd : %d\n", tunfd);
    exit(1);
  }

  printf("Configuration de %s en cours...\n",argv[1]);

  system("bash /vagrant/files/configure-tun.sh");

  printf("Interface %s Configurée : %d\n\n",argv[1], tunfd);

  system("ip addr");

  writeSrcInDst(tunfd, 1);

  return 0;
}
