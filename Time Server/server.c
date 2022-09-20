#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<time.h>
#include<netdb.h>
int main(int argc, char *argv[]) {
	int serversock,clientsock;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t len;
	char message[50];
	
	time_t currentTime;
	time(&currentTime);
	
	serversock = socket(AF_INET,SOCK_STREAM,0);
	bzero((char *)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	
	bind(serversock,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	bzero((char *)&clientaddr,sizeof(clientaddr));
	len = sizeof(clientaddr);
	
	listen(serversock,5);
	clientsock = accept(serversock,(struct sockaddr*)&clientaddr,&len);
	
	write(clientsock,ctime(&currentTime),30);
	read(clientsock,message,sizeof(message));
	printf("%s",message);
	
}