#include "stdio.h"

int main()
{
    unsigned long n,i,a,b,j,prod,tmp;
	scanf("%lu",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lu %lu",&a,&b);
        if(a==0 || b==0)
        {
            printf("0\n");
        }
        else
        {
            if(a==1)
            {
                printf("%lu\n",b%2);
            }
            else
            {
                if(a==b)
                {
                    printf("%lu\n",a);
                }
                else
                {
                    prod=1;
                    tmp=a;
                    while(tmp!=0)
                    {
                        tmp=tmp>>1;
                        prod=prod<<1;
                    }
                    if(b>=prod)
                    {
                        printf("0\n");
                    }
                    else
                    {
                        if(a&(a-1)==0)
                        {
                            printf("%lu\n",a);
                        }
                        else
                        {
                            tmp=a;
                            if(a&1)
                            {
                                a++;
                                tmp &= a;
                            }
                            for(j=(a+2);j<=b;j+=2)
                            {
                                tmp &= j;
                                if(tmp&(tmp-1)==0)
                                {
                                    break;
                                }
                            }
                            printf("%lu\n",tmp);
                        }
                    }
                }
            }
        }
	}
	return 0;
}


/*

Consider two non-negative long integers, a and b, where a<=b. The bitwise AND of all long integers in the inclusive range between a and b can be expressed 
as a & (a+1) & ... & (b-1) & b, where & is the bitwise AND operator.
 
Given n pairs of long integers, ai and bi, compute and print the bitwise AND of all natural numbers in the inclusive range between ai and bi.
 
Input Format
The first line contains a single integer, n, denoting the number of intervals to calculate results for.
Each line i of the n subsequent lines contains two space-separated long integers describing the respective values of ai and bi.
 
Constraints
1<=n<=200
0<=a<=b<2^32

Output Format
For each pair of long integers, print the bitwise AND of all numbers in the inclusive range between ai and bi on a new line.
 
Sample Input
3
12 15
2 3
8 13
 
Sample Output
12
2
8
 
Explanation
There are three pairs to compute results for:

1. a=12 and b=15
   12 & 13 & 14 & 15 = 12, so we print 12 on a new line.

2. a=2 and b=3
   2 & 3 = 2, so we print 2 on a new line.
 
3. a=8 and b=13
   8 & 9 & 10 & 11 & 12 & 13 = 8, so we print 8 on a new line.

*/
