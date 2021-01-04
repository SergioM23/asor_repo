#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>

void Atributos(char *t){

  printf("[%s] PID: %i\n", t, getpid());
  printf("[%s] PPID: %i\n", t, getppid());
  printf("[%s] PGID: %i\n", t, getpgid(getpid()));
  printf("[%s] SID: %i\n", t, getsid(getpid()));

  struct rlimit lim;
  getrlimit(RLIMIT_NOFILE, &lim);
  printf("[%s] Limite de ficheros: %li\n", t, lim.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1));
  char *path2 = getcwd(path, 4096 + 1);
  printf("[%s] Path: %s\n", t, path);
  free (path);
}

int main(){

  pid_t pid = fork();

  if(pid == 0){ //hijo
   
     pid_t nsid = setsid();
     chdir("/tmp");
     Atributos("Hijo");
    // sleep(10);
     exit(0);
  }
  else {
     Atributos("Padre");
     int status;
     wait(&status);
  }
  return 0;
}

