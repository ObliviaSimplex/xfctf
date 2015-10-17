#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char **argv){
  char filename[0x40] = "zero.txt";
  char password[7] = "secret";
  char buffer[7];
  char command[0x40] = "cat ";
  
  int i=0;
  printf("ENTER PASSWORD: ");
  do (scanf("%c",&(buffer[i++])));
  while (buffer[i-1] != '\n');
    ;
  buffer[i-1] = '\0';
  printf("%s",buffer);
  if (!strcmp(buffer,password)){
    printf("\nOpening %s\n",filename);
    strcat(command,filename);
    system(command);
  } else {
    printf("\nWRONG PASSWORD\n",buffer,password);
  }
}


