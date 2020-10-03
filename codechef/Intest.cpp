#include "stdio.h"
#include "cstdio"

void scanint(int &x)
{
	register int c = getchar_unlocked();
	int neg = 0;
	x = 0;
	for(;((c<48 || c>57) && c != '-');
	c = getchar_unlocked());
	if(c=='-') 
	{
		neg=1;
		c=getchar_unlocked();
	}
	for(;c>47 && c<58;c = getchar_unlocked())
		x = (x<<1) + (x<<3) + c - 48;
	if(neg) 
		x=-x;
}

int main()
{  

	int i,n,k,cnt=0,num;
	scanint(n);
	scanint(k);
	for(i=0;i<n;i++)
	{
		scanint(num);
		if(num%k==0)
			cnt++;
	}   
	printf("%d\n",cnt);
	return 0;            
}

/*

All submissions for this problem are available.

The purpose of this problem is to verify whether the method you are using to read input data is sufficiently fast to handle problems branded with the enormous Input/Output warning. You are expected to be able to process at least 2.5MB of input data per second at runtime.
Input

The input begins with two positive integers n k (n, k<=10^7). The next n lines of input contain one positive integer ti, not greater than 10^9, each.
Output

Write a single integer to output, denoting how many integers ti are divisible by k.
Example

Input:
7 3
1
51
966369
7
9
999996
11

Output:
4

*/
