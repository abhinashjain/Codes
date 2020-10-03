#include "stdio.h"

int main()
{
    int i,n,max,sum,tmp,dig,j,prod,tot=0;
    scanf("%d",&n);
    max=n;
    for(i=0;i<n;i++)
    {
        max=max*9;
    }
    for(i=10;i<=max;i++)
    {
        tmp=i;
        sum=0;
        while(tmp!=0)
        {
            dig=tmp%10;
            tmp/=10;
            prod=1;
            for(j=0;j<n;j++)
            {
                prod=prod*dig;
            }
            sum+=prod;
        }
        if(sum==i)
            tot+=sum;
    }
    printf("%d",tot);
	return 0;
}


/*

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634=1^4+6^4+3^4+4^4
8208=8^4+2^4+0^4+8^4
9474=9^4+4^4+7^4+4^4
 
As 1 = 1^4 is not a sum it is not included.
The sum of these numbers is 1634+8208+9474=19316.
 
Find the sum of all the numbers that can be written as the sum of Nth powers of their digits.
 
Input Format
Input contains an integer N
 
Constraints
3<=N<=6

Output Format
Print the answer corresponding to the test case.
 
Sample Input
4
 
Sample Output
19316

*/
