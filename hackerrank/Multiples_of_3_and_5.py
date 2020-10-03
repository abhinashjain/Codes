#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

t=int(raw_input())
list=stdin.readlines()
for i in list:
    last=int(i)-1
    num=last/3
    tot=(num*(6+(num-1)*3))/2
    num=last/5
    tot+=(num*(10+(num-1)*5))/2
    num=last/15
    tot-=(num*(30+(num-1)*15))/2
    stdout.write(str(tot)+"\n")



'''

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below N.

Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format
For each test case, print an integer that denotes the sum of all the multiples of 3 or 5 below N.

Constraints
1<=T<=10^5
1<=N<=10^9

Sample Input
2
10
100

Sample Output
23
2318

'''