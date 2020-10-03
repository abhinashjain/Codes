#include <stdio.h>
#include <math.h>
#define MAX 100001

int main()
{
    unsigned int t,n,i,j,s,tmp;
    unsigned long long divsum[MAX],sum,a;
	for(i=220;i<MAX;i++)
	{
		sum=1;
        s=sqrt(i);
        for(j=2;j<=s;j++)
        {
            if((i % j)==0)
            {
                tmp=i/j;
                sum+=tmp+j;
            }
        }
        if((s*s) == i)
        {
            sum-=s;
        }
        divsum[i]=sum;
	}
    scanf("%u",&t);
    for(i=0;i<t;i++)
    {
        scanf("%u",&n);
        sum=0;
        for(a=220;a<n;a++)
        {
            if(divsum[a]<MAX && a!=divsum[a] && divsum[divsum[a]]==a)
                sum+=a;
        }
        printf("%llu\n",sum);
    }
    return 0;
}


/*

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a)=b and d(b)=a, where a!=b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 
For example, the proper divisors of 220 are 1,2,4,5,10,11,20,22,44,55 and 110 therefore d(220)=284. The proper divisors of 284 are 1,2,4,71 and 142 so d(284)=220.
Evaluate the sum of all the amicable numbers under N.
 
Input Format
The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integer N.
 
Output Format
Print the values corresponding to each test case.
 
Constraints
1<=T<=1000
1<=N<=10^5
 
Sample Input
1
300
 
Sample Output
504
 
*/