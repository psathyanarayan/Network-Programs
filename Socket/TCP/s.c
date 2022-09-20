#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int serversock,clientsock;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t len;
	int message;
	
	serversock = socket(AF_INET,SOCK_STREAM,0);
	bzero((char *)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	
	bind(serversock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	bzero((char *)&clientaddr, sizeof(clientaddr));
	len = sizeof(clientaddr);
	
	listen(serversock,5);
	
	clientsock = accept(serversock,(struct sockaddr*)&clientaddr,&len);
	read(clientsock,(int *)&message,sizeof(message));
	printf("%d",message);
	write(clientsock,"MESSAGE RECEIVED",sizeof("MESSAGE RECEIVED"));
	
}