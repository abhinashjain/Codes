#include "stdio.h"

int min(int x, int y, int z)
{
	if(x>y)
	{
		if(z>y)
			return y;
		else
			return z;		
	}
	else
	{
		if(z>x)
			return x;
		else
			return z;		
	}
}

int main()
{
	int j,k,cal,r,c,x,y,swp;
	scanf("%d %d",&r,&c);
	int arr[r][c],rra[2][c];
	for(j=0;j<r;j++)
	{
		for(k=0;k<c;k++)
		{
			scanf("%d",&arr[j][k]);
			if(j==r-1)
				rra[0][k]=arr[j][k];
		}
	}
	x=1;
	y=0;
	for(j=r-2;j>=0;j--)
	{
		swp=x;
		x=y;
		y=swp;
		for(k=0;k<c;k++)
		{
			if(k>0 && k<c-1)
				rra[y][k]=arr[j][k]+min(rra[x][k-1], rra[x][k], rra[x][k+1]);
			else
			{
				if(k==0)
					rra[y][k]=arr[j][k]+min(100000, rra[x][k], rra[x][k+1]);
				else
					rra[y][k]=arr[j][k]+min(rra[x][k-1], rra[x][k], 100000);
			}
		}
	}
	cal=10000000;
	for(k=0;k<c;k++)
	{
		if(rra[y][k]<cal)
			cal=rra[y][k];
	}
	printf("%d\n",cal);
	return 0;
}


/*

Jack is a wise and miser man. Always tries to save his money.

One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:

    At every city, he has to change the bus.

    And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.

You are to help Jack to go from A to B by spending the minimum amount of money.

N,M,K<=100.
Input

Line 1:    N M
Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output

Single Line containing the minimum amount of fare that Jack has to give.
Example

Input:
5 5
1 3 1 2 6
10 2 5 4 15
10 9 6 7 1
2 7 1 5 3
8 2 6 1 9

Output:
10

Explanation:
1->4->1->3->1 = 10

*/
