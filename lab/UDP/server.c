#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
     
     char *ip = "127.0.0.1";
     int port = 4000;

     int sockfd;
     struct sockaddr_in server_addr,client_addr;
     char bf[1024];
     socklen_t len;
     int n;  //for binding

     sockfd = socket(AF_INET,SOCK_DGRAM,0); //socket descriptor
     if(sockfd<0)
     {
        perror("[-]socket error");
        exit(1);
     }

     
     server_addr.sin_family =  AF_INET;
     server_addr.sin_port = htons(port);
     server_addr.sin_addr.s_addr = inet_addr(ip);

     n = bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
      if(n<0)
     {
        perror("[-]bind error");
        exit(1);
     }
     bzero(bf,1024);
   len = sizeof(client_addr);
   recvfrom(sockfd,bf,1024,0,(struct sockaddr*)&client_addr,&len);
   printf("[+]Data recv from %s\n",bf);

}
