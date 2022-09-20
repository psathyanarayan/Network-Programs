#include <stdio.h>
void dij(int n,int s,int cost[10][10],int dis[10]);
int main(int argc, char *argv[]) {
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

	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			{
				//scanf("%d",&cost[i][j]);
				if(cost[i][j] == 0)
				{
					cost[i][j] = 999;
				}
			}
	}
	
	printf("Enter the source vertex\n");
	scanf("%d",&s);
	
	dij(n,s,cost,dis);
	
	for(i=0;i<n;i++)
	{
		if(s!=i)
		{
			printf("%d -> %d = %d\n",s,i,dis[i]);
		}
	}
	
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d \t\t\t\t %d\n",i,dis[i]);
	}
	
}
void dij(int n,int s,int cost[10][10],int dis[10])
{
	int i,count = 0,visited[10],min,v;
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
		dis[i] = cost[s][i];
	}
	visited[s] = 1;
	dis[s] = 0;
	while(count <n)
	{
		min = 999;
		//initialize
		for(i=0;i<n;i++)
		{
			if(dis[i]<min && visited[i]==0)
			{
				min = dis[i];
				v = i;
			}
		}
		visited[v] = 1;
		count++;
		for(i=0;i<n;i++)
		{
			if(dis[i]> dis[v] + cost[v][i])
			{
				dis[i] = dis[v] + cost[v][i];
			}
		}
	}
}