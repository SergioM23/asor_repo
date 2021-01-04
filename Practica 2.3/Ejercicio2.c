#include <stdlib.h>
#include <stdio.h>
#include <sched.h>


int main(){

  struct sched_param p;
  int uid = 1827;

  int n = sched_getscheduler(uid);
  if(n == SCHED_OTHER)
    printf("SCHED_OTHER\n");
  else if(n == SCHED_FIFO)
    printf("SCHED_FIFO\n");
  else if(n == SCHED_RR)
    printf("SCHED_RR\n");

  sched_getparam(uid, &p);
  printf("Prioridad: %i\n", p.sched_priority);

  int max = sched_get_priority_max(n);
  int min = sched_get_priority_min(n);
  printf("Prioridad max: %i\n", max);
  printf("Prioridad min: %i\n", min);

  return 0;
}
