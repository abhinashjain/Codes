#include "stdio.h"
#include "string.h"
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
	int n,q,rc,x,i;
	char z[10];
	scanf("%d %d",&n,&q);	
	//vector< vector<int> > server( n, vector<int>(n) );
	int row[n],col[n];
	for (i = 0; i < n; i++)
	{
		row[i]=0;
		col[i]=0;
	}
	for(i=0;i<q;i++)
	{
		scanf("%s %d %d",z,&rc,&x);
		rc--;
		if(strcmp(z,"RowAdd")==0)
		{
			row[rc] += x;
		}
		if(strcmp(z,"ColAdd")==0)
		{
			col[rc] += x;
		}		
	}
	sort(row,row+n);
	sort(col,col+n);
	printf("%d\n",(row[n-1]+col[n-1]));
	return 0;
}

/*
You are given an N × N grid initially filled by zeros. Let the rows and columns of the grid be numbered from 1 to N, inclusive. There are two types of operations can be applied to the grid:

    RowAdd R X: all numbers in the row R should be increased by X.
    ColAdd C X: all numbers in the column C should be increased by X.

Now after performing the sequence of such operations you need to find the maximum element in the grid.
Input

The first line of the input contains two space separated integers N and Q denoting the size of the grid and the number of performed operations respectively. Each of the following Q lines describe an operation in the format described above.
Output

Output a single line containing the maximum number at the grid after performing all the operations.
Constraints

    1 ≤ N ≤ 314159
    1 ≤ Q ≤ 314159
    1 ≤ X ≤ 3141
    1 ≤ R, C ≤ N

Example

Input:
2 4
RowAdd 1 3
ColAdd 2 1
ColAdd 1 4
RowAdd 2 1

Output:
7

Explanation

The grid changes as follows:

00  33  34  74  74
00  00  01  41  52

The maximum number in the final grid is 7.
*/
