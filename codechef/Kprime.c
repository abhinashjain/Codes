#include "stdio.h"

int arr[100001];

void primeFactors(int n)
{
	int i,j=0,c=0,ind=n;
	while(n%2==0)
	{
		j++;
		n=n/2;
	}
	if(j>0)
		c++;

	for(i=3;i*i<=n;i=i+2)
	{
		j=0;
		while(n%i==0)
		{
			j++;
			n=n/i;
		}
		if(j>0)
			c++;
	}
	if(n>1)			//if(n>2)
		c++;
	arr[ind]=c;
}

int main()
{
	int t,a,b,k,i,j,c;
	for(i=2;i<=100000;i++)
		primeFactors(i);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		c=0;
		scanf("%d %d %d",&a,&b,&k);
		for(j=a;j<=b;j++)
		{
			if(arr[j]==k)
				c++;
		}		
		printf("%d\n",c);
	}
        return 0;
}

/*

Alice and Bob are studying for their class test together. The topic of the test is Prime Numbers. The preparation is getting too boring for their liking. To make it interesting, they turn it into a game. The winner will get an ice-cream treat from the other.

The game is called Count K-Primes. A number is a k-prime if it has exactly k distinct prime factors. The game is quite simple. Alice will give three numbers A, B & K to Bob. Bob needs to tell Alice the number of K-prime numbers between A & B (both inclusive). If Bob gives the correct answer, he gets a point. If not, Alice gets a point. They play this game T times.

Bob hasn't prepared so well. But he really wants to win the game. He wants you to tell him the correct answer.
Input

First line of input contains a single integer T, the number of times they play. Each game is described in a single line containing the three numbers A,B & K.
Output

For each game, output on a separate line the number of K-primes between A & B.
Constraints:

1 ≤ T ≤ 10000
2 ≤ A ≤ B ≤ 100000
1 ≤ K ≤ 5
Example:

Input
4
2 5 1
4 10 2
14 15 2
2 20 3

Output
4
2
2
0

*/
