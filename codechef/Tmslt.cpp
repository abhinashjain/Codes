#include "stdio.h"
#include "vector"
#define mod(num,denom)num-(num/denom)*denom
using namespace std;

int main()
{
	long long b,tmp;
	int n,t,i,j,flag,a,c,d,team;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %lld %d %d",&n,&a,&b,&c,&d);
		if(c==0 && d==0)
			printf("0\n");
		else
		{
			vector<bool> vect(1000000,0);
			vect[d]=1;
			for(j=1;j<n;j++)
			{
				tmp=((a*d)+b)*d+c;
				d=mod(tmp,1000000);
				if(vect[d])
					vect[d]=0;
				else
					vect[d]=1;
			}
			team=flag=0;
			for(j=999999;j>=0;j--)
			{
				if(vect[j]==1)
				{
					if(flag)
					{
						team-=j;
						flag=0;
					}
					else
					{
						team+=j;
						flag=1;
					}
				}
			}
			printf("%d\n",team);
		}
	}
	return 0;
}



/*

Chef wants to split a team of new chef into two teams to play a game. In order to make the split, he first designates two team captains who take alternate turns selecting players for their teams. During each turn, the captain selects a single player for his team. Since each captain wants to make the strongest possible team, he will always select the best available player. The players have strengths as integer number, where higher strength indicate better players. After all the players have been selected, the team strength is computed as the sum of the strengths of the players on that team.

For example, if strengths of 5 players are 5,7,8,4 and 2, then the first captain selects the player with strength 8 for his team, the second captain gets the player with strength 7, the first gets the one with strength 5, the second the one with strength 4, and the last one (strength 2) goes to the first team. The first team now has a total strength 8+5+2=15, and the second team has strength 7+4=11.

Now Chef wants to find the absolute strength difference between the two teams. For the example above the answer is 4(=|15-11|).

But Chef does not know exact strengths of each player. He knows some parameter a, b, c and d and a formula to find the strength of each player. The formula is


S0 = d,

Si = (a * Si-12 + b * Si-1 + c) mod 1000000, for i = 1 to N - 1

There are N players numbering 0 to N-1 and Si is the strength of player i.
Input

First line of the input contains an integer T, number of test cases to follow. Each test consist of single line containing five integers N, a, b, c and d.
Output

For each test case, you have to print a single line containing the absolute strength difference between the two teams.
Constraints

    1 ≤ T ≤ 50
    1 ≤ N ≤ 3000000
    0 ≤ a, b, c, d ≤ 100

Example

Input:
4
1 1 1 1 1
2 1 1 1 1
3 1 2 3 4
4 2 3 4 1

Output:
1
2
763
74896

*/
