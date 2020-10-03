#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

t=int(raw_input())
list=stdin.readlines()
for i in list:
    n=int(i)
    binofn=bin(n)[2:]
    rev=binofn[::-1] #reverses the string
    pow=1
    a=2
    for ch in rev:
        if(ch=='1'):
            pow=pow*a
        a=a*a
    sum=0
    arr=map(int,str(pow))
    for j in arr:
        sum+=j
    stdout.write(str(sum)+"\n")


'''

2^9=512 and the sum of its digits is 5+1+2=8.
What is the sum of the digits of the number 2^N ?

Input Format
The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integer N.

Output Format
Print the values corresponding to each test case.

Constraints
1<=T<=100
1<=N<=10^4

Sample Input
3
3
4
7

Sample Output
8
7
11
    
'''