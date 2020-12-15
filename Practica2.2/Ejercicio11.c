#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv){

 if(argc < 2){
   printf("Especifica la ruta del archivo");
   return -1;
 }

 struct stat buff;
 int st = stat(argv[1], &buff);

 char* hard = malloc(sizeof(char)*(5 + strlen(argv[1])));
 char* sym = malloc(sizeof(char)*(5 + strlen(argv[1])));
 strcpy(hard, argv[1]);
 strcpy(sym, argv[1]);
 hard = strcat(hard, ".hard");
 sym = strcat(sym, ".sym");

 printf("Hard: %s\n", hard);
 printf("SYm: %s\n", sym);

 mode_t mode = buff.st_mode;

 if(S_ISREG(mode)){
   printf("%s es un archivo ordinario.\n", argv[1]);
   
   if(link(argv[1], hard) == -1){
     printf("ERROR al crear el enlace rigido");
   }
   else {
     printf("Enlace rigido creado\n");
   }
   if(symlink(argv[1], sym) == -1){
     printf("ERROR al crear el enlace simbolico");
   }
    else {
     printf("Enlace simbolico creado\n");
   }

 }
 else{
   printf("ERROR: la ruta no es un archivo ordinario\n");
 }


 return 1;
}
