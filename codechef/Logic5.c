#include "stdio.h"

int main()
{
	long long t,p,q,i;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld %lld",&p,&q);
		if(((p+q)&1)==0 && (p&1 || q&1))
			printf("B\n");
		else
			printf("A\n");
	}
	return 0;            
}


/*

A and B are playing a game. They start with two piles of p and q chips, respectively. A and B take a move alternately(A starts the game). A move consists of removing any pile and splitting the other pile into two piles (of any sizes). The loser is the one who cannot make a move any more. Can you decide who will win the game, assuming both the players play optimally?
Input

An integer T, denoting the number of test cases. Each test case contains two integers p and q, the size of the two piles.
Output

For every test case print "A" if A wins or "B" if B wins in a new line(without quotes).
Constraints

1 <= T <= 100000

1 <= p <= 10^18

1 <= q <= 10^18

Example
Sample Input
4
2 2
1 3
5 6
6 7

Sample Output
A
B
A
A

*/
