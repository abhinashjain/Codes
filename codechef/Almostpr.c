#include "stdio.h"
#include "math.h"

int main()
{
	long long t,i,j,k,z,p;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&p);
		if(p==1)
			printf("NO\n");
		else
		{
			if((p!=4) && ((p%2)==0))
				printf("NO\n");
			else
			{
				j=sqrt(p);
				if((j*j)==p)
				{
					z=0;
					for(k=2;k*k<=j;k++)
					{
						if(j%k==0)
						{
							z=1;
							break;
						}
					}
					if(z==1)
						printf("NO\n");
					else
						printf("YES\n");
				}
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}

/*

Chef Polo is experimenting with Prime Numbers. He can quickly tell whether a number is prime or not. His friend Palin knows about it, so he twists the question.
Palin challenges his friend to check whether a number P is "almost prime" or not.

The number P is said to be almost prime if it has exactly 3 distinct divisors.

A number d is said to be divisor of P if P is divisible by d.


Chef Polo is quite intelligent but currently he is busy with preparing delicious dishes. So he wants your help.
Input

First line Contains an integer T, the no of test cases.

Each of next T lines contain a single integer P, the number Palin asks to check.
Output

For each test case, output a string "YES" if the number P is almost prime. Otherwise output "NO"
Constraints

    1 ≤ T ≤ 10^5
    1 ≤ P ≤ 10^12

Example

Input:
4
2
4
7
10

Output:
NO
YES
NO
NO
*/
