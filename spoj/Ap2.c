#include "stdio.h"
#include "stdlib.h"

int main()
{
	unsigned long long a,n,d,sum,third,thlast;
	int t,i,j;
	scanf("%d",&t);
	if(t>100)
	{
		exit(0);
	}
	for(i=0;i<t;i++)
	{
		scanf("%llu %llu %llu",&third,&thlast,&sum);
		n=(sum*2)/(third+thlast);
		d=(thlast-third)/(n-5);
		a=third-(2*d);
		printf("%llu\n",n);
		j=1;
		while(j<=n)
		{
			printf("%llu ",a);
			a=a+d;
			j++;
		}
	}
	return 0;
}

/*
Arithmatic and geometric Progressions are 2 of the well known progressions in maths.

Arithmatic progression(AP) is a set in which the difference between 2 numbers in constant. for eg, 1,3,5,7,9 .... In this series the difference between 2 numbers is 2.

 

The task here is very simple indeed.

You will be given the 3rd term , 3rd last term and the sum of the series. You need print length of the series & the series.

Input

First line will contain a number indicating the number of test cases.

Each of the following t lines will have 3 number '3term' ,'3Lastterm' and 'sum'

3term  - is the 3rd term in of the series and

3Lastterm  - is the 3rd term in of the series and

sum - is the sum of the series.

Output

For each input of the test case, you need to print 2 lines.

fist line should have 1 value- number of terms in the series.

2nd line of the output should print the series numbers separated by single space.

Example

Input:
1
3 8 55

Output:
10
1 2 3 4 5 6 7 8 9 10

NOTE - In all the test cases all the series elements are positive integers.
The series will have at least 7 elements.
number of test cases <=100.
All the numbers will fit in 64 bits(long long in C)
*/
