#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

 int fd = open("/home/cursoredes/Documents/Practica2/ficheroEj5", O_RDWR | O_CREAT | O_TRUNC, 00646);

 return 1;
}
