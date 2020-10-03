#include "stdio.h"
#define mod(num,denom)num-(num/denom)*denom

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, mod(a,b));
}

int main()
{
    int t,n,i;
    unsigned long long lcm[41];
    lcm[0]=0;
    lcm[1]=1;
    lcm[2]=2;
    for(i=3;i<41;i++)
    {
        lcm[i]=(lcm[i-1]*i)/gcd(lcm[i-1],i);
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%llu\n",lcm[n]);
    }
    return 0;
}



/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?
 
Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.
 
Output Format
Print the required answer for each test case.
 
Constraints
1<=T<=10
1<=N<=40
 
Sample Input
2
3
10

Sample Output
6
2520
 
*/