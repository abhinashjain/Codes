#include "stdio.h"

int main()
{
    int i,cnt=0;
    unsigned long long n,ans=1;
    scanf("%llu",&n);
    while(n!=0)
    {
        if(n%2==0)
            cnt++;
        n/=2;
    }
    for(i=0;i<cnt;i++)
        ans*=2;
    printf("%llu",ans);
	return 0;
}


/*
 
Given an integer, n, find each x such that:

0<=x<=n
n+x = n xor x

where xor denotes the bitwise XOR operator. Then print an integer denoting the total number of x's satisfying 
the criteria above.
 
Input Format
A single integer, n.
 
Constraints
0<=n<=10^15
 
Subtasks
0<=n<=100 for 60% of the maximum score.
 
Output Format
Print the total number of integer x's satisfying both of the conditions specified above.
 
Sample Input 0
5
 
Sample Output 0
2
 
Explanation 0
For n=5, the x values 0 and 2 satisfy the conditions:
5+0 = 5 xor 0 = 5
5+2 = 5 xor 2 = 7
Thus, we print 2 as our answer.
 
Sample Input 1
10
 
Sample Output 1
4
 
Explanation 1
For n=10, the x values 0, 1, 4, and 5 satisfy the conditions:
10+0 = 10 xor 0 = 10
10+1 = 10 xor 1 = 11
10+4 = 10 xor 4 = 14
10+5 = 10 xor 5 = 15
Thus, we print 4 as our answer.
 
*/
