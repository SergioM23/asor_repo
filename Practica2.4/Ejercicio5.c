#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){

  char buf[257];

  int tub1 = open("/HOME/tuberia", O_RDONLY);
  int tub2 = open("/HOME/tuberia2", O_RDONLY);

  int seleccion = 0, tubactual;
  
  while(seleccion != -1){
    fd_set conjunto;
    FD_ZERO(&conjunto);
    FD_SET(tub1, &conjunto);
    FD_SET(tub2, &conjunto);
    int numtubactual;
    seleccion = select((tub1 < tub2) ? tub2 + 1 : tub1 + 1, &conjunto, NULL, NULL, NULL);

    if(seleccion > 0){
      if(FD_ISSET(tub1, &conjunto)){
        numtubactual = 1;
        tubactual = tub1;
      }
      else if(FD_ISSET(tub2, &conjunto)){
       	numtubactual = 2;
       	tubactual = tub2;
      }

      ssize_t readsize = 256;    
      while(readsize == 256){
        readsize = read(tubactual, buf, 256);
        buf[readsize] = '\0';
        printf("Tuberia %i: %s", numtubactual, buf);
      }
      if(readsize != 256 && numtubactual == 1){
        close(tub1);
        tub1 = open("/HOME/tuberia", O_RDONLY);
      }
      else if(readsize != 256 && numtubactual == 2){
        close(tub1);
       	tub2 = open("/HOME/tuberia2", O_RDONLY);
      }
    }
  }
  close(tub1);
  close(tub2);

  return 0;
}
