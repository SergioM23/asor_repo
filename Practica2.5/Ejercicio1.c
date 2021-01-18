#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv){

  if(argc < 2){
    printf("ERROR: introduce el host\n");
  } 

  struct addrinfo hints;
  struct addrinfo *res, *it;

  memset(&hints, 0, sizeof(struct addrinfo));

  hints.ai_family = AF_UNSPEC;
  hints.ai_flags = AI_PASSIVE;

  int rc = getaddrinfo(argv[1], NULL, &hints, &res);

  if(rc != 0){
    printf("ERROR: getaddrinfo: %s\n", gai_strerror(rc));
  }

  for(it = res; it != NULL; it = it->ai_next){
    char host[NI_MAXHOST];
    getnameinfo(it->ai_addr, it->ai_addrlen, host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
    printf("%i\t%i\t%i\n", host, it->ai_family, it->ai_socktype);
  }

  freeaddrinfo(res);
  return 0;
}
