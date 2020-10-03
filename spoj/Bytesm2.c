#include "stdio.h"

int max(int x, int y, int z)
{
	if(x<y)
	{
		if(z<y)
			return y;
		else
			return z;		
	}
	else
	{
		if(z<x)
			return x;
		else
			return z;		
	}
}

int main()
{
	int t,i,j,k,cal,r,c,x,y,swp;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
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
					rra[y][k]=arr[j][k]+max(rra[x][k-1], rra[x][k], rra[x][k+1]);
				else
				{
					if(k==0)
						rra[y][k]=arr[j][k]+max(-1, rra[x][k], rra[x][k+1]);
					else
						rra[y][k]=arr[j][k]+max(rra[x][k-1], rra[x][k], -1);
				}
			}
		}
		cal=0;
		for(k=0;k<c;k++)
		{
			if(rra[y][k]>cal)
				cal=rra[y][k];
		}
		printf("%d\n",cal);
	}
	return 0;
}


/*

One of the secret chambers in Hogwarts is full of philosopher’s stones. The floor of the chamber is covered by h × w square tiles, where there are h rows of tiles from front (first row) to back (last row) and w columns of tiles from left to right. Each tile has 1 to 100 stones on it. Harry has to grab as many philosopher’s stones as possible, subject to the following restrictions:

    He starts by choosing any tile in the first row, and collects the philosopher’s stones on that tile. Then, he moves to a tile in the next row, collects the philosopher’s stones on the tile, and so on until he reaches the last row.
    When he moves from one tile to a tile in the next row, he can only move to the tile just below it or diagonally to the left or right.

Given the values of h and w, and the number of philosopher’s stones on each tile, write a program to compute the maximum possible number of philosopher’s stones Harry can grab in one single trip from the first row to the last row.
Input

The first line consists of a single integer T, the number of test cases. In each of the test cases, the first line has two integers. The first integer h (1<=h<=100) is the number of rows of tiles on the floor. The second integer w (1<=w<=100) is the number of columns of tiles on the floor. Next, there are h lines of inputs. The ith line of these, specifies the number of philosopher’s stones in each tile of the ith row from the front. Each line has w integers, where each integer m (0<=m<=100) is the number of philosopher’s stones on that tile. The integers are separated by a space character.
Output

The output should consist of T lines, (1<=T<=100), one for each test case. Each line consists of a single integer, which is the maximum possible number of philosopher’s stones Harry can grab, in one single trip from the first row to the last row for the corresponding test case.
Example

Input:
1
6 5
3 1 7 4 2
2 1 3 1 1
1 2 2 1 8
2 2 1 5 3
2 1 4 4 4
5 2 7 5 1

Output:
32 	

//7+1+8+5+4+7=32

*/
