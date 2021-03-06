#!/usr/bin/python
# coding: utf-8

(b,q,l,m)=map(int,raw_input().split(' '))
arr=map(int,raw_input().split(' '))
cnt=0
if((b==0 or q==0) and abs(b)<=l):
    if(b not in arr):
        cnt+=1
    if(0 not in arr):
        cnt=-1

else:
    if(abs(q)==1 and abs(b)<=l):
        if(b not in arr):
            cnt=-1
        else:
            b=b*q
            if(abs(b)<=l and (b not in arr)):
                cnt=-1

    else:
        while(abs(b)<=l):
            if(b not in arr):
                cnt+=1
            b=b*q

if(cnt<0):
    print "inf"
else:
    print cnt


'''

Masha really loves algebra. On the last lesson, her strict teacher Dvastan gave she new exercise.

You are given geometric progression b defined by two integers b1 and q. Remind that a geometric progression is a sequence of integers b1, b2, b3, ..., where for each i > 1 the 
respective term satisfies the condition bi = b(i - 1)·q, where q is called the common ratio of the progression. Progressions in Uzhlyandia are unusual: both b1 and q can equal 0. 
Also, Dvastan gave Masha m "bad" integers a1, a2, ..., am, and an integer l.

Masha writes all progression terms one by one onto the board (including repetitive) while condition |bi| ≤ l is satisfied (|x| means absolute value of x). There is an exception: if a 
term equals one of the "bad" integers, Masha skips it (doesn't write onto the board) and moves forward to the next term.

But the lesson is going to end soon, so Masha has to calculate how many integers will be written on the board. In order not to get into depression, Masha asked you for help: help her 
calculate how many numbers she will write, or print "inf" in case she needs to write infinitely many integers.

Input
The first line of input contains four integers b1, q, l, m (-10^9 ≤ b1, q ≤ 10^9, 1 ≤ l ≤ 10^9, 1 ≤ m ≤ 10^5) — the initial term and the common ratio of progression, absolute value 
of maximal number that can be written on the board and the number of "bad" integers, respectively.

The second line contains m distinct integers a1, a2, ..., am (-10^9 ≤ ai ≤ 10^9) — numbers that will never be written on the board.

Output
Print the only integer, meaning the number of progression terms that will be written on the board if it is finite, or "inf" (without quotes) otherwise.

Examples
Input
3 2 30 4
6 14 25 48

Output
3

Input
123 1 2143435 4
123 11 -5453 141245

Output
0

Input
123 1 2143435 4
54343 -13 6 124

Output
inf

Note
In the first sample case, Masha will write integers 3, 12, 24. Progression term 6 will be skipped because it is a "bad" integer. Terms bigger than 24 won't be written because they 
exceed l by absolute value.

In the second case, Masha won't write any number because all terms are equal 123 and this is a "bad" integer.

In the third case, Masha will write infinitely integers 123.

'''
