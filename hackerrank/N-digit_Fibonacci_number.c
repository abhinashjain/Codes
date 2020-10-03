#include "stdio.h"
#define RANGE 25000
#define NUMDIGIT 5001

int main()
{
    int i,j,t,n,tmp;
    unsigned long long fib[NUMDIGIT]={0},fn1[NUMDIGIT]={0},fn2[NUMDIGIT]={0};
    fib[1]=1;
    fn1[NUMDIGIT-1]=2;
    fn2[NUMDIGIT-1]=1;
    for(i=4;i<RANGE;i++)
    {
        tmp=0;
        for(j=NUMDIGIT-1;j>=0;j--)
        {
            tmp+=fn1[j]+fn2[j];
            fn2[j]=fn1[j];
            fn1[j]=tmp%10;
            tmp/=10;
        }
        for(j=0;j<NUMDIGIT;j++)
        {
            if(fn1[j]!=0)
                break;
        }
        tmp=NUMDIGIT-j;
        if(fib[tmp]==0)
            fib[tmp]=i;
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%llu\n",fib[n]);
    }
	return 0;
}


/*

The Fibonacci sequence is defined by the recurrence relation:
F(n)=F(n-1)+F(n-2), where F(1)=1 and F(2)=1.
 
Hence the first 12 terms will be:
F(1)=1
F(2)=1
F(3)=2
F(4)=3
F(5)=5
F(6)=8
F(7)=13
F(8)=21
F(9)=34
F(10)=55
F(11)=89
F(12)=144
 
The 12th term, F(12), is the first term to contain 3 digits.
What is the first term in the Fibonacci sequence to contain N digits?
 
Input Format
The first line contains an integer T, i.e., number of test cases.
Next T lines will contain an integer N.
 
Output Format
Print the values corresponding to each test case.
 
Constraints
1<=T<=5000
2<=N<=5000
 
Sample Input
2
3
4
 
Sample Output
12
17

*/