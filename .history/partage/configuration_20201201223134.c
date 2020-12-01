#include "configuration.h"

void loadConfiguration(char * name, 
    char * inip, 
    char * inport,
    char * options,
    char * outip,
    char * outport) {

        FILE * f = fopen("/vagrant/files/configuration.conf", "r");
        fscanf(f, "tun=%s\n", name);
        fscanf(f, "inip=%s\n", inip);
        fscanf(f, "inport=%s\n", inport);
        fscanf(f, "options=%s\n", options);
        fscanf(f, "outip=%s\n", outip);
        getchar();
        fscanf(f, "outport=%s", outport);
        fclose(f);
    }