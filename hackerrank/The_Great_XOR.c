#include "stdio.h"

int main()
{
    int q,i;
    long long x,tmp,cnt;
	scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%lld",&x);
        cnt=1;
        tmp=x;
        while(tmp!=0)
        {
            tmp/=2;
            cnt*=2;
        }
        printf("%lld\n",cnt-(x+1));
    }
	return 0;
}


/*

Given a long integer, x, count the number of values of a satisfying the following conditions:
a xor x > x
0 < a < x
 
where a and x are long integers and xor is the bitwise XOR operator.
 
You are given q queries, and each query is in the form of a long integer denoting x. For each query, print the total number of values of a satisfying the conditions above on a new 
line.
 
Input Format
The first line contains an integer, q, denoting the number of queries.
Each of the q subsequent lines contains a long integer describing the value of x for a query.
 
Constraints
1<=q<=10^5
1<=x<=10^10
 
Subtasks
For 50% of the maximum score:
1<=q<=10^3
1<=x<=10^4

Output Format
For each query, print the number of values of a satisfying the given conditions on a new line.
 
Sample Input 0
2
2
10
 
Sample Output 0
1
5
 
Explanation 0
We perform the following q=2 queries:
 
1. For x=2 the only value of a satisfying 0<a<x is 1. This also satisfies our other condition, as 1 xor 2 = 3 and 3>x. 
Because we have one valid a and there are no more values to check, we print 1 on a new line.

2. For x=10, the following values of a satisfy our conditions:
1 xor 10 = 11
4 xor 10 = 14
5 xor 10 = 15
6 xor 10 = 12
7 xor 10 = 13
Because there are five valid values of a, we print 5 on a new line.

*/
