#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in range(t):
	pa=float(raw_input())
	pb=1-pa;
	if(pa>=pb):
		s=10000*pb;
	else:
		s=10000*pa;
	s=(20000*pa*pb)+10000-s;   # profit = 20000*pa*pb-(B*pa+A*pb);		# (5880-4000)*0.51+(4080-6000)*0.49
	print s


'''

Chef Datta likes betting in Indian Premier League very much.

He has 10000 rupees. Today the match is between team A and team B. The winning probability of team A is PA, and hence winning probability of team B is PB = 1 − PA.

Datta is free to bet any integral amount of money on any of the two teams as long as the total amount of money bet is at most 10000 rupees.
Help him know the expected amount of money he will eventually have if today he places his bet(s) optimally.
Rules of the game:

If team X with winning probability PX actually wins and someone bets M rupees on this team, he will gain (2*(1−PX)) * M rupees.

If team X with winning probability PX actually loses and someone bets N rupees on this team, he will just lose N rupees.

Input

First line contains single integer T, the number of testcases. Then T lines follow, each line contains PA the probability that team A wins.

Output

For each test case output single line containing the expected amount of money Datta will eventually have today if he places his bet(s) optimally. Your answer will be accepted if the absolute error is less than 10−6.
Constraints

    1 ≤ T ≤ 100001 (10^5+1)
    0.0 ≤ PA ≤ 1.0
    PA has at most 5 digits after the decimal point.

Example

Input:
1
0.510

Output:
10098

 
Example bet:

Look at the following situation:

A=51% and B=49% Then
If chef Datta bets 6,000 on team A and 4,000 on team B, the expected amount of money he will have after the bet is settled is 10,018. Apparently that is not the best he can do ;)

'''
