#include "stdio.h"
#include "iostream"
using namespace std;

int prime[250];
int numprime[250];

int main()
{
	int i,r,c,t,j,k,min,tot;
	void primes();
	primes();
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		tot=0;		
		scanf("%d %d",&r,&c);
		char arr[r][c];
		int top[r][c], left[r][c], bot[r][c], right[r][c];
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				cin >> arr[j][k];
				if(j!=0 && j<r-2)
				{
					if(arr[j][k]=='^')
						top[j][k]=top[j-1][k]+1;
					else
						top[j][k]=-1;	
				}
				else
				{
					if(j==0)
						if(arr[0][k]=='^')
							top[0][k]=0;
						else
							top[0][k]=-1;
				}
				if(k!=0 && k<c-2)
				{
					if(arr[j][k]=='^')
						left[j][k]=left[j][k-1]+1;
					else
						left[j][k]=-1;	
				}
				else
				{
					if(k==0)
						if(arr[j][0]=='^')
							left[j][0]=0;
						else
							left[j][0]=-1;
				}
			}
		}
		
		for(j=r-1;j>=2;j--)
		{
			for(k=c-1;k>=2;k--)
			{
				if(j!=r-1)
				{
					if(arr[j][k]=='^')
						bot[j][k]=bot[j+1][k]+1;
					else
						bot[j][k]=-1;
				}
				else
				{
					if(arr[r-1][k]=='^')
						bot[r-1][k]=0;
					else
						bot[r-1][k]=-1;
				}
				if(k!=c-1)
				{
					if(arr[j][k]=='^')
						right[j][k]=right[j][k+1]+1;
					else
						right[j][k]=-1;
				}
				else
				{
					if(arr[j][c-1]=='^')
						right[j][c-1]=0;
					else
						right[j][c-1]=-1;
				}
			}
		}

		for(j=2;j<(r-2);j++)
		{
			for(k=2;k<(c-2);k++)
			{
				if(top[j][k]>=2 && left[j][k]>=2 && bot[j][k]>=2 && right[j][k]>=2)
				{
					min=left[j][k];

					if(top[j][k]<min)
						min=top[j][k];

					if(right[j][k]<min)
						min=right[j][k];

					if(bot[j][k]<min)
						min=bot[j][k];
					
					if(numprime[min]>=1000)
						tot+=numprime[(numprime[min]-1000)];
					else
						tot+=numprime[min];
				}
			}
		}
		printf("%d\n",tot);
	}
	return 0;            
}

void primes()
{
   	int i,z,j,p,c;

   	prime[0]=1;
	prime[1]=1;
   	prime[2]=0;

	numprime[0]=0;
	numprime[1]=0;
	numprime[2]=1;

	c=2;
   	for(i=3;i<250;i++)
	{
		if(i%2==0)
			prime[i]=1;
   		if(!prime[i])
      		{
	 	        numprime[i]=c;
         	        c++;
         	        p=i;

			z=i*2;
      			for(j=i*i;j<250;j+=z)
				prime[j]=1;
		}
		else
			numprime[i]=1000+p;
   	}
}



/*
Past

In the year of 2048, the Virtual Reality Massively Multiplayer Online Role-Playing Game (VRMMORPG), Code Art Online (CAO), is released. With the Chef Gear, a virtual reality helmet that stimulates the user's five senses via their brain, players can experience and control their in-game characters with their minds.

On August the 2nd, 2048, all the players log in for the first time, and subsequently discover that they are unable to log out. They are then informed by Code Master, the creator of CAO, that if they wish to be free, they must reach the second stage of the game.

Kirito is a known star player of CAO. You have to help him log out.

Present

Stage 2

A map is described by a 2D grid of cells. Each cell is either labelled as a # or a ^. # denotes a wall. A monster exists in a cell if the cell is not a wall and the cell is a centre of Prime-Cross (CPC).

    Let L be the number of contiguous ^ to the left of X, in the same row as X.
    R be the number of contiguous ^ to the right of X, in the same row as X.
    T be the number of contiguous ^ above X, in the same column as X.
    B be the number of contiguous ^ below X, in the same column as X.

A cell X is said to be a CPC if there exists a prime number P such that P ≤ minimum of [L, R, T, B].

Note that, there can be many such primes, let N be the number of such primes. That CPC can accommodate N monsters.

Note: While computing L, R, T, B for a cell X, you should not count the ^ of the cell X.

Given a map, you have to tell Kirito the number of cells where monsters exist.

Future

Have fun solving other tasks :-)
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. Each case starts with a line containing two space separated integers R, C, denoting the number of rows and columns in the map respectively. The next R lines contain C characters each, describing the map.
Output

For each test case, output a single line containing the number of monsters the map can accommodate.
Constraints

    1 ≤ T ≤ 100
    1 ≤ R ≤ 500
    1 ≤ C ≤ 500

Example

Input:
2
3 10
#^^^^^#^##
^^^^^^^^^^
^^^^^^^^^#
7 10
^^^^#^^^^#
^^^^^^^^#^
^^##^^#^^^
#^^^^^^^#^
^^#^^^^^^^
^^^^#^^^^^
^^^^^^^^^^

Output:
0
3
*/
