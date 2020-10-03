#include "stdio.h"

int check(long long x, long long y, long long p, long long q, long long t)
{
    return ( (p * t) >= x ) && ( (q * t) - (p * t) >= (y - x) );
}

int main()
{
    long long x, y, p, q, m, l=-1, r=1000000000LL;
    scanf("%lld %lld %lld %lld", &x, &y, &p, &q);
    while (r - l > 1)
    {
        m = (l + r) / 2;
        if(check(x, y, p, q, m)==1)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    return 0;
}

/*

int check(long long k)
{
    if(success)
        return 1;
    return 0;
}
main()
{
    l=0;
    r=n;
    while(l<=r)
    {
        m=(l+r)/2;
        if(check(m))
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
}

*/
