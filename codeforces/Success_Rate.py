#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
    (x,y,p,q)=map(int,raw_input().split(' '))
    if((p==q and x!=y) or (p==0 and x!=0)):
        print "-1"
    else:
        if((p==0 and x==0) or (p==q and x==y)):
            print "0"
        else:
            win=(x+p-1)/p                           # pt >= x      Minimum t for which desired win is always greater than current win
            loss=0
            if(p!=q):
                loss=((y-x)+(q-p)-1)/(q-p)          # (q-p)t >= (y-x)  Minimum t for which desired loss is always greater than current loss
            n=max(win,loss)                         # this n can satisfy both of the above condition simultaneously
            print (q*n)-y                           # q*n games needed to get the desired ratio, out of which y games have already been played.


'''

You are an experienced Codeforces user. Today you found out that during your activity on Codeforces you have made y submissions, out of which x have been successful. Thus, your 
current success rate on Codeforces is equal to x / y.

Your favorite rational number in the [0;1] range is p / q. Now you wonder: what is the smallest number of submissions you have to make if you want your success rate to be p / q?

Input
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.
Each of the next t lines contains four integers x, y, p and q (0 ≤ x ≤ y ≤ 10^9; 0 ≤ p ≤ q ≤ 10^9; y > 0; q > 0).
It is guaranteed that p / q is an irreducible fraction.

Hacks. For hacks, an additional constraint of t ≤ 5 must be met.

Output
For each test case, output a single integer equal to the smallest number of submissions you have to make if you want your success rate to be equal to your favorite rational number, 
or -1 if this is impossible to achieve.

Example
Input
4
3 10 1 2
7 14 3 8
20 70 2 7
5 6 1 1

Output
4
10
0
-1

Note
In the first example, you have to make 4 successful submissions. Your success rate will be equal to 7 / 14, or 1 / 2.

In the second example, you have to make 2 successful and 8 unsuccessful submissions. Your success rate will be equal to 9 / 24, or 3 / 8.

In the third example, there is no need to make any new submissions. Your success rate is already equal to 20 / 70, or 2 / 7.

In the fourth example, the only unsuccessful submission breaks your hopes of having the success rate equal to 1.

'''
