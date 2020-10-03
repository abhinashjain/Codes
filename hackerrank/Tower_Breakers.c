#include <stdio.h>

int main()
{
    int t,n,m,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        if(m==1)
        {
            printf("2\n");
        }
        else
        {
            if(n&1)
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}


/*

Two players (numbered 1 and 2) are playing a game of Tower Breakers! The rules of the game are as follows:
 
Player 1 always moves first, and both players always play optimally.
Initially there are N towers, where each tower is of height M.
The players move in alternating turns. In each turn, a player can choose a tower of height X and reduce its height to Y, where 1<=Y<X and Y evenly divides X.
If the current player is unable to make any move, they lose the game.
 
Given the values of N and M, can you determine who will win? If the first player wins, print 1; otherwise, print 2.
 
Input Format
The first line contains a single integer, T, denoting the number of test cases.
Each of the T subsequent lines describes a test case in the form of 2 space-separated integers describing the respective values for N and M.
 
Constraints
1<=T<=100
1<=N,M<=10^6
 
Output Format
For each test case, print a single integer (i.e., either 1 or 2) denoting the winner on a new line.
 
Sample Input
2
2 2
1 4
 
Sample Output
2
1
 
Explanation
We'll refer to player 1 as P1 and player 2 as P2
 
In the first test case, P1 chooses one of the two towers and reduces it to 1. Then P2 reduces the remaining tower to a height of 1. As both towers now have height 1, P1 cannot make a 
move so P2 is the winner and we print 2 on a new line.

In the second test case, there is only one tower of height 4. P1 can reduce it to a height of either 1 or 2, but P1 chooses 1 as both players always choose optimally. Because P2 has 
no possible move, P1 wins and we print 1 on a new line.

*/
