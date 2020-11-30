#ifndef TUNALLOC_H
#define TUNALLOC_H

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

#include <pthread.h>

#include "iftun.h"
#include "extremite.h"

int main (int argc, char** argv);

#endif