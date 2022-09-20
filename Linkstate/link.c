#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void dij(int s,int n,int cost[10][10],int dis[10])
{
	int i,j,v,min,visited[10],count = 0,f[10][10];
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
		dis[i] = cost[s][i];
		
	}
	visited[s] = 1;
	dis[s] = 0;
	while(count<n)
	{
		min = 999;
		for(i=0;i<n;i++)
			{
				if(dis[i]<min && visited[i] ==0)
					{
						min = dis[i];
						v = i;
					}
				
			}
		visited[v] = 1;
		
		for(i=0;i<n;i++)
		{
			if(dis[i]>dis[v]+cost[v][i])
			{
				dis[i] = dis[v]+cost[v][i];
			}
			f[count][i] = dis[i];
		}
		count++;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
			
			printf("%d ",f[i][j]);
		printf("\n");
	}
	
}

int main() {
	int i,j,n=10,s,dis[10];
	int cost[10][10] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(cost[i][j] ==0)
				cost[i][j] = 999;
		}
	}
	
	dij(0,10,cost,dis);
	printf("\nVertex \t\t\t Distance\n");
	for(i=0;i<n;i++)
		{
			printf("%d \t\t\t\t %d\n",i,dis[i]);
		}
	
}
