#include "stdio.h"
#include "string.h"
#define MAXNUMBER                                               2147483650
#define SQROOT                                                  46350
#define SQROOT_of_SQROOT                                        220
#define Number_of_primes_in_first_SQROOT                        4800
#define MAX_RANGE_LEN                                           1000005
#define chkC(x,n) (x[n>>6] &  (1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6] |= (1<<((n>>1)&31)))

long long base[SQROOT >> 6], segment[MAX_RANGE_LEN >> 6], primes[Number_of_primes_in_first_SQROOT];

void simple_sieve()
{
    long long i, j, k;
    for(i=3;i<SQROOT_of_SQROOT;i+=2)
    {
        if(!chkC(base,i))
        {
            k=i<<1;
            for(j=i*i;j<SQROOT;j+=k)
            {
                setC(base, j);
            }
        }
    }
    j=0;
    for(i=3;i<SQROOT;i+=2)
    {
        if(!chkC(base,i))
        {
            primes[j]=i;
            j++;
        }
    }
}

long long segmented_sieve(long long a, long long b)
{
    long long i,j,k,cnt=0;

    if(a<=2 && 2<=b)
    {
        printf("2\n");
//        cnt++;
    }

    if(b<2)
    {
        return 0;
    }
    if(a<3)
    {
        a=3;
    }
    if((a&1)==0)
    {
        a++;
    }

    memset(segment,0,sizeof(segment));
    for(i=0;(primes[i]*primes[i])<=b;i++)
    {
        j=primes[i] * ((a+primes[i]-1)/primes[i]);
        if((j&1)==0)
        {
            j+=primes[i];
        }
        k=primes[i]<<1;
        for(;j<=b;j+=k)
        {
            if(j!=primes[i])
            {
                setC(segment,(j-a));
            }
        }
    }
    for(i=0;i<=(b-a);i+=2)
    {
        if(!chkC(segment,i))
        {
            printf("%lld\n",a+i);
//            cnt++;
        }
    }
    return cnt;
}

int main()
{
    long long i, t, start, end;
    simple_sieve();
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld %lld",&start,&end);
        segmented_sieve(start,end);
    }
    return 0;
}


/*

In this problem you have to print all primes from given interval.

Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].

Output
For each test case output must contain all primes from interval [L; U] in increasing order.

Example
Input:
2
2 10
3 7

Output:
2
3
5
7
3
5
7

*/
