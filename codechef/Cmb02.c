#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int j,r,z,t,i;
	char k[10],c[10];
	scanf("%d",&t);
	for(i = 0; i < t; i++)
	{
		scanf("%s", k);
		do
		{
			memset (c, 0,10);
			r=strlen(k)-1;
			if(k[r] != '9')
			{
				k[r]=k[r]-'0'+'1';
			}
			else
			{
				for(j=r;j>=0;j--)
				{
					if(k[j] == '9')
					{
						k[j]='0';
					}
					else
					{
						k[j]=k[j]-'0'+'1';
						break;
					}
				}
				z = atoi(k);
				if(z == 0)
				{
					for(j=r;j>=0;j--)
					{	
						k[j+1]=k[j];
					}	
					k[0]='1';
					r=strlen(k)-1;			
				}
			}
			for(j=r;j>=0;j--)
			{	
				if(k[r-j] != k[j])
					break;
				c[r-j]=k[j];
			}
		}while ((strcmp(c, k)) != 0);
		printf("\n%s",c);
	}
	return 0;
}

/*
A positive integer is called a palindrome if its representation in the decimal system is the same when read from left to right and from right to left. For a given positive integer K of not more than 5 digits, write the value of the smallest palindrome larger than K to output. Numbers are always displayed without leading zeros.
Input

The first line contains integer t, the number of test cases. Integers K are given in the next t lines.
Output

For each K, output the smallest palindrome larger than K.
Example

Input:
3
1
5
808

Output:
2
6
818
*/
