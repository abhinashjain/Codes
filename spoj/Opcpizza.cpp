#include "stdio.h"
#include "algorithm"
using namespace std;

int main()
{
	int t,n,m,i,j,k,temp;
	int cnt;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		cnt=0;
		scanf("%d %d",&n,&m);
		int arr[n];
		for(j=0;j<n;j++)
			scanf("%d",&arr[j]);
		sort(arr,arr+n);
		for(j=0;j<n;j++)
			if(binary_search(arr,arr+n,m-arr[j]))
				cnt++;
		printf("%d\n",cnt/2);
	}
	return 0;
}


/*

Singham and his friends are fond of pizza. But this time they short of money. So they decided to help each other.They all decided to bring pizza in pairs. Our task is to find the total number of pairs possible which can buy pizza, given the cost of pizza. As pizza boy dont have any cash for change, if the pair adds upto more money than required, than also they are unable to buy the pizza. Each friend is guaranteed to have distinct amount of money. As it is Singham's world, money can also be negative ;).


Input:
The first line consist of t(1<=t<=100) test cases.In the following 2*t lines, for each test case first there is n and m, where n(1<=n<=100000) is number of Singham's friend and m is the price of pizza.The next line consist of n integers, seperated by space, which is the money each friend have. 

The value of m and money is within the limits of int in C,C++.

Output: 
A single integer representing the number of pairs which can eat pizza.

Example
Sample Input:
2
4 12
9 -3 4 3
5 -9
-7 3 -2 8 7

Sample Output:
1
1

*/
