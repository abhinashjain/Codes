#include "stdio.h"

int main()
{
    int t,n,i,j,ans;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        int arr[n];
        for(j=0;j<n;j++)
            scanf("%d",&arr[j]);
        if(n&1)
        {
            ans=arr[0];
            for(j=2;j<n;j+=2)
                ans^=arr[j];
            printf("%d\n",ans);
        }
        else
            printf("0\n");
    }
	return 0;
}


/*

Sansa has an array. She wants to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-
ing the values thus obtained. Can you help her in this task?
 
Note : [5,7,5] is contiguous subarray of [4,5,7,5] while [4,7,5] is not.
 
Input Format
First line contains an integer T, number of the test cases.
The first line of each test case contains an integer N, number of elements in the array.
The second line of each test case contains N integers that are elements of the array.
 
Constraints
1<=T<=5
2<=N<=10^5
1<=numbers in array<=10^8

Output Format
Print the answer corresponding to each test case in a separate line.
 
Sample Input
2
3
1 2 3
4
4 5 7 5
 
Sample Output
2
0
 
Explanation
Test case #00:
1 xor 2 xor 3 xor (1 xor 2) xor (2 xor 3) xor (1 xor 2 xor 3) = 2
 
Test case #01:
4 xor 5 xor 7 xor 5 xor (4 xor 5) xor (5 xor 7) xor (7 xor 5) xor (4 xor 5 xor 7) xor (5 xor 7 xor 5) xor (4 xor 5 xor 7 xor 5) = 0

*/
