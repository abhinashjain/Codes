#include "stdio.h"
//#define mod 1000000007

void multiply(long long F[2][2], long long M[2][2])
{
    long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
    
    F[0][0] = x;    //x%mod;
    F[0][1] = y;    //y%mod;
    F[1][0] = z;    //z%mod;
    F[1][1] = w;    //w%mod;
}

void power(long long F[2][2], long long n)
{
    if(n<2)
    {
        return;
    }
    
    long long M[2][2] = {{1,1},{1,0}};
    power(F, n/2);
    multiply(F, F);
    
    if(n&1)
    {
        multiply(F, M);
    }
}

long long fib(long long n)
{
    long long F[2][2] = {{1,1},{1,0}};
    if(n == 0)
    {
        return 0;
    }
    power(F, n-1);
    return F[0][0];
}

int main()
{
    long long n;
    scanf("%lld",&n);
//    printf("%lld\n",fib(n) % mod);
    printf("%lld\n",fib(n));
    return 0;
}


/*

If n is even then k = n/2:
F(n) = [2*F(k-1) + F(k)]*F(k)

If n is odd then k = (n + 1)/2
F(n) = F(k)*F(k) + F(k-1)*F(k-1)

Time Complexity: O(LogN)

*/
