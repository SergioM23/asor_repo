#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
  
  if(argc < 2){
     printf("ERROR: argumentos incorrectos\n");
     return 0;   
  }
  
  execvp(argv[1], argv + 1);

  printf("El comando terminó de ejecutarse\n");

  return 0;
}
