#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){

  if(argc < 2){
     printf("ERROR: argumentos incorrectos\n");
     return 0;
  }

  int i;
  char command[255];
  strcpy(command, argv[1]);

 for(i = 2; i < argc; i++){
    strcat(command, " ");
    strcat(command, argv[1]);
 }
  system(command);

  printf("El comando terminó de ejecutarse\n");

  return 0;
}

