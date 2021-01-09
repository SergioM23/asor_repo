#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

  if(argc != 5){
    printf("ERROR: argumentos incorrectos \n");
    return -1;
  }

  int pipefd[2];
  char buf;
  if(pipe(pipefd) == -1){
     printf("ERROR: tuberia no creada \n");
     return -1;
  }

  pid_t fd = fork();

  if(fd == 0){ //hijo
  //aqui ejecutar comando2 argumento2

    close(pipefd[1]);
    dup2(pipefd[0], 0);
    close(pipefd[0]);
    execlp(argv[3], argv[3], argv[4], NULL);
  }
  else { //padre
 //aqui ejecutar comando1 argumento1
    dup2(pipefd[1], 1);
    close(pipefd[0]);    
    close(pipefd[1]);
    execlp(argv[1], argv[1], argv[2], NULL);
  }
  return 0;
}
