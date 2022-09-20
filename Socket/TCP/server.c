#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<netdb.h>
int main()
{
        int serversock,clientsock,port;
        struct sockaddr_in serveraddr,clientaddr;
        socklen_t len;
        char message[50];

        serversock = socket(AF_INET,SOCK_STREAM,0);
        bzero((char *)&serveraddr,sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_port = htons(8000);
        serveraddr.sin_addr.s_addr = INADDR_ANY;

        bind(serversock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
        listen(serversock,5);
        bzero((char *)&clientaddr,sizeof(clientaddr));
        len = sizeof(clientaddr);

        clientsock = accept(serversock,(struct sockaddr*)&clientaddr,&len);

        read(clientsock,message,sizeof(message));
        printf("%s",message);

        write(clientsock,"MESSAGE RECEIVED",sizeof("MESSAGE RECEIVED"));

        close(clientsock);
        close(serversock);

}


