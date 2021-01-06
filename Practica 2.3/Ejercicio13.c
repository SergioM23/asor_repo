#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile int stop = 0;

void counter(int senial){
  if(senial = SIGUSR1) stop = 1;
}

int main(int argc, char **argv){

  if(argc < 2){
     printf("ERROR: escribe los segundos\n");
     return -1;
  }
  
  struct sigaction act;
  
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGUSR1);

  sigprocmask(SIG_UNBLOCK, &mask, NULL);

  sigaction(SIGUSR1, NULL, &act);
  act.sa_handler = counter;
  sigaction(SIGUSR1, &act, NULL);

  sleep(atoi(argv[1]));

  if(stop == 1){
     printf("STOPPED\n");
  }
  else{
     printf("BORRADO\n");
     unlink(argv[0]);
  }

  return 0;
}
