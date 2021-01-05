#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/time.h>

int main(int argc, char **argv){

  if(argc < 2){
     printf("ERROR: argumentos incorrectos\n");
     return 0;
  }

  pid_t pid = fork();

  if(pid == 0){
     pid_t nsid = setsid();
     chdir("/tmp");
     
     int in = open("/dev/null", O_RDONLY);
     int out = open("/tmp/daemon.out", O_WRONLY | O_CREAT);
     int err = open("/tmp/daemon.err", O_WRONLY | O_CREAT);
     if(in == -1 || out == -1 || err == -1){
       close(in);
       close(out);
       close(err);
       exit(-1);
     }

     int dup_in = dup2(in, 0);
     int dup_out = dup2(out,1);
     int dup_err = dup2(err, 2);
     execvp(argv[1], argv + 1);

     exit(0);
  }
  else{
     int status;
     wait(&status);
     printf("El comando terminó de ejecutarse\n");
  }

  return 0;
}

