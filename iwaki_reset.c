#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char * argv[]){

  int sockfd ;
  int len ;
  int i;
  struct sockaddr_in address ;
  char command[256];
  int result ;
  int result2;
  int data_length;
  char data[256];
  char header[32];
  char buff[256];
  long buff2;
  char *endptr;
  long ADC_val[16];

  float pressure;
  float temp;
  float density;
  float dew;
  float dew_ppm;
  float flow[2];
  int rec_int;

  char *outfile;

  double p_offset;

  bzero((char*)&address, sizeof(address));
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  //  printf("id= %d \n", sockfd);
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

  

  return 0;
}
