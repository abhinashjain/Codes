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

if n < 2,047, it is enough to test for witness = 2;
if n < 1,373,653, it is enough to test for witness = 2 and 3;
if n < 9,080,191, it is enough to test for witness = 31 and 73;
if n < 25,326,001, it is enough to test for witness = 2, 3, and 5;
if n < 3,215,031,751, it is enough to test for witness = 2, 3, 5, and 7;
if n < 4,759,123,141, it is enough to test for witness = 2, 7, and 61;
if n < 1,122,004,669,633, it is enough to test for witness = 2, 13, 23, and 1662803;
if n < 2,152,302,898,747, it is enough to test for witness = 2, 3, 5, 7, and 11;
if n < 3,474,749,660,383, it is enough to test for witness = 2, 3, 5, 7, 11, and 13;
if n < 341,550,071,728,321, it is enough to test for witness = 2, 3, 5, 7, 11, 13, and 17.
if n < 3,825,123,056,546,413,051, it is enough to test for witness = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
if n < 18,446,744,073,709,551,616 = 264, it is enough to test for witness = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.
if n < 318,665,857,834,031,151,167,461, it is enough to test for witness = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.
if n < 3,317,044,064,679,887,385,961,981, it is enough to test for witness = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, and 41.

*/
