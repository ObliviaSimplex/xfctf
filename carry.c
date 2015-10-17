#include <string.h>
#include <stdio.h>

char *key="\x7f\x7b\x49\x3d\x33\x3d\x31\x4f\x39\x2d\x4a\x2c\x2b\x7e\x3a\x28\x52\x3e\x61\x3a\x3c\x49\x20\x38\x6e\x75\x6c\x30\x24\x3f\x48";

int main(int argc, char **argv){
  printf("THE FATE OF THE PLANET MAY HANG IN THE BALANCE!\n>>");
  char decoder[30];
  int i;
  while ((decoder[i++] = getchar()) != '\n');

  for (i = 0; i < strlen(key); i++)
    printf("%c",decoder[i] ^ key[i]);
  printf("\n");
  return 0;
}
