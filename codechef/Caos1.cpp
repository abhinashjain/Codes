#include "stdio.h"
#include "iostream"
using namespace std;

int main()
{
	int i,r,c,t,j,k,cnt;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		cnt=0;
		scanf("%d %d",&r,&c);
		char arr[r][c];
		for(j=0;j<r;j++)
			for(k=0;k<c;k++)		
				cin >> arr[j][k];
		for(j=2;j<(r-2);j++)
		{
			for(k=2;k<(c-2);k++)
			{
				if(arr[j][k]=='^' && arr[j-1][k]=='^' && arr[j-2][k]=='^' && arr[j][k-1]=='^' && arr[j][k-2]=='^' && arr[j+1][k]=='^' && arr[j+2][k]=='^' && arr[j][k+1]=='^' && arr[j][k+2]=='^')
				{
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;            
}



/*

Past

In the year of 2048, the Virtual Reality Massively Multiplayer Online Role-Playing Game (VRMMORPG), Code Art Online (CAO), is released. With the Chef Gear, a virtual reality helmet that stimulates the user's five senses via their brain, players can experience and control their in-game characters with their minds.

On August the 2nd, 2048, all the players log in for the first time, and subsequently discover that they are unable to log out. They are then informed by Code Master, the creator of CAO, that if they wish to be free, they must reach the second stage of the game.

Kirito is a known star player of CAO. You are to help him log out.

Present

Stage 1

A map is described by a 2D grid of cells. Each cell is either a # or a ^. # denotes a wall. A monster exists in a cell, if the cell is not a wall and the cell is a centre of Prime-Cross (CPC).

A cell X is said to be a CPC if it satisfies the following property:

    Let L be the number of contiguous ^ to the left of X, in the same row as X
    R be the number of contiguous ^ to the right of X, in the same row as X
    T be the number of contiguous ^ to the top of X, in the same column as X
    B be the number of contiguous ^ to the bottom of X, in the same column as X

if there exists a prime number P, where P ≤ minimum of [L, R, T, B], then X is said to be a CPC.

Note: While computing L, R, T, B, for a cell X you should not count the ^ of the cell X

Given a map, you are to tell Kirito the number of cells where monsters exist.

Future

If you are done with this task, go help Kirito with Stage 2 :-)
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. Each case start with a line containing two space separated integers R, C, denoting the number of rows and columns in the map respectively. Followed by R lines containing C characters each, describing the map.
Output

For each test case, output a single line containing the number of cells where monsters exist.
Constraints

    1 ≤ T ≤ 100
    1 ≤ R ≤ 50
    1 ≤ C ≤ 50

Example

Input:
2
5 5
^^^^^
^^^^^
^^^^#
^^^^^
^^^^^
5 7
^^#^^^^
^^#^#^#
#^^^^^^
^^#^^#^
^^^^^^^

Output:
0
1

 
Explanation

Example case 1. There is no cell which for which minimum of L, R, T, B is greater than some prime P.

Example case 2. The cell at [3, 4], (1-based indexing) is the only CPC

*/
