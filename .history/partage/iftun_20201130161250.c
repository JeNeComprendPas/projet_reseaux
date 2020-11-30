#include "iftun.h"

// Tun allocation
int tun_alloc(char *dev) {
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


// Ecrire le contenu d'une source dans une destination
void writeSrcInDst(int src, int dst) {
    char buf[2000];
    int nbytes;

    nbytes = read(src, buf, sizeof(buf));
    printf("%d ",nbytes);
    if(nbytes > 0) {
        write(dst, buf, sizeof(buf));
    }
}

// Création d'une interface et configuration
int createInterface(int argc, char ** argv) {
    if(argc < 2) {
        printf("Erreur argument\n");
        exit(0);
    }
    
    int tunfd;
    tunfd = tun_alloc(argv[1]);

    if(tunfd < 0) {
        printf("Erreur tunfd : %d\n", tunfd);
        exit(1);
    }
    system("bash /vagrant/files/configure-tun.sh");

    return tunfd;
}
