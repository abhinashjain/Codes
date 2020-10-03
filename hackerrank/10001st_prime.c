#include "stdio.h"

int prime[104744],primelist[10001];
void primes()
{
    int i,j,z;
    prime[0]=1;
    prime[1]=1;
    for(i=3;(i*i)<104744;i+=2)
    {
        if(prime[i]==0)
        {
            z=i<<1;
            for(j=i*i;j<104744;j+=z)
                prime[j]=1;
        }
    }
    j=0;
    primelist[j]=2;
    for(i=3;i<104744;i+=2)
        if(prime[i]==0)
            primelist[++j]=i;
}

int main()
{
    int t,n,i,p,c;
    primes();
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%d\n",primelist[n-1]);
    }
    return 0;
}



/*

By listing the first six prime numbers: 2,3,5,7,11 and 13, we can see that the 6th prime is 13.
What is the Nth prime number?
 
Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.
 
Output Format
Print the required answer for each test case.
 
Constraints
1<=T<=10^3
1<=N<=10^4
 
Sample Input
2
3
6

Sample Output
5
13

*/