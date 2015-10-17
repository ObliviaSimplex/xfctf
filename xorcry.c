#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
  if (argc != 4){
    printf("Usage: %s <file name> <key string> <-x or -c>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  /*char *buffer;
  if ((buffer = malloc(0x100000)) == NULL){
    printf("MEMORY FAILURE\n");
    exit(EXIT_FAILURE);
    }*/
  int len = strlen(argv[2]);
  
  FILE *fd = fopen(argv[1],"r");

  char ch;
  int counter = 0;
  char *fmtstr = (!(strcmp(argv[3],"-c")))? "%c" : "\\x%2.2x";
  while ((ch = fgetc(fd)) != EOF){
    printf(fmtstr, (ch ^ argv[2][counter % len]));
    counter ++;
  }
  return 0;
}
