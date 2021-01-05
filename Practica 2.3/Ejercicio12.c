#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile int int_count = 0;
volatile int tstp_count = 0;

void counter(int senial){
  if(senial = SIGINT) int_count++;
}

void counter2(int senial){
  if(senial = SIGTSTP) tstp_count++;
}

int main(){

  struct sigaction act;

  sigaction(SIGINT, NULL, &act);
  act.sa_handler = counter;
  sigaction(SIGINT, &act, NULL);

  sigaction(SIGTSTP, NULL, &act);
  act.sa_handler = counter2;
  sigaction(SIGTSTP, &act, NULL);

  sigset_t mask;
  sigemptyset(&mask);
 
  while(int_count + tstp_count < 10)
     sigsuspend(&mask);

  printf("SIGINT total: %i\n", int_count);
  printf("SIGTSTP total: %i\n", tstp_count);

  return 0;
}
