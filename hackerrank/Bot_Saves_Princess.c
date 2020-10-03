#include <stdio.h>
#include <string.h>

void displayPathtoPrincess(int n, char grid[n][n])
{
	int i,j,k,x,y,flag=0;
	k=(n-1)/2;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(grid[i][j]=='p')
			{
				flag=1;
				break;
			}
		if(flag==1)
            		break;
	}
	x=i-k;
	y=j-k;
	if(x>0)
		for(i=0;i<x;i++)
			printf("DOWN\n");
	else
		if(x<0)
			for(i=0;i<(-(x));i++)
				printf("UP\n");         
	if(y>0)
		for(i=0;i<y;i++)
			printf("RIGHT\n");
	else
		if(y<0)
			for(i=0;i<(-(y));i++)
				printf("LEFT\n");         
}

int main(void) 
{
	int m;
	scanf("%d", &m);
	char grid[m][m];
	char line[m];
	for(int i=0;i<m;i++) 
	{
		scanf("%s",line);
		strncpy(grid[i], line, m);
	}
	displayPathtoPrincess(m,grid);
	return 0;
}
