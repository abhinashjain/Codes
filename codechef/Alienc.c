#include "stdio.h"
#include "stdlib.h"

int main()
{
	int t,i;
	unsigned long long n,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%llu",&n);		
		if(n==1)
		{
			printf("No\n");
		}
		else
		{
			if((n%2)==1)
			{
				printf("Yes\n");
			}
			else
			{
				j=2;
				while((j<n))
				{
					j=j*2;
				}
				if(j==n)
				{
					printf("No\n");
				}
				else
				{
					printf("Yes\n");
				}
			}
		}
	}
	return 0;
}


/*
An alien from a galaxy far far away has come to Earth to check out the best commodity on Earth - chocolate. The alien, on 29th January, 2013 has N chocolates.
On each day, if the number of chocolates is even, he will eat half of the chocolates. If it is odd, he brings more chocolates such that the new number of chocolates is thrice the current number of chocolates plus three. If the number of chocolates left is 1 on any day, then the alien will teleport back to his planet.
Will the alien still be on Earth on 29th January 2113?
Input

A integer T(1 ≤ T ≤ 105) containing number of test cases followed by T integers each containing a integer N (1 ≤ N ≤ 1018), number of chocolates.
Output

Output T lines, each line containing "Yes" or "No" whether he will be on earth or not after the above given time.
Example

Input:
2
2
5

Output:
No
Yes
*/
