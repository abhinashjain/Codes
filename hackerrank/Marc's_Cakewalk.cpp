#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    long long n,i,sum=0;
    scanf("%lld",&n);
    long long arr[n];
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    for(i=0;i<n;i++)
        sum+=(arr[n-1-i]*(1L<<i));
    printf("%lld\n",sum);
    return 0;
}


/*

Marc loves cupcakes, but he also likes to stay fit. He eats n cupcakes in one sitting, and each cupcake i has a calorie count, ci. After eating a cupcake with c calories, he must 
walk at least 2^j * c (where j is the number cupcakes he has already eaten) miles to maintain his weight.

Given the individual calorie counts for each of the n cupcakes, find and print a long integer denoting the minimum number of miles Marc must walk to maintain his weight. Note that he
can eat the cupcakes in any order.

Input Format
The first line contains an integer, n, denoting the number of cupcakes.
The second line contains n space-separated integers describing the respective calorie counts of each cupcake, c0,c1,...,cn-1.

Constraints
1<=n<=40
1<=ci<=1000

Output Format
Print a long integer denoting the minimum number of miles Marc must walk to maintain his weight.

Sample Input 0
3
1 3 2

Sample Output 0
11

Explanation 0
Let's say the number of miles Marc must walk to maintain his weight is miles. He can minimize miles by eating the n=3 cupcakes in the following order:

1. Eat the cupcake with c1=3 calories, so miles=0+(3*2^0)=3.
2. Eat the cupcake with c2=2 calories, so miles=3+(2*2^1)=7.
3. Eat the cupcake with c0=1 calories, so miles=7+(1*2^2)=11.

We then print the final value of miles, which is 11, as our answer.

*/
