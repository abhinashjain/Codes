#include "stdio.h"
#include "math.h"

int main()
{
	int t,i,n,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		n=2*n;
		j=(int)sqrt(n);
		if((j*(j+1))<n)
			j++;
		printf("%d\n",j);
	}
	return 0;            
}



/*

There is a N-story building and you are given two identical eggs. The eggs (and the building) have an interesting property that if you throw the egg from a floor number less than X, it will not break. And it will always break if the floor number is greater than or equal to X. Assuming that you can reuse the eggs which didn't break, you need to find X in a minimal number of throws. What is the worst case upper bound on the number of throws you must make to determine this X?
Input

An integer T, denoting the number of test cases (1<= T <= 100000).

Each test case contains one integer N, the number of floors in the building.
Output

For each test case, print the minimum number of moves required to determine X on a new line.

Constraints
2 <= N <= 10^9

1 <= T <= 100000

1 <= X <= N

Example
Sample Input
2
2
4

Sample Output
2
3

*/
