#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
  char canary1[6]="tweet!";
  char buffer[0x100]="We want neither virtue nor terror. We want superior forms of corruption.\n";
  strcpy(buffer,argv[1]);
  printf("==> %s\n\n",buffer);
  char canary2[6]="tweet!";
  if (strncmp(canary1,canary2,6)){
    printf("DEAD CANARY!");
    getchar();
    char *X="XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    strcpy(canary1,X);
  } else {
    printf("The canary says: %s\n",canary1);
  }
  return 0;
}
