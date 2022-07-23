#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main()
{
   char *ip = "127.0.0.1";
   int port = 4000;
   int sockfd = socket(AF_INET,SOCK_DGRAM,0);
   char bf[1024];
   socklen_t len;
   struct sockaddr_in addr;
   int n;

   if(sockfd<0){
    perror("[-]Socket Error");
    exit(1);
   }

   addr.sin_family = AF_INET;
   addr.sin_port = htons(port);
   addr.sin_addr.s_addr = inet_addr(ip);

   bzero(bf,1024);
   strcpy(bf,"Hello World");
   sendto(sockfd,bf,1024,0,(struct sockaddr*)&addr,sizeof(addr));
   printf("[+]Data send: %s\n", bf);



}