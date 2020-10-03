#include "stdio.h"
#define number_of_witness 13
#define rep(i,begin,end) for(i=begin;i<end;i++)

long long witness[number_of_witness]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

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
    long long t,n,i;
    scanf("%lld",&t);
    rep(i,0,t)
    {
        scanf("%lld",&n);
        if(isprime_Miller_Rabin(n)==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}


/*

Given the number, you are to answer the question: "Is it prime?"

Input
t – the number of test cases, then t test cases follows. [t <= 500]
Each line contains one integer: N [2 <= N <= 2^63-1]

Output
For each test case output string "YES" if given number is prime and "NO" otherwise.

Example
Input:
5
2
3
4
5
6

Output:
YES
YES
NO
YES
NO

*/
