#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv){

 if(argc < 2){
   printf("Especifica la ruta del fichero\n");
 }
 
 int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
 int fd2 = dup2(fd, 1);

 printf("Redirección a: %d\n", argv[1]);

 dup2(fd2, fd);

 return -1;
}
