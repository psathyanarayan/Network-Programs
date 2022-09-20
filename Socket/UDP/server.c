#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
int main(int argc, char *argv[]) {
	int serversock;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t len;
	char message[50];
	
	serversock = socket(AF_INET,SOCK_DGRAM,0);
	bzero((char *)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	
	bind(serversock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	bzero((char *)&clientaddr,sizeof(clientaddr));
	len = sizeof(clientaddr);
	
	recvfrom(serversock,message,sizeof(message),0,(struct sockaddr*)&clientaddr,&len);
	printf("%s",message);
	sendto(serversock,"DONE",sizeof("DONE"),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
	close(serversock);
	
}