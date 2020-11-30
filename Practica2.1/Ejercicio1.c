#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  if(setuid(2) == -1){
    perror("Error: ");
  }
  else{
   printf("Todo ok\n");
  }

return 1;

}
