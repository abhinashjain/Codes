#include "stdio.h"

int main()
{
	int t,n,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
        if(n%7==0 || n%7==1)
            printf("Second\n");
        else
            printf("First\n");
	}
	return 0;
}


/*

Two players (numbered 1 and 2) are playing a game with n stones. Player 1 always plays first, and the two players move in alternating turns. The game's rules are as follows:
 
In a single move, a player can remove either 2, 3, or 5 stones from the game board.
If a player is unable to make a move, that player loses the game.
 
Given the number of stones, find and print the name of the winner (i.e., First or Second) on a new line. Each player plays optimally, meaning they will not make a move that causes 
them to lose the game if some better, winning move exists.
 
Input Format
The first line contains an integer, T, denoting the number of test cases.
Each of the T subsequent lines contains a single integer, n, denoting the number of stones in a test case.
 
Constraints
1<=T<=100
1<=n<=100

Output Format
On a new line for each test case, print First if the first player is the winner; otherwise, print Second.
 
Sample Input
8
1
2
3
4
5
6
7
10
 
Sample Output
Second
First
First
First
First
First
Second
First
 
Explanation
In the sample, we have T=8 testcases.
We'll refer to our two players as P1 and P2.
 
If n=1, P1 can't make any moves and loses the game (i.e., the P2 wins and we print Second on a new line).
If n=2, P1 removes 2 stones in their first move and wins the game, so we print First on a new line.
If n=3, P1 removes 2 stones in their first move, leaving 1 stone on the board. Because P2 is left with no available moves, P1 wins and we print First on a new line.
If n=4, P1 removes 3 stones in their first move, leaving 1 stone on the board. Because P2 has no available moves, P1 wins and we print First on a new line.
If n=5, P1 removes all 5 stones from the game board. Because P2 is left with no available moves, P1 wins and we print First on a new line.
If n=6, P1 removes 5 stones in their first move, leaving 1 stone on the board. Because P2 has no available moves, P1 wins and we print First on a new line.
If n=7, P1 can make any of the following three moves:
 Remove 2 stones, leaving 5 stones on the board. P2 then removes 5 stones. Because P1 has no available moves, P2 wins.
 Remove 3 stones, leaving 4 stones on the board. P2 then removes 3 stones, leaving 1 stone left on the board. Because P1 has no available moves, P2 wins.
 Remove 5 stones, leaving 2 stones on the board. P2 then removes the 2 remaining stones. Because P1 has no available moves, P2 wins.
Because all possible moves result in P2 winning, we print Second on a new line.
 
If n=10, P1 can remove either 2 or 3 stones to win the game, so we print First on a new line. Recall that each player moves optimally, so P1 will not remove 5 stones because doing so 
would cause P1 to lose the game.

*/
