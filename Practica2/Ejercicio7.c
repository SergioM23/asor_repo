#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
 
 mode_t prev = umask(027);

 int fd = open("/home/cursoredes/Documents/Practica2/ficheroEj7", O_RDWR | O_CREAT | O_TRUNC, 0777);

 mode_t last = umask(prev);

 printf("Mask: %i\n", last);

 return 1;
}
