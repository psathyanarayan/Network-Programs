#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>

int main()
{
    char *ip = '127.0.0.1';
    int port = 4000;
    int sockfd;
    struct sockaddr_in server_addr;
    char bf[1024];
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    bzero(bf,1024);
    strcpy(bf,"Hello World");
    sendto(sockfd,1024,0,(struct sockaddr*)&server_addr,sizeof(server_addr));
    printf("[+]Data send %s",bf);
}