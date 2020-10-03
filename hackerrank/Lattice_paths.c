#include "stdio.h"

int main()
{
    int i,j,t,n,m;
    unsigned long long paths[501][501];
    for(i=0;i<501;i++)
    {
        paths[0][i]=1;
        paths[i][0]=1;
    }
    for(i=1;i<501;i++)
    {
        for(j=1;j<501;j++)
        {
            paths[i][j]=(paths[i][j-1]+paths[i-1][j])%1000000007;
        }
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        printf("%llu\n",paths[n][m]);
    }
	return 0;
}



/*
 
Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
Image: Lattice_paths.gif

How many such routes are there through a NxM grid? As number of ways can be very large, print it modulo 10^9+7.
 
Input Format
The first line contains an integer T , i.e., number of test cases.
Next T lines will contain integers N and M.
 
Output Format
Print the values corresponding to each test case.
 
Constraints
1 <= T <= 10^3
1 <= N <= 500
1 <= M <= 500
 
Sample Input
2
2 2
3 2
 
Sample Output
6
10
 
*/