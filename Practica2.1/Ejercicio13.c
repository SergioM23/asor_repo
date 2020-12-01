#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
int main(){
  
  struct timeval ini, fin;
  int i;
  gettimeofday(&ini, NULL);
  for(i = 0; i < 1000000; i++){}
  gettimeofday(&fin, NULL);
  
  printf("Inicio: %i\n", ini.tv_usec);
  printf("Fin: %i\n", fin.tv_usec);
  printf("Resultado: %i\n", fin.tv_usec - ini.tv_usec);

  return 1;
}
