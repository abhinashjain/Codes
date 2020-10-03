#include "stdio.h"
#include "stack"
#include "cstdio"
using namespace std;

stack<unsigned long long> mystack;

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

void primeFactors(unsigned long long n)
{
	unsigned long long i,j=0;
	while(n%2==0)
	{
		j++;
		n=n/2;
	}
	if(j>0)
		mystack.push(j);

	for(i=3;i*i<=n;i=i+2)
	{
		j=0;
		while(n%i==0)
		{
			j++;
			n=n/i;
		}
		if(j>0)
			mystack.push(j);
	}
	if(n>1)			//if(n>2)
		mystack.push(1);
}

int main()
{
	int t,n,i,j,a;
	unsigned long long p,c;
	scanint(t);
	for(i=0;i<t;i++)
	{
		p=1;
		c=1;
		scanint(n);
		for(j=0;j<n;j++)
		{
			scanint(a);
			p*=a;
		}
		primeFactors(p);
		while (!mystack.empty())
		{
			c*=(mystack.top()+1);
			mystack.pop();
		}
		printf("%llu\n",c);
	}
        return 0;
}


/*

Alice has learnt factorization recently. Bob doesn't think she has learnt it properly and hence he has decided to quiz her. Bob gives Alice a very large number and asks her to find out the number of factors of that number. To make it a little easier for her, he represents the number as a product of N numbers. Alice is frightened of big numbers and hence is asking you for help. Your task is simple. Given N numbers, you need to tell the number of distinct factors of the product of these N numbers.
Input:

First line of input contains a single integer T, the number of test cases.

Each test starts with a line containing a single integer N.
The next line consists of N space separated integers (Ai).
Output:

For each test case, output on a separate line the total number of factors of the product of given numbers.
Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 10
2 ≤ Ai ≤ 1000000

Example:

Input:

3
3
3 5 7
3
2 4 6
2
5 5

Output:

8
10
3

Scoring:

You will be awarded 40 points for correctly solving for Ai ≤ 100.

You will be awarded another 30 points for correctly solving for Ai ≤ 10000.

The remaining 30 points will be awarded for correctly solving for Ai ≤ 1000000.

*/
