#include <stdio.h>
#include <sys/utsname.h>

int main(){
  struct utsname unameData; 
  uname(&unameData);

  printf("system name = %s\n", unameData.sysname); 
  printf("node name = %s\n", unameData.nodename);
  printf("release = %s\n", unameData.release);
  printf("version = %s\n", unameData.version);
  printf("machine = %s\n", unameData.machine);
  #ifdef _GNU_SOURCE
   printf("domainname = %s\n", unameData.domainname);
  #endif

  return 1;
}
