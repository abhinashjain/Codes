#include "iostream"
#define MAX 1000005
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

long long cubicroot(long long x)
{
    long long l=0,r=MAX,m;
    while(l!=r)
    {
        m=(l+r+1)/2;
        if((m*m*m) > x)
        {
            r=m-1;
        }
        else
        {
            l=m;
        }
    }
    return l;
}

int main()
{
    dontsync()
    long long i,n,a,b,prod,cuberoot;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a >> b;
        prod=a*b;
        cuberoot=cubicroot(prod);
        if((cuberoot*cuberoot*cuberoot)==prod && (a%cuberoot)==0 && (b%cuberoot)==0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}


/*

Slastyona and her loyal dog Pushok are playing a meaningless game that is indeed very interesting.

The game consists of multiple rounds. Its rules are very simple: in each round, a natural number k is chosen. Then, the one who says (or barks) it faster than the other wins the
round. After that, the winner's score is multiplied by k^2, and the loser's score is multiplied by k. In the beginning of the game, both Slastyona and Pushok have scores equal to
one.

Unfortunately, Slastyona had lost her notepad where the history of all n games was recorded. She managed to recall the final results for each games, though, but all of her memories
of them are vague. Help Slastyona verify their correctness, or, to put it another way, for each given pair of scores determine whether it was possible for a game to finish with
such result or not.

Input
In the first string, the number of games n (1 ≤ n ≤ 350000) is given.
Each game is represented by a pair of scores a, b (1 ≤ a, b ≤ 10^9) – the results of Slastyona and Pushok, correspondingly.

Output
For each pair of scores, answer "Yes" if it's possible for a game to finish with given score, and "No" otherwise.
You can output each letter in arbitrary case (upper or lower).

Example
Input
6
2 4
75 45
8 8
16 16
247 994
1000000000 1000000

Output
Yes
Yes
Yes
No
No
Yes

Note
First game might have been consisted of one round, in which the number 2 would have been chosen and Pushok would have won.

The second game needs exactly two rounds to finish with such result: in the first one, Slastyona would have said the number 5, and in the second one, Pushok would have barked the
number 3.

*/
