#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>

int main()
{
    int port = 4000;
    char *ip = '127.0.0.1';
    int sockfd;
    char bf[1024];
    struct sockaddr_in server_addr;
    sockfd = socket(PF_INET,SOCK_STREAM,0);
    memset(sockfd,'\0',sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    recv(sockfd,bf,1024,0);
    printf("[+] Data Received");

}