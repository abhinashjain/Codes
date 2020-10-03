#include "stdio.h"
#include "math.h" //sometimes takes extra time of 0.01 for case of sqrt in prime calculation
#include <list> // list = 0.64, array = 0.68, vector = 0.67, map = 1.88
#include <vector> 
using namespace std;
     
list<int> mylist;
list<int>::iterator iter;
vector<bool> prime(10001,1);
int main()
{
	void primes();
	primes();
	int t,n,i,p,c;
	vector<int> vect(10001,-1);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		if(vect[n] == -1)
		{
			c=0;
			for(iter=mylist.begin();*iter <= (n-2); iter++)
			{
				p = n-(*iter);
				if((p%2 == 1 || p==2) && prime[p] == 1)
					c++;
			}
			vect[n]=c;
			printf("%d\n",c);
		}
		else
			printf("%d\n",vect[n]);			
	}
	return 0;
}

void primes()
{
	prime[0]=0;
	prime[1]=0;
	int i,z,j;
	for(i=3;i<=sqrt(10000);i=i+2) // i*i<=10000 instead of sqrt for saving 0.01 extra time sometimes
	{
		if(prime[i])
		{
			z=i<<1;
			for( j = i*i; j <=10000; j += z )
				prime[j]=0;
		}
	}
	mylist.push_back(4);
	for(i=3;i<=10000;i=i+2)
		if(prime[i]!=0)
			mylist.push_back(2*i);
}		


/*

Levy's conjecture, named after Hyman Levy, states that all odd integers greater than 5 can be represented as the sum of an odd prime number and an even semiprime. To put it algebraically, 2n + 1 = p + 2q always has a solution in primes p and q (not necessary to be distinct) for n > 2. (Source: Wikipedia)

In this problem, given a positive integer N (not necessary to be odd integer greater than 5). Your task is to calculate how many distinct ordered pairs (p, q) such that N = p + 2q, where p and q are primes.
Input

The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow.

Each test case consists of exactly one line containing an integer N.
Constraints

    1 ≤ T ≤ 100000 (10^5)
    1 ≤ N ≤ 10000 (10^4)

Output

For each test case, output the number of ordered pairs (p, q) of primes such that N = p + 2q.
Example

Input:
3
2
7
11

Output:
0
1
2

Explanation

Case #1: There are no ordered pairs (p, q) such that p + 2q = 2.

Case #2: There is only one ordered pair (p, q) = (3, 2) such that p + 2q = 7.

Case #3: There are two ordered pairs (p, q) = (7, 2), (5, 3) such that p + 2q = 11.
*/
