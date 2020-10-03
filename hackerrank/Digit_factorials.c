#include "stdio.h"
#define RANGE 100001

int main()
{
    int n,i,tmp,ind,sumtmp;
    int sum[RANGE]={0},fact[10]={1,1,2,6,24,120,720,5040,40320,362880};
    for(i=10;i<RANGE;i++)
    {
        tmp=i;
        sumtmp=0;
        sum[i]=sum[i-1];
        while(tmp!=0)
        {
            ind=(tmp%10);
            tmp/=10;
            sumtmp+=fact[ind];
        }
        if(sumtmp%i==0)
        {
            sum[i]+=i;
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",sum[n-1]);
    }
	return 0;
}


/*
 
19 is a curious number, as 1!+9!=1+362880=362881 which is divisible by 19.
 
Find the sum of all numbers below N which divide the sum of the factorial of their digits.
 
Note: as 1!,2!,...,9! are not sums they are not included.
 
Input Format
Input contains an integer N
 
Output Format
Print the answer corresponding to the test case.
 
Constraints
10<=N<=10^5
 
Sample Input
20
 
Sample Output
19
 
*/