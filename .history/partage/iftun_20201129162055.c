void writeSrcInDst(int src, int dst) {
  char buf[2000];
  int nbytes;

  nbytes = read(src, buf, sizeof(buf));
  if(nbytes > 0) {
    write(dst, buf, sizeof(buf));
    
    // printf("\n\n Read %d bytes \n\n", nbytes);
  }
}