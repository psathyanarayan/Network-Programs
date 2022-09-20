#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netdb.h>
#include<unistd.h>

int main()
{
        int clientsock,port;
        struct sockaddr_in serveraddr;
        socklen_t len;
        char message[50];

        clientsock = socket(AF_INET,SOCK_STREAM,0);
        bzero((char *)&serveraddr,sizeof(serveraddr));
        len = sizeof(serveraddr);


        //recv(clientsock,message,sizeof(message),0);
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_port = htons(8000);
        serveraddr.sin_addr.s_addr = INADDR_ANY;

        connect(clientsock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
        recv(clientsock,message,29,0);
        send(clientsock,"Thank you for the time server",sizeof("Thank you for the time server"),0);
printf("%s",message);   
close(clientsock);
}



