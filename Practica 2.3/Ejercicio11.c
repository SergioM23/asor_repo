#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGINT);
  sigaddset(&mask, SIGTSTP);

  sigprocmask(SIG_BLOCK, &mask, NULL);

  //char *sleep_secs = getenv("SLEEP_SECS");
  //int secs = atoi(sleep_secs);
  sleep(10);

  sigset_t pending;
  sigpending(&pending);

  if(sigismember(&pending, SIGINT) == 1){
    printf("Se ha recibido la señal SIGINT\n");
    sigdelset(&mask, SIGINT);
  }
  else printf("No se ha recibido la señal SIGINT\n");

  if(sigismember(&pending, SIGTSTP) == 1){
    printf("Se ha recibido la señal SIGTSTP\n");
    sigdelset(&mask, SIGTSTP); 
  }
  else printf("No se ha	recibido la señal SIGTSTP\n");

  sigprocmask(SIG_UNBLOCK, &mask, NULL);

  printf("FIN\n");
  return 0;
}


