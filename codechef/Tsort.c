#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int t,i;
	int inp[1000000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&inp[i]);
	}
	sort(inp,inp+t);
	for(i=0;i<t;i++)
	{
		printf("%d\n",inp[i]);
	}
	return 0;
}

/*
Given the list of numbers, you are to sort them in non decreasing order.
Input

t – the number of numbers in list, then t lines follow [t <= 10^6].

Each line contains one integer: N [0 <= N <= 10^6]
Output

Output given numbers in non decreasing order.
Example

Input:

5
5
3
6
7
1

Output:

1
3
5
6
7

*/
