#include "stdio.h"

int min(int x, int y)
{
	if(x>y)
		return y;
	else
		return x;
}

int main()
{
	int t,i,j,k,cal,r,c=3,x,y,swp;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&r);
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
			rra[y][0]=arr[j][0]+min(rra[x][1],rra[x][2]);
			rra[y][1]=arr[j][1]+min(rra[x][0],rra[x][2]);
			rra[y][2]=arr[j][2]+min(rra[x][0],rra[x][1]);
		}
		cal=10000000;
		for(k=0;k<c;k++)
		{
			if(rra[y][k]<cal)
				cal=rra[y][k];
		}
		printf("%d\n",cal);
	}
	return 0;
}


/*

Having crossed the first hurdle, Mario encounters a long and narrow alleyway, with turtles. Mario can cross it by jumping from one turtle to another. Whenever Mario makes his jump on any given turtle, he can leave it in any of the three possible states, as per his choice. These states are:

    Active (A)
    Dormant (D)
    Bruised (B) 

There are n turtles in the street, indexed 0..(n-1)
Each jump costs some amount of energy, which depends on the index of turtle as well as the state it is left in. However, Mario has to take care that no neighboring turtles are left in the same state, or otherwise they all will reunite and cause a fatal attack on Mario, as he is about to leave the alley.
The neighbors of turtle i are turtles i-1 and i+1. The first and last turtles are not neighbors.
You need to find out the minimum amount of energy required to cross the alley.

Input
first line contains no. of test cases T (T <= 5)
T input sets are given in the following manner
the first line contains n, no. of turtles (n <= 20)
the next n lines have space separated 3 numbers (a1, a2, a3), the values of energy needed for ith turtle to change into states A D B (0 <= ai <= 1000)
similarly, the inputs are given for other cases

Output
T lines, the minimal energy needed for each set of input

Sample I/O

Input
2
3
0 1 2
1 4 8
9 2 5
4
10 10 10
2 4 9
12 7 10
6 6 6

Output
4
25
*/
