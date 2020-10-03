#include <stdio.h>

int main()
{
	int t,n,a,b,c,d,i,j,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{		
		scanf("%d",&n);
		scanf("%d %d",&a,&b);
		k=0;
		for(j=0;j<n;j++)
		{		
			scanf("%d %d",&c,&d);
			c=c-a;
			c=(c<0)?0-c:c;
			d=d-b;
			d=(d<0)?0-d:d;
			k += c+d;
		}
		printf("%d\n",(2*k));
	}
	return 0;
}

/*

James Moriarty planted few bombs all over the city. But sadly there is only one bomb defusing squad, and is at a fixed position (X,Y). Sherlock Holmes was able to find out the positions of all the bombs. So all the bombs are to be disarmed in order to save the city. Since this is a very dangerous task thus no body volunteered.


Sherlock is initially at position (X,Y) and can carry only one bomb at a time. He has to bring all the bombs to the bomb defusing squad. Obviously he wants to do this task as soon as possible.


Given the position of the Squad and position of all the bombs, you need to tell the minimum distance that Sherlock Holmes has to travel to save the city.
Input

First line contains test cases T<=400.

Then first line of each test case tells the no. of bombs N ( 3<=N <=1500) in the city.

Next line contain the position of squad X Y ( X,Y <=100).

Next N lines denotes the position of bombs- xi yi (xi,yi<=100).
Output

For each test case output the minimum distance that Sherlock Holmes will travel.

Note:
Bomb Squad is fixed and can not move.
Initially Sherlock Holmes is standing with the squad.
All the positions are integers.
Minimum Distance between two points x1 y1 and x2 y2 is | x1-x2 | + | y1-y2 |.

Example

Input:
1
3
3 4
5 6
2 1
2 3

Output:
20

*/
