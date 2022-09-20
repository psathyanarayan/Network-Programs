#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>


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
	int clientsock,frameNo=0,ackRec = 1;
	struct sockaddr_in serveraddr;
	socklen_t len;
	char data[50];
	
	Frame frame_send,frame_recv;
	
	clientsock = socket(AF_INET,SOCK_DGRAM,0);
	bzero((char *)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	len = sizeof(serveraddr);
	
	while(1)
	{
		if (ackRec == 1)
		{
			frame_send.frame_kind = 1;
			frame_send.seq = frameNo;
			frame_send.ack = 0;
			
			strcpy(frame_send.packet.data,"HI");
			sendto(clientsock,&frame_send,sizeof(frame_send),0,(struct sockaddr*)&serveraddr,len);
		}
		int recvSize = recvfrom(clientsock, &frame_recv, sizeof(Frame), 0, (struct sockaddr *)&serveraddr, &len);
		if(recvSize > 0 && frame_recv.seq ==0 && frame_recv.ack == frameNo +1)
		{
			printf("[+]ACK RECEIVED");
			ackRec = 1;
			break;
		}
		else {
			printf("[-]ACK NOT RECEIVED");
			ackRec = 0;
			break;
		}
		frameNo ++;
	}
}