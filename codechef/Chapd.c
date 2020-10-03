#include "stdio.h"
#define mod(num,denom)num-(num/denom)*denom

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    if (a==0 || b == 0)
        return a+b;
    else
        return gcd(b, a % b);
}

int main()
{
    int t,i;
    unsigned long long a,b,gcdret;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%llu %llu",&a,&b);
        if((a&1)!=0 && (b&1)==0)
            printf("No\n");
        else
            if(mod(a,b)==0)
                printf("Yes\n");
            else
            {
                gcdret=0;
                while(1)
                {
                    gcdret=gcd(a,b);
                    if(gcdret==1)
                        break;
                    a=gcdret;
                    b=b/gcdret;
                }
                if(b==1)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
    }
    return 0;
}


/*

You are given two positive integers – A and B. You have to check whether A is divisible by all the prime divisors of B.
 
Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
For each test case, you are given two space separated integers – A and B.
 
Output
For each test case, output "Yes" (without quotes) if A contains all prime divisors of B, otherwise print "No".

Constraints
1 ≤ T ≤ 10^4
1 ≤ A, B ≤ 10^18
 
Subtasks
Subtask 1 (20 points):1 ≤ B ≤ 10^7
Subtask 2 (30 points):1 ≤ A ≤ 10^7
Subtask 3 (50 points): Original constraints
 
Example
Input:
3
120 75
128 16
7 8
 
Output:
Yes
Yes
No
 
Explanation
Example case 1. In the first case 120 = 2^3*3*5 and 75 = 3*5^2. 120 is divisible by both 3 and 5. Hence, we will print "Yes"
Example case 2. In the second case both 128 and 16 are powers of two. Hence, the answer is "Yes"
Example case 3. In the third case 8 is power of two and 7 is not divisible by 2. So, the answer is "No"
 
*/