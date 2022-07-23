#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
int main()
{
    int socketfd;
    struct sockaddr_in server_addr;
    char bf[1024];
    int port = 4000;
    char *ip = '127.0.0.0.1';
    socketfd = socket(PF_INET,SOCK_STREAM,0);
    memset(socketfd,'\0',sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    connect(socketfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    recv(socketfd,bf,1024,0);
    printf("Data Received: %s",bf);
}
