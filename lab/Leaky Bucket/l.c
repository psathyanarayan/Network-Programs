#include<stdio.h>
int main()
{
    int bucketSize,outgoing,incoming,n,store=0;
    printf("Enter the bucket size\n");
    scanf("%d",&bucketSize);
    printf("Enter the outgoing rate\n");
    scanf("%d",&outgoing);
    printf("Enter the no of inputs\n");
    scanf("%d",&n);

    while (n!=0)
    {
        printf("Enter the incoming packet size\n");
        scanf("%d",&incoming);

        if(incoming<= (bucketSize-store))
        {
            store+=incoming;
            printf("%d out of %d",store,bucketSize);
        }
        else
        {
            printf("%d packets are dropped",incoming-(bucketSize-store))
            store = 
        }
    }
    

}