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
  char c;
  ssize_t rsize;

  printf("hey");
  if((rsize = read(src, &c, 1) != -1) {
    printf("ici");
  }
  // while(read(src, &c, 1) > 0) {
  //   printf("hey");
  // }

  // test_iftun(src, dst);
}

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
  ifr.ifr_flags = IFF_TUN; 
  if( *dev )
    strncpy(ifr.ifr_name, dev, IFNAMSIZ);

  if( (err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0 ){
    close(fd);
    return err;
  }
  strcpy(dev, ifr.ifr_name);

  return fd;
}      

int main (int argc, char** argv){

  int tunfd;
  printf("Création de %s\n",argv[1]);
  tunfd = tun_alloc(argv[1]);
  printf("Faire la configuration de %s...\n",argv[1]);

  system("bash /vagrant/configure-tun.sh");

  printf("Interface %s Configurée:\n",argv[1]);
  system("ip addr");

  printf("Appuyez sur une touche pour terminer\n");
  
  test_iftun(tunfd, 1);
  
  getchar();

  return 0;
}

