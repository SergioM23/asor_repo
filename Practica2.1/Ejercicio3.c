#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int main(){
int i;
 for(i = 0; i < 255; i++){
  printf("Error: %s\n", strerror(i)); 
 }
 return 1;
}
