#include <stdio.h>
#include <stdlib.h>
#include <string.h>
     
int main()
{
	char a[30],b[30],c[30],p,e;
	char * m;
	int t,i,z,y,x;
	scanf("%d",&t);
	for(i = 0; i < t; i++)
    	{
		scanf("%s %c %s %c %s", a,&p,b,&e,c);
    		m = strstr (a,"machula");
		if(m == NULL)
		{
			m = strstr (b,"machula");
   			x = atoi(a);
			if(m == NULL)
			{
				y = atoi(b);
				z = x + y;
			}
			else
			{
				z = atoi(c);
    				y = z - x;
    			}
    		}
    		else
    		{
    			y = atoi(b);
    			z = atoi(c);
    			x = z - y;
    		}
    		printf("\n%d %c %d %c %d",x,p,y,e,z);
	}
	return 0;
} 

/*

Jimmy is a hard-working pupil in his second year at primary school. Recently he decided to convert all his notes into an electronic version. Sadly, he found that his math notes were full of ink blots.

He scanned the notes and sent them through his own OCR package (yes, he coded it all by himself at the age of 8). The OCR package replaced all ink blots by the string "machula".
Problem specification

You are given Jimmy's notes, processed by the OCR. They contain simple math exercises, which were used to practice addition on positive integers. Your task is to recover the damaged part of the notes.
Input specification

The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.

Each test case consists of exactly one line. The line represents an equation of the form "number + number = number", where each number is a positive integer. One part of the equation will be replaced by the string "machula". The string always covers a contiguous non-empty sequence of digits, possibly even an entire number. You may assume that for each equation in the input there will be exactly one way to fill in the missing digits.
Output specification

For each test case, the output shall contain one line of the form "number + number = number". The line must represent the equation from that test case with all missing digits filled in.
Example
Input:

3

23 + 47 = machula

3247 + 5machula2 = 3749

machula13 + 75425 = 77038

Output:

23 + 47 = 70
3247 + 502 = 3749
1613 + 75425 = 77038

Note: int in C++/C/Java or longint in Pascal is enough.

*/
