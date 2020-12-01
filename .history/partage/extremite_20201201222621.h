#ifndef EXTREMITE_H
#define EXTREMITE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "iftun.h"

#define MAXLIGNE 80
#define CIAO "Au revoir ...\n"

void extout(int tun, char * port, char * options);
void extin(int tun, char * hote);

#endif