#include<stdio.h>
int front = -1,rear = -1,q[100];
void enqueue(int x,int SIZE)
{
    if(rear == SIZE-1)
    {
        printf("Queue is full Discarded");
    }
    else{
        if(front == -1)
            front = 0;
        rear++;
        q[rear] = x;
    }
    
    
}
int dequeue()
{
    if(front == -1)
        {
            return -1;
        }
    else{
        int val = q[front];
        printf("Deleted item = %d ",val);
        front++;
        if(front>rear)
            front = rear = -1;
        return val;
    }
    
    
}

int main(){
    int incoming, outgoing, buck_size, n, store = 0;
    //store is used to store the number of packets that are removed from the buffer
    //buck_size is the size of the buffer in bytes
    //n is the number of packets that are to be transmitted
    //incoming is the size of the incoming packet in bytes
    //outgoing is the size of the outgoing packet in bytes
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n != 0) {
        printf("Enter the incoming packet size : ");
        scanf("%d", &incoming);
        printf("Incoming packet size %d\n", incoming);
        //if the incoming packet size is greater than the bucket size
        if (incoming <= (buck_size - store)){
            enqueue(incoming, buck_size);
            store += incoming; //add the incoming packet size to the buffer
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
        } else {
            printf("Dropped %d no of packets\n", incoming - (buck_size - store));
            int out =0;
            while(out<outgoing && store>0)
            {
                int x = dequeue();
                out+=incoming;
                printf("Outgoing Packet size = %d",incoming);
                store-=incoming;
            }
            printf("Bucket buffer size %d out of %d\n", buck_size-store, buck_size);
            n+=1;
            //if the incoming packet size is greater than the bucket size
            //then the packets are dropped
            store = buck_size;
        }
        store = store - outgoing; //subtract the outgoing packet size from the buffer
        if(store < 0)
            store = 0; //if the buffer size is less than 0 then set it to 0
        printf("After outgoing %d packets left out of %d in buffer\n", store, buck_size);
        n--;
    }
}