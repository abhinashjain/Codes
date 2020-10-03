#include "stdio.h"

int main()
{
    int t,n,i,j,k,cnt;
    char ch;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        char grid[n][n];
        for(j=0;j<n;j++)
        {
            scanf("%s",grid[j]);
        }
        for(k=0;k<n;k++)
        {
            do
            {
                cnt=0;
                for(j=1;j<n;j++)
                {
                    if(grid[k][j-1]>grid[k][j])
                    {
                        ch=grid[k][j-1];
                        grid[k][j-1]=grid[k][j];
                        grid[k][j]=ch;
                        cnt=1;
                    }
                }
            } while(cnt);
        }
        for(k=0;k<n;k++)
        {
            for(j=1;j<n;j++)
            {
                if(grid[j-1][k]>grid[j][k])
                {
                    cnt=1;
                    break;
                }
            }
            if(cnt)
                break;
        }
        if(cnt)
            printf("NO\n");
        else
            printf("YES\n");
    }
	return 0;
}


/*

Given a squared sized grid G of size N in which each cell has a lowercase letter. Denote the character in the ith row and in the jth column as G[i][j].
You can perform one operation as many times as you like: Swap two column adjacent characters in the same row G[i][j] and G[i][j+1] for all valid i,j.
Is it possible to rearrange the grid such that the following condition is true?
 
G[i][1] <= G[i][2] <= ... <= G[i][N] for 1<=i<=N and
G[1][j] <= G[2][j] <= ... <= G[N][j] for 1<=j<=N
 
In other words, is it possible to rearrange the grid such that every row and every column is lexicographically sorted?
 
Note: c1<=c2 , if letter c1 is equal to c2 or is before c2 in the alphabet.
 
Input Format
The first line begins with T, the number of testcases. In each testcase you will be given N. The following N lines contain N lowercase english alphabet each, describing the grid.
 
Constraints
1<=T<=100
1<=N<=100
Gij will be a lower case letter
 
Output Format
Print T lines. On the ith line print YES if it is possible to rearrange the grid in the ith testcase or NO otherwise.
 
Sample Input
1
5
ebacd
fghij
olmkn
trpqs
xywuv
 
Sample Output
YES
 
Explanation
The grid in the first and only testcase can be reordered to
 
abcde
fghij
klmno
pqrst
uvwxy
 
This fulfills the condition since the rows 1, 2, ..., 5 and the columns 1, 2, ..., 5 are all lexicographically sorted.

*/
