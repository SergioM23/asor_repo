#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>

int main(){

  printf("PID: %i\n", getpid());
  printf("PPID: %i\n", getppid());
  printf("PGID: %i\n", getpgid(getpid()));
  printf("SID: %i\n", getsid(getpid()));

  struct rlimit lim;
  getrlimit(RLIMIT_NOFILE, &lim);
  printf("Limite de ficheros: %li\n", lim.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1)); 
  char *path2 = getcwd(path, 4096 + 1);
  printf("Path: %s\n", path);
  free (path);
  return 0;
}
