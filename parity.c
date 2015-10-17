#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parity.h"
#include <unistd.h>

int main(int argc, char **argv){
  char *the = "The key you're looking for is ";
  char *kkey = "(Nope, you're not going to find it with a string dump. Nice try, though.)";
  char key[20];
key[8] = 0x34 << 1;
  key[9] = 'q' - 'Q';
  key[10] = 'f' - key[9];
  key[11]= 0x69;
  key[12]= 'r';
  key[13]= 'a'+4;
  key[14]= 'u'-2;
  key[0] = 'A'+0x12;
  key[1] = key[0]+0x15;
  key[2] = (key[1]+0x7)*0+'u';
  key[3] = 0x6c;
  key[4] = 'A'+' ';
  key[5] = key[4] + 0xc;
  key[6] = 'h'+1;
  key[7] = 'r'+2;
  key[15]= key[7];
  key[16]= 0x60 + 0xf;
  key[19]= '\0';
  key[17]= key[16]-1;
  key[18]= key[13];
  int j;
  for (j=0; j<19; j++)
    key[j] -= 2;
  for (j=0; j<19; j++)
    key[j] += argc;
  
  // -- snip! -- //
  printf("YOU ENTERED '"); 
  printf(argv[1]);
  printf("'\n");
  printf("\nDecrypting message with %s as key",argv[1]);
  int len = strlen(key);
  char *userkey = calloc(len,sizeof(char));
  printf("\nHIT <ENTER> TO PROCEED...\n");
  getchar();
  strncpy(userkey,argv[1],len);
  int ulen = strlen(userkey);
  int counter = 0;  
  int txtlen = 4062;
  char ch;
  usleep(5);
  do{
    usleep(0.1);
    ch = (char) *encrypted^(userkey[counter % (ulen)]);
    printf("%c",ch);
    counter ++; encrypted ++;
  } while (counter < txtlen);

  return 0;

}
