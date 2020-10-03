#include "stdio.h"
#define mod(num,denom)num-(num/denom)*denom

long long primeFactors(long long n)
{
	long long i,max=2;
	while((n&1)==0)
	{
		n=n>>1;
	}
	for(i=3;i*i<=n;i=i+2)
	{
		while(mod(n,i)==0)
		{
            max=i;
			n=n/i;
		}
	}
	if(n>1)
        max=n;
    return max;
}

int main()
{
    int t,i;
    long long n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&n);
        printf("%lld\n",primeFactors(n));
	}
    return 0;
}



/*

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of a given number N?
 
Input Format
First line contains T, the number of test cases. This is followed by T lines each containing an integer N.
 
Output Format
For each test case, display the largest prime factor of N.
 
Constraints
1<=T<=10
10<=N<=10^12
 
Sample Input
2
10
17

Sample Output
5
17
 
*/