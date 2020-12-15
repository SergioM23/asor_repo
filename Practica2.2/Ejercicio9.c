#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/sysmacros.h>

int main(){
 struct stat buff;

 int st = stat("/home/cursoredes/Documents/Practica2/ficheroEj5", &buff);

 printf("Major: %li\n", major(buff.st_dev));
printf("Minor: %li\n", minor(buff.st_dev));
printf("I-nodo:%i\n", buff.st_ino);
printf("Tipo: %i\n", buff.st_mode);

//con atime
time_t t = buff.st_atime;
struct tm *tm1 = localtime(&t);
printf("Ultimo acceso (A): %d:%d\n", tm1->tm_hour, tm1->tm_min);

//con mtime
time_t t2 = buff.st_mtime;
struct tm *tm2 = localtime(&t2);
printf("Ultimo acceso (M): %d:%d\n", tm2->tm_hour, tm2->tm_min);

//con ctime
time_t t3 = buff.st_ctime;
struct tm *tm3 = localtime(&t3);
printf("Ultimo acceso (C): %d:%d\n", tm3->tm_hour, tm3->tm_min);

 return 1;
}
