#include <time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
 
int main(int argc, char** argv){

 if(argc < 2){
   printf("Especifica la ruta del fichero\n");
 }

 int fd = open(argv[1], O_CREAT | O_RDWR, 00777);

 struct flock lock;

 lock.l_type = F_UNLCK;
 lock.l_whence = SEEK_SET;
 lock.l_start = 0;
 lock.l_len = 0;
 lock.l_pid = getpid();

 int status = fcntl(fd, F_GETLK, &lock);
 
 if(lock.l_type == F_UNLCK){
   printf("STATUS: desbloqueado\n");
   lock.l_type = F_WRLCK;
   lock.l_whence = SEEK_SET;
   lock.l_start = 0;
   lock.l_len = 0;
   lock.l_pid = getpid();
 
 
   if(fcntl(fd, F_GETLK, &lock) == -1){
     printf("ERROR: no se ha cerrado el cerrojo\n");
     close(fd);
     return -1;
   }
   else{
     printf("STATUS: Creado cerrojo de escritura\n");
   }

   time_t t = time(NULL);
   struct tm *tm = localtime(&t);
   char buff[1024];

   printf("Hora: %d:%d\n", tm->tm_hour, tm->tm_min);
   write(fd, &buff, strlen(buff));

   sleep(30);

   lock.l_type = F_WRLCK;
   lock.l_whence = SEEK_SET;
   lock.l_start = 0;
   lock.l_len = 0;
   lock.l_pid = getpid();

   if(fcntl(fd, F_GETLK, &lock) == -1){
     printf("ERROR: no se ha cerrado el cerrojo\n");
     close(fd);
     return 1;
   }else{
     close(fd);
   }

 }else{
   printf("STATUS: cerrojo bloqueado\n");
   close(fd);
   return 1;
 }

 close(fd);
 return 1;
}

