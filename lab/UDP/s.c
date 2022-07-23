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
    int n;
    struct sockaddr_in server_addr,client_addr;
    int sockfd;
    char bf[1024];
    socklen_t len;

    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = hotons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    
    bzero(bf,1024);
    n = bind(sockfd,(struct sockaddr*)&client_addr,sizeof(client_addr));
    if(n<0)
    {
        perror("[-] Bind Error");
        exit(0);
    }
    recvfrom(sockfd,bf,1024,0,(struct sockadd*)&client_addr,sizeof(client_addr));


}