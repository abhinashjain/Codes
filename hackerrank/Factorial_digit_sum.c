#include "stdio.h"
#define MAXNUM 1001
#define NUMDIGIT 2601

int fact[MAXNUM][NUMDIGIT];
int main()
{
    int i,j,t,n,mulsum;
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
        mulsum=fact[n][0];
        for(j=1;j<NUMDIGIT;j++)
            mulsum+=fact[n][j];
        printf("%d\n",mulsum);
    }
	return 0;
}


/*

n! means nx(n-1)x . . . x3x2x1
For example, 10!=10x9x . . . x3x2x1=3628800, and the sum of the digits in the number 10! is 3+6+2+8+8+0+0=27.
 
Find the sum of the digits in the number N!
 
Input Format
The first line contains an integer T, i.e., number of test cases.
Next T lines will contain an integer N.
 
Output Format
Print the values corresponding to each test case.
 
Constraints
1<=T<=100
0<=N<=1000
 
Sample Input
2
3
6
 
Sample Output
6
9

*/