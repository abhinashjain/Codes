#include "vector"
using namespace std;

class PingPongQueue
{
    public:
        vector<int> whoPlaysNext(vector<int> skills, int n, int k)
        {
            int i,x=0,y=1,val1,val2,winner,looser;
            vector<int> answer;
            vector<int>::iterator iter;
            int arr[51]={0};
            for(i=0;i<k;i++)
            {
                val1=skills[x];
                val2=skills[y];
                if(val1<val2)
                {
                    looser=val1;
                    winner=val2;
                    x=y;
                    y=x+1;
                }
                else
                {
                    winner=val1;
                    looser=val2;
                    y=y+1;
                }
                arr[looser]=0;
                arr[winner]++;
                skills.push_back(looser);
                if(arr[winner]==n)
                {
                    skills.push_back(winner);
                    arr[winner]=0;
                    x=y;
                    y=x+1;
                }
            }
            answer.push_back(looser);
            answer.push_back(winner);
            return answer;
        }
};


/*

This task is about a group of people who like to play ping pong. All games of ping pong mentioned in this task are one-on-one games.

You are given a skills. Each element of skills is the skill level of one person in the group. The skill levels are all distinct. Whenever two people play a game of ping pong, the
one with the higher skill level always wins.

All people in the group would like to play but they only have a single table. Therefore, only two people can play at any given time.

There will be a sequence of games, numbered starting from 1. Game 1 will be played by the players who correspond to skills[0] and skills[1]. All the remaining people will form a 
queue, in the order in which they are given in skills. After each game the following things will happen, in order:
1. The person who lost the game leaves the table and goes to the end of the queue.
2. If the person who won the game has already won N games in a row, they also leave the table and they go to the end of the queue (behind the person who lost the last game).
3. While there are fewer than two people at the table, the first person in the queue leaves the queue and goes to the table.
4. The two people at the table play the next game.

 You are given the skills, the N, and an K. Return the two-element { L, W }, where L and W are the skills of the loser and the winner of game K, in this order.

Constraints
- skills will contain between 2 and 50 elements, inclusive.
- Each element of skills will be between 1 and 50, inclusive.
- All elements of skills will be distinct.
- N will be between 1 and 100, inclusive.
- K will be between 1 and 1000, inclusive.

Examples
0)
{1, 2, 3}
2
2
Returns: {2, 3}
In all annotations, we call people by their skill. For example, "player 7" means "the player whose skill level is 7".
In this example players 1 and 2 play the first game, and player 2 wins. For the second game, player 3 joins player 2, so we return { 2, 3 }.

1)
{1, 2, 3}
2
4
Returns: {1, 2}
The sequence of games is as follows:
1. Player 1 loses to player 2.
2. Player 2 loses to player 3.
3. Player 1 loses to player 3. After this player 1 joins the queue, player 3 also steps down because he just won 2 games in a row and joins the queue.
4. Player 1 loses to player 2.

2)
{49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50}
10
399
Returns: {12, 50}

3)
{30, 12}
34
80
Returns: {12, 30}

*/
