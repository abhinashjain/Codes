#include "stdio.h"
#include "string.h"

int main() 
{
	int i,c=0;
	char s[100002];
	int a[26]={0};
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
		a[s[i]-97]++;
	for(i=0;i<26;i++)
	{
		if(a[i]%2==1)
		{
			c++;
			if(c==2)
				break;
		}
	}
	if(c==2)
		printf("NO\n");
	else
	{
		if(strlen(s)%2==1)
			printf("YES\n");		
		else
			printf("YES\n");
	}
	return 0;
}

/*
King Robert has 7 kingdoms under his rule. He gets to know from Raven that Dothrakis are to wage a war against him soon. But, he knows Dothrakis need to cross the narrow river to enter his dynasty. There is only one bridge that connects both sides of the river which is sealed by a huge door.
The king wants to lock the door so that the Dothrakis can’t enter. But, to lock the door you need a key that is a palindrome of an anagram of a certain string.

The king has a list of words. For each given word, can you help the king in figuring out if any anagram of it can be a palindrome or not?.

Input Format
A single line which will contain the input string

Constraints
1<=length of string <= 10^5 Each character of the string is a lowercase english alphabet.

Output Format
A single line containing YES/NO in capital letter of english alphabet.

Sample Input : 01

aaabbbb

Sample Output : 01

YES

Explanation
One of the permutations of the given string which is a palindrome is bbaaabb.

Sample Input : 02

cdefghmnopqrstuvw

Sample Output : 02

NO

Explanation
You can verify that no permutation of the given string can be a palindrome.

Sample Input : 03

cdcdcdcdeeeef

Sample Output : 03

YES

Explanation
One of the permutations of the given string which is a palindrome is ddcceefeeccdd.
*/
