#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
  time_t t;
  t = time(NULL);

  printf("%i\n", t);

  return 1;
}
