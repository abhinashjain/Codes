#include "stdio.h"

int main()
{
    int t,n,i,j,f;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        f=0;
        scanf("%d",&n);
        unsigned long long arr[n];
        scanf("%llu",&arr[0]);
        for(j=1;j<n;j++)
        {
            scanf("%llu",&arr[j]);
            arr[j]+=arr[j-1];
        }
        for(j=(n-2);j>=1;j--)
        {
            if((arr[n-1]-arr[j])==arr[j-1])
            {
                f=1;
                break;
            }
        }
        if(f || n==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}


/*

Watson gives Sherlock an array A of length n. Then he asks him to determine if there exists an element in the array such that the sum of the elements on its left is equal to the sum 
of the elements on its right. If there are no elements to the left/right, then the sum is considered to be zero.
Formally, find an i, such that, A0 + A1 + ... + Ai-1 = Ai+1 + Ai+2 + ... + An-1.
 
Input Format
The first line contains T, the number of test cases. For each test case, the first line contains n, the number of elements in the array A. The second line for each test case contains 
n space-separated integers, denoting the array A.
 
Constraints
1<=T<=10
1<=n<=10^5
1<=Ai<=2*10^4
1<=i<=N
 
Output Format
For each test case print YES if there exists an element in the array, such that the sum of the elements on its left is equal to the sum of the elements on its right; otherwise print 
NO.
 
Sample Input 0
2
3
1 2 3
4
1 2 3 3
 
Sample Output 0
NO
YES
 
Explanation 0
For the first test case, no such index exists.
For the second test case, A[0]+A[1]=A[3], therefore index 2 satisfies the given conditions.

*/
