#include "stdio.h"
#define number_of_witness 5
#define rep(i,begin,end) for(i=begin;i<end;i++)

long long witness[number_of_witness]={2, 3, 5, 7, 11};

long long mul_mod(long long a, long long b,long long c)
{
    long long x=0,y=a%c;
    while(b>0)
    {
        if(b&1)
        {
            x=(x+y)%c;
        }
        y=(y<<1)%c;
        b=b>>1;
    }
    return x%c;
}

long long modulo(long long a, long long b, long long c)
{
    long long x=1,y=a;
    while(b>0)
    {
        if(b&1)
        {
            x=mul_mod(x,y,c);
        }
        y=mul_mod(y,y,c);
        b=b >> 1;
    }
    return x%c;
}

int isprime_Miller_Rabin(long long p)
{
    long long i,a,temp,mod,s=p-1;
    rep(i,0,number_of_witness)
    {
        if(p==witness[i])
        {
            return 1;
        }
    }
    rep(i,0,number_of_witness)
    {
        if((p%witness[i])==0)
        {
            return 0;
        }
    }

    if(p<2)
    {
        return 0;
    }
    if(p!=2 && (p&1)==0)
    {
        return 0;
    }
    
    while((s&1)==0)
    {
        s=s >> 1;
    }
    
    rep(i,0,number_of_witness)
    {
        a=witness[i];
        temp=s;
        mod=modulo(a,temp,p);
        while(temp!=(p-1) && mod!=1 && mod!=(p-1))
        {
            mod=mul_mod(mod,mod,p);
            temp=temp << 1;
        }
        if(mod!=(p-1) && (temp&1)==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long t,n,k,i;
    scanf("%lld",&t);
    rep(i,0,t)
    {
        scanf("%lld %lld",&n,&k);
        if(k==1)
        {
            if(isprime_Miller_Rabin(n))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else
        {
            if(k==2)
            {
                if(n<4)
                {
                    printf("No\n");
                }
                else
                {
                    if(n&1)
                    {
                        if(isprime_Miller_Rabin(n-2))
                        {
                            printf("Yes\n");
                        }
                        else
                        {
                            printf("No\n");
                        }
                    }
                    else
                    {
                        printf("Yes\n");
                    }
                }
            }
            else
            {
                if(n<(2*k))
                {
                    printf("No\n");
                }
                else
                {
                    printf("Yes\n");
                }
            }
        }
    }
    return 0;
}


/*

The problem is quite simple. You're given a number N and a positive integer K. Tell if N can be represented as a sum of K prime numbers (not necessarily distinct).

Input Format
The first line contains a single integer T, denoting the number of test cases.
Each of the next T lines contains two positive integers, N & K, separated by a single space.

Output Format
For every test case, output "Yes" or "No" (without quotes).

Constraints
1 <= T <= 5000
1 <= N <= 10^12
1 <= K <= 10^12

Sample Input
2
10 2
1 6

Sample Output
Yes
No

Explanation
In the first case, 10 can be written as 5 + 5, and 5 is a prime number. In the second case, 1 cannot be represented as a sum of prime numbers, because there are no prime numbers less
than 1.

*/
