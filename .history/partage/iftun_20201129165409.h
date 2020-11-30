#ifndef IFTUN_H
#define IFTUN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h> 
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <fcntl.h>


int tun_alloc(char *dev);
void writeSrcInDst(int src, int dst);
int createInterface(int argc, char ** argv);

#endif