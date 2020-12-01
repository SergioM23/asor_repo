#include <time.h>
#include <stdio.h>

int main(){

  const time_t t = time(NULL);
  struct tm *lt = localtime(&t);

  printf("%i, ", 1900+lt->tm_year);
  
  char buf[100];
  strftime(buf, 100, "%A %d %B, %R", lt);
  printf("%s\n", buf);

  return 1;
}
