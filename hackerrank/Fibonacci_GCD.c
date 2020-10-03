#include "stdio.h"
#define mod 1000000007

void multiply(long long F[2][2], long long M[2][2])
{
    long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
    
    F[0][0] = x%mod;
    F[0][1] = y%mod;
    F[1][0] = z%mod;
    F[1][1] = w%mod;
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

long long gcdFunc(long long a, long long b)
{
    if(a==0 || b == 0)
    {
        return a+b;
    }
    return gcdFunc(b, (a%b));
}

int main()
{
    long long i,n,a,gcd;
    scanf("%lld",&n);
    scanf("%lld",&a);
    gcd=a;
    for(i=1;i<n;i++)
    {
        scanf("%lld",&a);
        gcd=gcdFunc(gcd,a);
    }
    printf("%lld\n",fib(gcd) % mod);
    return 0;
}


/*

Fibonacci numbers have the following form:
            F(1)=1
            F(2)=1
            F(3)=2
            F(n)=F(n-2) + F(n-1)

We have an array a1, a2, ..., aN which contains N elements.

We want to find gcd( F(a1), F(a2), ..., F(aN) ).

Input Format
The first line contains N, where N denotes size of the array.
Each of the next N lines contains a number: the ith line contains ai.

Output Format
Print a single integer — the remainder of the division of the resulting number by 1000000007.

Constraints
1 <= N <= 2*10^5
1 <= ai <= 10^12

Sample Input 1
3
2
3
5

Sample Output 1
1

Explanation 1
F(2)=1
F(3)=2
F(5)=5
gcd(1,2,5)=1

Sample Input 2
2
3
6

Sample Output 2
2

Explanation 2
F(3)=2
F(6)=8
gcd(2,8)=2

*/
