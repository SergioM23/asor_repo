#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(){
  char *path = "/home";
  printf("%d\n", pathconf(path, _PC_LINK_MAX));
  printf("%d\n", pathconf(path, _PC_PATH_MAX));
  printf("%d\n", pathconf(path, _PC_NAME_MAX));

  return 1;
}
