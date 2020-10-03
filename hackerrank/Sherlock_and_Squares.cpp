#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
	int t,a,b;
	long long i;
	vector<long long> vect;
	vector<long long>::iterator low,up;
	for(i=1;i<100001;i++)
		vect.push_back(i*i);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&a,&b);
		low=lower_bound(vect.begin(),vect.end(),a);
		up=upper_bound(vect.begin(),vect.end(),b);
		printf("%d\n",(up-vect.begin())-(low-vect.begin()));
	}
	return 0;
}


/*

Watson gives two integers A & B to Sherlock and asks if he can count the number of square integers between A and B (both inclusive).

A square integer is an integer which is the square of any integer. For example, 1, 4, 9, 16 are some of the square integers as they are squares of 1, 2, 3, 4 respectively.

Input Format
First line contains T, the number of testcases. T test cases follow, each in a newline.
Each testcase contains two space separated integers denoting A and B.

Output Format
For each testcase, print the required answer in a new line.

Constraints
1 ≤ T ≤ 100
1 ≤ A ≤ B ≤ 10^9

Sample Input
2
3 9
17 24

Sample output
2
0

Explanation
In the first testcase, 4 and 9 are the square numbers.
In second testcase no square numbers exist between 17 and 24 (both inclusive). 

*/
