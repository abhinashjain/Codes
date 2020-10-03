#include "stdio.h"
#define mod 1000000007    //if this number is not prime, then this algo won't work

long long bigmod(long long a, long long p, long long m)
{
    long long res=1%m, x=a%m;
    while(p)
    {
        if(p&1)
        {
            res=(res*x)%m;
        }
        x=(x*x)%m;
        p >>= 1;
    }
    return res;
}

int main()
{
    long long i,n,k,a=1,b=1,c=1;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)
    {
        a=(a*i)%(mod);
    }
    for(i=1;i<=k;i++)
    {
        b=(b*i)%(mod);
    }
    for(i=1;i<=(n-k);i++)
    {
        c=(c*i)%(mod);
    }
    b = bigmod(b, mod-2, mod);
    c = bigmod(c, mod-2, mod);
    a = (a*b)%mod;
    a = (a*c)%mod;
    printf("%lld\n",a);
    return 0;
}
