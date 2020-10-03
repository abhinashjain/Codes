#include "stdio.h"
#include "stdio.h"

int main()
{
	unsigned long long t,n,i,a,b,c;
	scanf("%llu",&t);
	for(i=0;i<t;i++)
	{
		scanf("%llu",&n);
		a = n + 2;
		b = (n * 2) + 1;
		c = (n * a * b) / 8;
		printf("%llu\n",c);
	}
	return 0;
}

/*f(n) = n * (n + 2) * (2n + 1) / 8
We define the LEVEL of a triangle as in the following image in folder:
Task: Your task is very easy. All you have to do is to count all triangles in the biggest one (Level N).

Input

The first line of the input contains an integer T (T ≤ 10000) - the number of test cases and T lines follow. Each line contains an integer N (1 ≤ N ≤ 106) which is the level of the triangle in that test case.

Output

For each test case, you should write a seperate line: the number of triangles in the biggest one (Level N). (All answers will fit within the range of a 64-bit integer)

Example

Input:
3
1
2
3

Output:
1
5
13

*/
