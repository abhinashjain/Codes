#include "stdio.h"
#include "string.h"

int main()
{
	int t,i,j,k,l,len;
	char s[50002],z,v[5]="uaeio",c[21]="zbcdfghjklmnpqrstvwxy";
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",s);
		int arr[26]={0};
		len=strlen(s);
		for(j=0;j<len;j++)
		{
			z=s[j];
			if(z=='a' || z=='e' || z=='i' || z=='o' || z=='u')
			{
				if(z=='u')
					l=5;
				else
				{
					for(l=1;l<5;l++)
					{
						if(z==v[l])
							break;
					}
				}
				k=(arr[z-97]*5+l)%21;
				s[j]=c[k];
			}
			else
			{
				if(z=='z')
					l=21;
				else
				{
					for(l=1;l<21;l++)
					{
						if(z==c[l])
							break;
					}
				}
				k=(arr[z-97]*21+l)%5;
				s[j]=v[k];
			}
			arr[z-97]++;
		}
		printf("%s\n",s);
	}	
	return 0;
}




/*
Marko is going to write a secret letter to a friend. He thought it is better to encrypt letter so that no other person can read it. After long thought he came up with an encryption scheme which was lame but he thought it will work anyways.

To encrypt a text he first wrote two infinite strings of characters first string consists only of vowels and second string consists of consonants only.

aeiouaeiouaeiouaeiouaeiou....................
bcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyz...
 
Following is the scheme for encryption :
1. let c be any character to be encrypted.
2. let k be the count of number of times c character occured in text to be encrypted till now.
3. first find which of two infinite string contains that character.
4. then look for kth occurence of that character in that string.
5. replace charcter c by corresponding character in second string.

For example encrypted text of "baax" will be "abho".
Input

First line of input will contains t, number of test cases. Then t test case follows each test case in a line. Each test case will be a string of small latin alphabets. Length of string will be less than 5*10^4
Output

For each test case print encrpyted text.

Sample :

Input:

2
baax
aaa

Output:

abho
bhn
*/
