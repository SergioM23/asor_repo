#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

  int ph[2];
  if(pipe(ph) == -1){
     printf("ERROR: ph tuberia no creada \n");
     return -1;
  }

  int hp[2];
  if(pipe(hp) == -1){
     printf("ERROR: hp tuberia no creada \n");
     return -1;
  }

  pid_t fd = fork();

  if(fd == 0){ //hijo
    close(ph[1]);
    close(hp[0]);
    char h_msg[256];
    char p_msg[1] = {'1'};

    int i;
    for(i = 0; i < 10; i++){
      int size = read(ph[0], h_msg, 255);
      h_msg[size] = '\0';

      printf("[Hijo] Mensaje recibido: %s", h_msg);
      sleep(1);

      if(i == 9){
        p_msg[0] = 'q';
        write(hp[1], p_msg, 1);
      }
    }
    close(ph[0]);
    close(hp[1]);
  }
  else { //padre
    char p_msg[256];
    char h_msg[1] = {'1'};
    close(ph[0]);
    close(hp[1]);

    while(h_msg[0] != 'q'){
      printf("[Padre] NUevo mensaje: \n");
      int size = read(0, p_msg, 255);
      p_msg[size] = '\0';
    
      write(ph[1], p_msg, size + 1);

      while(h_msg[0] != '1' && h_msg[0] != 'q'){
        read(hp[0], h_msg, 1);
      }
    }
   close(ph[1]);
   close(hp[0]);
    
  }
  return 0;
}

