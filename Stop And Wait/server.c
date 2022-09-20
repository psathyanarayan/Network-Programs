#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>

typedef struct packet
{
	char data[1024];
}Packet;

typedef struct frame
{
	int frame_kind;
	int seq;
	int ack;
	Packet packet;
}Frame;

int main(int argc, char *argv[]) {
	int serversock,clientsock,frameno=0;
	struct sockaddr_in serveraddr,clientaddr;
	socklen_t len;
	Frame frame_send,frame_recv;
	
	serversock = socket(AF_INET,SOCK_DGRAM,0);
	bzero((char *)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	
	bind(serversock,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	bzero((char *)&clientaddr,sizeof(clientaddr));
	len = sizeof(clientaddr);
	
	while(1)
		{
			int frame_recvLen = recvfrom(serversock,&frame_recv,sizeof(Frame),0,(struct sockaddr *)&clientaddr,&len);
			if (frame_recvLen >0 && frame_recv.frame_kind == 1 && frame_recv.seq == frameno)
				{
					frame_send.frame_kind = 0;
					frame_send.seq = 0;
					frame_send.ack = frame_recv.seq + 1; //next frame
					sendto(serversock,&frame_send,sizeof(frame_send),0,(struct sockaddr*)&clientaddr,len);
					printf("[+]Frame Received");
				}
			else {
				printf("[-]Frame not Received");
			}
			frameno++;

		}
	close(serversock);
	close(clientsock);
}