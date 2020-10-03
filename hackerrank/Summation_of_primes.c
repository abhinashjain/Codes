#include "stdio.h"
#define max 1000001

unsigned long long prime[max];
void primes()
{
    int i,j,z;
    prime[0]=1;
    prime[1]=1;
    for(i=3;(i*i)<max;i+=2)
    {
        if(prime[i]==0)
        {
            z=i<<1;
            for(j=i*i;j<max;j+=z)
                prime[j]=1;
        }
    }
    prime[0]=0;
    prime[1]=0;
    prime[2]=2;
    for(i=3;i<max;i++)
    {
        if(prime[i]==1 || (i&1)==0)
            prime[i]=prime[i-1];
        else
            prime[i]=i+prime[i-1];
    }
}

int main()
{
    int t,n,i,p,c;
    primes();
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%llu\n",prime[n]);
    }
    return 0;
}


/*

The sum of the primes below 10 is 2+3+5+7=17.
Find the sum of all the primes not greater than given N.
 
Input Format
The first line contains an integer T i.e. number of the test cases.
The next T lines will contains an integer N.
 
Output Format
Print the value corresponding to each test case in seperate line.
 
Constraints
1<=T<=10^4
1<=N<=10^6
 
Sample Input
2
5
10

Sample Output
10
17
 
*/