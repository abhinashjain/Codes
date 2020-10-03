#include "stdio.h"

int main()
{
    int i,j,k,t,n,max;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        int arr[n+1][n+1];
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=n;k++)
            {
                arr[j][k]=0;
            }
        }
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=j;k++)
            {
                scanf("%d",&arr[j][k]);
            }
        }
        for(j=n-1;j>0;j--)
        {
            for(k=j;k>0;k--)
            {
                max=arr[j+1][k];
                if(max<arr[j+1][k+1])
                {
                    max=arr[j+1][k+1];
                }
                arr[j][k]+=max;
            }
        }
        printf("%d\n",arr[1][1]);
    }
	return 0;
}


/*

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23. The path is denoted by numbers in bold.
 
3
74
246
8593
 
That is, 3+7+4+9=23.
 
Find the maximum total from top to bottom of the triangle given in input.
 
Input Format
First line contains T, the number of testcases. For each testcase:
First line contains N, the number of rows in the triangle.
For next N lines, i'th line contains i numbers.
 
Output Format
Print the required answer for each testcase on a new line.
 
Constraints
1<=T<=10
1<=N<=100
Each element of triangle lies between 0 and 100(both inclusive).
 
Sample Input
2
4
3
7 4
2 4 6
8 5 9 3
4
3
7 4
2 4 6
8 5 9 3
 
Sample Output
23
23

*/