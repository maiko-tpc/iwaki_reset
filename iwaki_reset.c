#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc, char * argv[]){

  int sockfd ;
  int len ;
  struct sockaddr_in address ;
  int result ;
  int data_length;
  char data[256];

  bzero((char*)&address, sizeof(address));
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  address.sin_family = AF_INET ;
  address.sin_addr.s_addr =inet_addr("172.16.213.19"); // OKTAVIAN
  //address.sin_addr.s_addr =inet_addr("172.16.205.94"); // RCNP
  address.sin_port =htons(12289);
  len = sizeof(address);

  /* connect to PLC */
  result = connect(sockfd, (struct sockaddr*)&address, len);

  if ( result == -1 ) {
    perror("oops: client");
    return 0;
  }

  /* turn off the power modules */
  printf("Turn off the power modules...\n");
  send(sockfd, "01BWRI00333,001,1\r\n", 256, 0);
  data_length=recv(sockfd, &data, 256, 0);

  /* wait 5 seconds */
  sleep(5);

  /* turn on the power modules */
  printf("Turn on the power modules...\n");
  send(sockfd, "01BWRI00333,001,0\r\n", 256, 0);
  data_length=recv(sockfd, &data, 256, 0);
  
  printf("Done.\n");

  /* close the connection */
  close(sockfd);

  return 0;
}
