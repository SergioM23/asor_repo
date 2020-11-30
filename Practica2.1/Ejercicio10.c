#include <string.h>
#include <stdio.h>
#include <pwd.h>

int main(){
  struct passwd *pwd;

 pwd = getpwuid(getuid());
  printf("UID: %d\n", getuid());
  printf("EUID: %d\n", geteuid());
  printf("Username: %s\n", pwd->pw_name);
  printf("Home: %s\n", pwd->pw_dir);
  printf("User info: %s\n", pwd->pw_gecos);


  if(getuid() != geteuid()){
    printf("Bit setuid activado\n");
  }
  else{
    printf("Bit setuid desactivado\n");
  }

  return 1;
}
