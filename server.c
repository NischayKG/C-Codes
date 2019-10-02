#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
 int sockfd,bd,x;
 char ch;
 sockfd = socket(AF_INET,SOCK_DGRAM,0);
 struct sockaddr_in server,client;
 server.sin_family=AF_INET;
 server.sin_port=5000;
 server.sin_addr.s_addr=inet_addr("127.0.0.1");
 bd = bind(sockfd, (const struct sockaddr *) &server, sizeof(server));
 if(bd==-1)
  printf("\nError");
 else
  printf("\nSuccess %d",bd);
 client.sin_family=AF_INET;
 client.sin_port=5010;
 client.sin_addr.s_addr=inet_addr("127.0.0.1");

 //printf("\nEnter a string");
 //scanf("%s",buf);
 //sendto(sockfd, buf, strlen(buf), 0, const struct sockaddr *dest_addr. sizeof(server));
 do
 {
  char *buf=(char*)malloc(sizeof(char*));
  recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &client, &x);
  printf("\n%s",buf);
  buf=(char*)malloc(sizeof(char*));
  printf("\nEnter a string to reply to client:");
  scanf("%s",buf);
  sendto(sockfd, buf, strlen(buf), 0, (const struct sockaddr *)&client, sizeof(client));
  printf("\nDo you wish to receive another message?");
  printf("\nPress Y for Yes, N for No:");
  scanf(" %c",&ch);
  free(buf);
 }while(ch=='Y');
}

