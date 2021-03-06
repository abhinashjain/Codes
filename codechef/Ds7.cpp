#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	int col,l,i,j,z,t,s;
	char a[300],d;
	scanf("%d",&t);
	for(s=0; s<t; s++)
	{
		scanf("%d",&col);
		z=0;
		scanf("%s",a);
		l=strlen(a)-1;
		for(i=col;i<=l;i=i+(col*2))
		{
			z=i+col-1;
			for(j=z;j>((i+z)/2);j--)
			{
				d=a[z-j+i];
				a[z-j+i]=a[j];
				a[j]=d;
			}
		}
		for(i=0;i<col;i++)
		{
			for(j=i;j<=l;j=j+col)
			{
				printf("%c",a[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

/*

Michal Scofield and Lincon burrow are two brothers. By a murder allegation Lincon Burrow was sentenced to jail. Michal Scofield some how came to know that his brother is not guilty and he don’t have time to file case against the allegations as his brother is going to sit on death chair soon enough. So he made a plan for Prison break before handing himself over to police in a robbery allegation he made tattoos on his whole body a way of encrypting messages. He decided secretly on the number of columns and write the message (letters only) down the columns, padding with extra random letters so as to make a rectangular array of letters. For example, if the message is “There’s no place like home on a snowy night” and there are five columns, Michal would write down

t o i o y
h p k n n
e l e a i
r a h s g
e c o n h
s e m o t
n l e w x

Note that Michal Scofield includes only letters in between the tattoos and writes them all in lower case. In this example, Michael used the character ‘x’ to pad the message out to make a rectangle, although he could have used any letter. Michael then tattooed them by writing the letters in each row, alternating left-to-right and right-to-left. So, the above would be encrypted as

toioynnkpheleaigshareconhtomesnlewx

At the time of the break he forget something about encryption .Your job is to recover for Michal the original message (along with any extra padding letters) from the encrypted one.
Input

The first line have a integer T number of test cases. Input for each test case will consist of two lines. The first line will contain an integer c indicating the number of columns used. The next line is a string of up to 200 lower case letters.
Output

Each input set should generate one line of output, giving the original plaintext message, with no spaces.
Constraints

1&ltT&lt20	
2&ltC&lt20

Sample Input

2
5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss

Output:

theresnoplacelikehomeonasnowynightx
thisistheeasyoneab

*/
