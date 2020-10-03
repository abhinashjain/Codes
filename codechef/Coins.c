#include "stdio.h"
     
unsigned int coins[15625000]={0};
int main()
{
	int i;
	unsigned int c,n;
	unsigned int convert(unsigned int);
	coins[1]=1;
	for(i=0;i<10;i++)
	{
		scanf("%lu",&n);
		c = convert(n);
		if(c>n)
			printf("%lu\n",c);
		else
			printf("%lu\n",n);
	}
	return 0;
}

unsigned int convert(unsigned int n)
{
	unsigned int c;
	if(((n<15625000) && (coins[n] != 0)) || (n==0))
		return coins[n];
	c = convert(n/2)+convert(n/3)+convert(n/4);
	if(c > n)
	{
		if(n<15625000)
			coins[n]=c;
		return c;
	}
	else
	{
		if(n<15625000)
			coins[n]=n;
		return n;
	}
}

/*
In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n
can be exchanged in a bank into three coins: n/2, n/3 and n/4.
But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange
rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars
you can get for it?
Input

The input will contain several test cases (not more than 10). Each
testcase is a single line with a number n, 0 <= n <= 1 000 000 000.
It is the number written on your coin.
Output

For each test case output a single line, containing the maximum amount
of American dollars you can make.
Example

Input:
12
2

Output:
13
2

You can change 12 into 6, 4 and 3, and then change these into
$6+$4+$3 = $13.

If you try changing the coin 2 into 3 smaller coins, you will get
1, 0 and 0, and later you can get no more than $1 out of them.
It is better just to change the 2 coin directly into $2.
*/
