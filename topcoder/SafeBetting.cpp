class SafeBetting
{
    public:
        int minRounds(int a,int b,int c)
        {
            int cnt=0;
            while(b<c)
            {
                cnt++;
                b=(2*b)-a;
            }
            return cnt;
        }
};


/*

Limak is in a casino. He has b dollars. He wants to have at least c dollars (to be able to buy flowers for a girl he likes). In order to achieve that, he must win the money he's
missing.
 
The casino allows guests to risk some of their money on bets. Limak can make as many bets as he likes, but he has to make them one after another. Each time Limak makes a bet, he
chooses the amount he wants to bet. The amount must be a positive integer. Each bet has two possible outcomes: either Limak loses the money, or he gets it back doubled.
 
For example, suppose Limak has 20 dollars. If he bets 5, he will be left with 20 - 5 = 15 dollars. If he loses the bet, that is his new total. If he wins the bet, he'll get back 2*5 
= 10 dollars, which will bring his total up to 15 + 10 = 25 dollars.
 
Limak doesn't want to lose all his money. More precisely, he wants to make sure that at any moment he will have at least a dollars. He will not make a bet if losing the bet would
mean that he will have less than a dollars.
 
For example, suppose Limak currently has 20 dollars. If a = 15, in the next round Limak can bet 1, 2, 3, 4, or 5 dollars. Note that a bet of 6 dollars is not allowed: if he lost it,
he would have 20 - 6 = 14 dollars, which is less than a.
 
You are given the s a, b, and c. We will assume that Limak follows the rules described above when choosing the amounts to bet. Compute and return the smallest B such that Limak can
reach his goal (i.e., have at least c dollars) after making B bets.
 
Constraints
- a, b and c will each be between 1 and 1000, inclusive.
- a will be smaller than b.
- b will be smaller than c.

Examples
0)
15
20
48
Returns: 3
 
Limak has 20 dollars. He wants to have at least 48 dollars. He can never have less than 15 dollars.
 
In the first round Limak can bet at most 5 dollars (as explained in the example in the problem statement). If he bets 5 and wins, he will have 25 dollars. In the second round he
will be able to bet at most 10 dollars. If he wins that round as well, he will have 35 dollars. Finally, it is possible that in the third round Limak will bet 13 dollars and he
will win the bet. At that moment he will have exactly 48 dollars.
 
The correct return value is 3, because Limak needed to place at least 3 bets. He cannot reach 48 dollars by placing fewer than 3 bets.
 
1)
10
400
560
Returns: 1

2)
5
7
21
Returns: 3

3)
5
7
22
Returns: 4

4)
17
30
1000
Returns: 7

*/
