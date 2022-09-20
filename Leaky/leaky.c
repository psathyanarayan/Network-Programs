#include <stdio.h>
int front = -1,rear = -1, q[100],outRate,bucketSize,n,packSize,store=0;

void enqueue(int x)
{
	if(front == -1)
		front++;
	rear++;
	q[rear] = x;
}

int dequeue()
{
	int del = q[front];
	if(rear == front)
		front = rear = -1;
	else
		front++;
	return del;
		
}

void empty()
{
	int outgoing = 0,x;
	while(outgoing < outRate && store>0)
	{
		x = dequeue();
		outgoing+=x;
		store-=x;
	}
	printf("%d OUT OF %d LEFT IN BUCKET\n\n", bucketSize - store, bucketSize);
}

int main() {
	
	int i,outgoing = 0,x;
	printf("Enter the bucket Size");
	scanf("%d",&bucketSize);
	printf("Enter the Out Rate ");
	scanf("%d",&outRate);
	printf("Enter the number of incoming packets ");
	scanf("%d",&n);
	while(1)
	{
		for(i=0;i<n;i++)
			{
				printf("Enter the size of the packet %d",i+1);
				scanf("%d",&packSize);
				if(packSize>bucketSize-store)
				{
					printf("PACKET DROPPED");
					empty();
					i--;
					continue;
					
				}
				store+=packSize;
				enqueue(packSize);
				printf("(%d out of %d in bucket\n", bucketSize - store, bucketSize);
			}
		while(outgoing<outRate && store>0)
		{
			x = dequeue();
			outgoing+=x;
			store-=x;
		}
		printf("%d OUT OF %d LEFT IN BUCKET\n\n", bucketSize - store, bucketSize);
	}
	empty();
}
