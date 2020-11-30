#include <stdio.h>
#include <string.h>

int main(){
  
  printf("UID: %d\n", getuid());  
  printf("EUID: %d\n", geteuid()); 
  
  if(getuid() != geteuid()){
    printf("Bit setuid activado\n");
  }
  else{
    printf("Bit setuid desactivado\n");
  }

  return 1;
}
