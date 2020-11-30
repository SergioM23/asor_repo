#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(){
  if(setuid(2) == -1){ 
    perror("Error: ");
    int error = errno;
    printf("error: %d", error);
  }
  else{
    printf("Todo ok\n");
  }

return 1;

}
