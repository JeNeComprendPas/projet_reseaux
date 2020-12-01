#include "configuration.h"

void loadConfiguration(char * name, 
    char * inip, 
    char * inport,
    char * options,
    char * outip,
    char * outport) {

        FILE * f = fopen("/vagrant/files/configuration.conf", "r");
        fscanf(f, "tun=%s", name);
        fscanf(f, "inip=%s", inip);
        fscanf(f, "inport=%s", inport);
        fscanf(f, "options=%s", options);
        fscanf(f, "outip=%s", outip);
        fscanf(f, "outport=%s", outport);
    }