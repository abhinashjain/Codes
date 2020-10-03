#include "stdio.h"
#define MAXNUM 101
#define NUMDIGIT 201

int fact[MAXNUM][NUMDIGIT];
int main()
{
    int i,j,t,n,mulsum,tmp;
    fact[0][NUMDIGIT-1]=1;
    for(i=1;i<MAXNUM;i++)
    {
        mulsum=0;
        for(j=NUMDIGIT-1;j>=0;j--)
        {
            mulsum+=i*fact[i-1][j];
            fact[i][j]=mulsum%10;
            mulsum/=10;
        }
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        j=0;
        while(fact[n][j]==0)
            j++;
        for(;j<NUMDIGIT;j++)
        {
            printf("%d",fact[n][j]);
        }
        printf("\n");
    }
	return 0;
}


/*

You are asked to calculate factorials of some small positive integers.

Input
An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output
For each integer n given at input, display a line with the value of n!

Example
Sample input:
4
1
2
5
3
 
Sample output:
1
2
120
6

*/