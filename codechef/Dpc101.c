#include "stdio.h"

int main()
{
	int a,b,c,d,e,n;
	scanf("%d %d",&a,&b);
	while((a!=0) || (b!=0))
	{
		e=0;
		n=0;
		while((a>0) || (b>0))
		{
			c = a%10;
			d = b%10;
			a = a/10;
			b = b/10;
			e += c+d;
			e = e/10;
			if(e == 1)
				n++;
		}
		if(n > 0)
		{
			if(n > 1)
				printf("%d carry operations.\n",n);
			else
				printf("%d carry operation.\n",n);
		}
		else
			printf("No carry operation.\n");
		scanf("%d %d",&a,&b);
	}
	return 0;
}

/*
Children are taught to add multi-digit numbers from right-to-left one digit at a time. Many find the "carry" operation - in which 1 is carried from one digit position to be added to the next - to be a significant challenge.  Your job is to count the number of carry operations for each of addition problem so that educators may assess their difficulty.

 

Input

Each line of input contains two unsigned integers less than 10 digits.

The last line of input contains 0 0.

 

Output

For each line of input except the last output the number of carry operations that would result from adding the two numbers, in the format shown below.

 

Sample Input

123 456

555 555

123 594

0 0

Sample Output

No carry operation.

3 carry operations.

1 carry operation.
*/
