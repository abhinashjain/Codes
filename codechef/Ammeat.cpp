#include "stdio.h"
#include "algorithm"
using namespace std;

int main()
{
	unsigned long long t,n,m,i,s;
	int j,r;
	scanf("%llu",&t);
	for(i=0;i<t;i++)
	{
		scanf("%llu %llu",&n,&m);		
		unsigned long long p[n];
		for(j=0;j<n;j++)
		{
			scanf("%llu",&p[j]);		
		}		
		sort(p,p+n);	
		s=0;
		r=0;
		for(j=(n-1);j>=0;j--)
		{
			s+=p[j];
			if(s>=m)
			{
				printf("%d\n",(n-j));
				r=1;
				break;
			}				
		}
		if(r==0)
			printf("-1\n");		
	}
	return 0;
}

/*

Andrew likes meatballs very much.

He has N plates of meatballs, here the ith plate contains Pi meatballs. You need to find the minimal number of plates Andrew needs to take to his trip to Las Vegas, if he wants to eat there at least M meatballs. Note that each plate is already packed, i.e. he cannot change the amount of meatballs on any plate.
Input

The first line of the input contains an integer T, denoting the number of test cases. The description of T test cases follows. The first line of each test case contains two space-separated integers N and M. The second line contains N space-separated integers P1, P2, ..., PN.
Output

For each test case, output an integer, denoting the minimum number of plates. If it's impossible to take at least M meatballs, print -1.
Constraints

    1 ≤ T ≤ 7777
    1 ≤ N ≤ 7
    1 ≤ M, Pi ≤ 10^18

Example

Input:
1
4 7
1 2 3 4

Output:
2

Explanation

If he takes 3rd and 4th plates, then we may eat P3 + P4 = 7 meatballs in Las Vegas. This is the only way for eating at least M = 7 meatballs with 2 plates.
*/
