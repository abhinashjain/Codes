#include "stdio.h"

int main()
{
	int d,n,m,i,k;
	scanf("%d",&d);
	for(i=0;i<d;i++)
	{
		scanf("%d %d",&n,&m);
		if(n==m)
			printf("1\n");
		else
			if((n>0 && m==0)||(n==0 && m>0))
				printf("0\n");
			else
			{
				k=(m-1)/2;
				n=(n-m)&k;
				if(n==0)
					printf("1\n");
				else
					printf("0\n");
			}
	}
	return 0;
}



/*
The Stirling number of the second kind S(n, m) stands for the number of ways to partition a set of n things into m nonempty subsets. For example, there are seven ways to split a four-element set into two parts: {1, 2, 3} u {4}, {1, 2, 4} u {3}, {1, 3, 4} u {2}, {2, 3, 4} u {1}, {1, 2} u {3, 4}, {1, 3} u {2, 4}, {1, 4} u {2, 3}.

There is a recurrence which allows you to compute S(n, m) for all m and n.
S(0, 0) = 1,
S(n, 0) = 0, for n > 0,
S(0, m) = 0, for m > 0,
S(n, m) = m*S(n-1, m) + S(n-1, m-1), for n, m > 0.

Your task is much "easier". Given integers n and m satisfying 1 <= m <= n, compute the parity of S(n, m), i.e. S(n, m) mod 2.

For instance, S(4, 2) mod 2 = 1.
Task

Write a program that:

    reads two positive integers n and m,
    computes S(n, m) mod 2,
    writes the result.

Input

The first line of the input contains exactly one positive integer d equal to the number of data sets, 1 <= d <= 200. The data sets follow.

Line i + 1 contains the i-th data set - exactly two integers ni and mi separated by a single space, 1 < = mi < = ni <= 10^9.
Output

The output should consist of exactly d lines, one line for each data set. Line i, 1 <= i < = d, should contain 0 or 1, the value of S(ni, mi) mod 2.
Example

Sample input:
1 
4 2 

Sample output:
1 
*/
