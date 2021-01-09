#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv){
  
  if(argc < 2){
    printf("ERROR: argumentos incorrectos \n");
    return -1;
  }
  
  char *HOME = getenv("HOME");
  char *tub = strcat(HOME, "/tuberia2");
  //creo la tuberia con todos los permisos para luego abrirla con otros 
  //distintos y comprobar que eso esta bien
  printf("HOME: %s\n", tub);
  mkfifo(tub, 0777);
  
  int fd = open(tub, O_WRONLY);
  ssize_t arglen = strlen(argv[1]);
  write(fd, argv[1], arglen);

  close(fd);
  //para leer el mensaje se hace un cat de la tuberia en otra terminal
  return 0;
}
