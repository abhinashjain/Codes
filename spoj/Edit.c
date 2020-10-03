#include "stdio.h"
#include "string.h"

int main()
{
	int i,k,l;
	char s[1002],t[1002];
	while(scanf("%s",s)!=EOF)
	{
		k=0;
		l=1;
		strcpy(t,s);
		if(isupper(t[0]))
			t[0]=tolower(t[0]);			
		else
			t[0]=toupper(t[0]);
		for(i=1;i<strlen(s);i++)
		{
			if((islower(s[i-1])) && (islower(s[i])))
			{
				s[i]=toupper(s[i]);
				k++;
			}
			else
			{
				if((isupper(s[i-1])) && (isupper(s[i])))
				{
					s[i]=tolower(s[i]);
					k++;
				}
			}		
			if((islower(t[i-1])) && (islower(t[i])))
			{
				t[i]=toupper(t[i]);
				l++;
			}
			else
			{
				if((isupper(t[i-1])) && (isupper(t[i])))
				{
					t[i]=tolower(t[i]);
					l++;
				}
			}		
		}
		if(l>k)
			printf("%d\n",k);
		else
			printf("%d\n",l);
	}
	return 0;
}


/*
As any experienced programmer must know the famous problem of "Edit Distance", however this

problem is considered an “alternating chain” if you have alternately made case sensitive.

Example:

"AaAaAbB" "B" "a" "aBaCdEf"

Alternating chains are considered in our problem.

We only have one operation that is permitted in exchange for a lower or upper case Latin letter.

Given a string giving the minimum number of changes to be considered an alternating chain.

Input

A string with no spaces line containing only uppercase and lowercase letters, one for each line of

maximum length 10 ^ 3 until end of file

 
Output

For each line print the minimum number of changes to the chain is a "chain alternately"

Example

Input:
AaAaB
ABaa
a
aaAa
AAaAaAA
AAAAAa 

Output:
0
2
0
1
2
2
*/
