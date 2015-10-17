#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
  srand(time(NULL));
  printf("Time: %d\n",time(NULL));
  unsigned char K = rand();
  char *filename;
  printf("Enter filename: ");
  scanf("%s",filename);
  int i = 0;
  while (filename[i++] != '\0')
    filename[i-1] ^= K;
  printf("\nI'm sorry, it's terribly noisy in here. Did you say %s?",filename);

  FILE *fd = fopen(filename,"r");
  if (fd == NULL){
    printf("\n%s not found!\n",filename);
    exit(EXIT_FAILURE);
   
  }
  char ch;
  printf("\nOpening %s\n",filename);
  while ((ch = getc(fd)) != EOF)
    printf("%c",ch);
  return 0;  
}
