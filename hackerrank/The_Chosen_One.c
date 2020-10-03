#include <stdio.h>
#define MAX 2000000000000000000

long long gcd(long long a, long long b)
{
    long long t;
    while (b != 0)
    {
        t = b;
        b = a % t;
        a = t;
    }
    return a;
}

int main()
{
    long long n,i,odd=0,ans;
    scanf("%lld",&n);
    long long a[n],fromfront[n],fromback[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]&1)
            odd++;
    }
    if(odd==1)
    {
        printf("2");
    }
    else
    {
        fromfront[0]=a[0];
        fromback[n-1]=a[n-1];
        for(i=0;i<(n-1);i++)
        {
            fromfront[i+1]=gcd(fromfront[i],a[i+1]);
        }
        for(i=(n-2);i>=0;i--)
        {
            fromback[i]=gcd(fromback[i+1],a[i]);
        }
        ans=fromback[1];
        if(ans>1 && ans<MAX && (a[0]%ans)!=0)
        {
            printf("%lld",ans);
        }
        else
        {
            ans=fromfront[n-2];
            if(ans>1 && ans<MAX && (a[n-1]%ans)!=0)
            {
                printf("%lld",ans);
            }
            else
            {
                for(i=1;i<(n-1);i++)
                {
                    ans=gcd(fromfront[i-1],fromback[i+1]);
                    if(ans>1 && ans<MAX && (a[i]%ans)!=0)
                    {
                        printf("%lld",ans);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}


/*

You are given a sequence of n integers, a0,a1,...,an-1. Find and print any integer x such that x is divisor of every ai except for exactly one element.
 
Input Format
The first line contains an integer, n, denoting the length of the sequence.
The second line contains n positive space-separated integers describing a0,a1,...,an-1.
 
Constraints
1<=n<=10^5
1<=ai<=10^18
It is guaranteed that a solution exists.
 
Output Format
Print any positive integer denoting x such that x is a divisor of exactly n-1 of the sequence's elements. x must be between 1 and 2*10^18
 
Sample Input 0
4
3 6 18 12
 
Sample Output 0
6
 
Explanation 0
We are given the array [3,6,18,12]. There are two possible answers:

1. x=6 is a divisor of 6, 12, and 18 but not a divisor of 3.
2. x=2 is a divisor of 6, 12, and 18 but not a divisor of 3.
 
Thus, we can print either 6 or 2 as our answer.

*/
