#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
	int clientsock;
	struct sockaddr_in serveraddr;
	socklen_t len;
	char message[60];
	
	clientsock = socket(AF_INET,SOCK_STREAM,0);
	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	
	connect(clientsock,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	write(clientsock,"demo.txt",60);
	
	while((read(clientsock,message,60))!=0)
	{
		printf("%s",message);
	}
}