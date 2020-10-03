#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int arr[200000];
	int t,a,sum,s,j,b,i;
	scanf("%d",&t);
	if(t>200000)
	{
		exit(0);
	}
	for(i=0;i<t;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>500000 || arr[i]<1)
		{
			exit(0);
		}
	}
	for(i=0;i<t;i++)
	{
		a=arr[i];
		sum=0;
		s=sqrt(arr[i]);
		for(j=2;j<=s;j++)
		{
			if((a % j)==0)
			{
				b=a/j;
				sum+=b+j;
			}
		}

		if((s*s) == arr[i])
		{
			sum-=s;
		}
		if(arr[i]==1)
		{
			sum=0;
			printf("%d\n",sum);			
		}
		else
		{		
			sum+=1;
			printf("%d\n",sum);
		}
	}	
	return 0;
}

/*
Given a natural number n (1 <= n <= 500000), please output the summation of all its proper divisors.

Definition: A proper divisor of a natural number is the divisor that is strictly less than the number.

e.g. number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.

Input

An integer stating the number of test cases (equal to about 200000), and that many lines follow, each containing one integer between 1 and 500000 inclusive.

Output

One integer each line: the divisor summation of the integer given respectively.

Example

Sample Input:
5
1
2
9
10
20

Sample Output:
0
1
4
8
22
*/
