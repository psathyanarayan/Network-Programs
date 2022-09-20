#include <stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/socket.h>
FILE *f1;
int main() {
	int sockserver,sockclient;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t len;
	char t[60],str[60],buff[4096];
	strcpy(t,"exit");
	
	sockserver =socket(AF_INET,SOCK_STREAM,0);
	bzero((char *)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	
	bind(sockserver,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	listen(sockserver,5);
	bzero((char *)&clientaddr,sizeof(clientaddr));
	len = sizeof(clientaddr);
	
	sockclient = accept(sockserver,(struct sockaddr *)&clientaddr,&len);
	read(sockclient,&str,60);
	
	f1 = fopen(str,"r");
	while(fgets(buff,4096,f1)!= NULL)
	{
		write(sockclient,buff,60);
		printf("%s",buff);
	}
	fclose(f1);
	
	
}