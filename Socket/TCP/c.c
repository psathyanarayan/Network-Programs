#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
	int clientsock;
	struct sockaddr_in serveraddr;
	socklen_t len;
	char message[50];
	
	clientsock = socket(AF_INET,SOCK_STREAM,0);
	bzero((char *)&serveraddr, sizeof(serveraddr));
	
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	int x = 100;
	connect(clientsock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	send(clientsock,(int *)&x,sizeof(x),0);
	recv(clientsock,message,sizeof(message),0);
	printf("%s",message);
}