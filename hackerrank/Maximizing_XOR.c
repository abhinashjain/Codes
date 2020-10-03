#include "stdio.h"

int main()
{
	int l,r,max=0,i,j,tmp;
	scanf("%d",&l);
	scanf("%d",&r);
	for(i=l;i<r;i++)
		for(j=i+1;j<=r;j++)
		{
			tmp=i^j;
			if(tmp>max)
				max=tmp;
		}
	printf("%d\n",max);
	return 0;
}


/*

Given two integers: L and R,

find the maximal values of A xor B ∀ L ≤ A ≤ B ≤ R

Input Format
The input contains two lines, L is present in the first line.
R in the second line.

Output Format
The maximal value as mentioned in the problem statement.

Constraints
1 ≤ L ≤ R ≤ 10^3

Sample Input
1
10

Sample Output
15

Explanation
The maximum value can be obtained for A = 5 and B = 10,
1010 xor 0101 = 1111 hence 15. 

*/
