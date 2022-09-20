#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<netdb.h>
#include<unistd.h>
#include<netinet/in.h>
int main()
{
	int clientsock;
	struct sockaddr_in serveraddr;
	char message[50];
	socklen_t len;
	
	clientsock = socket(AF_INET,SOCK_DGRAM,0);
	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	len = sizeof(serveraddr);
	sendto(clientsock,"THIS IS ROOT",sizeof("THIS IS ROOT"),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	recvfrom(clientsock,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&len);
	printf("%s",message);
	close(clientsock);
}