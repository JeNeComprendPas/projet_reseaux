#ifndef IFTUN_H
#define IFTUN_H

int tun_alloc(char *dev);
void writeSrcInDst(int src, int dst);
void createInterface(char ** argv);

#endif