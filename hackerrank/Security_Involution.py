#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

n=int(raw_input())
arr=map(int,raw_input().split(' '))
tmp=0
for i in xrange(n):
    if(arr[arr[i]-1]==i+1):
        tmp+=1
if(n==tmp):
    print "YES"
else:
    print "NO"



'''
    
Consider a function f: X -> X where X is any set, and f is a bijection.
    
Now, if f = f^(-1) then f is called an involution. In other words, a function f is called an involution if f(f(x))=x
    
In this task you're given a permutation f: {1,2,3,...,n} -> {1,2,3,...,n}.
    
Determine whether f is an involution or not.
    
Constraints
1 <= n <= 20

Input Format
There are 2 lines in the input.
The first line contains a single positive integer n.
The second line contains n space separated integers, the values of f(1), f(2), f(3), ..., f(n), respectively.
    
Output Format
Output "YES" if is an involution. Otherwise, output "NO".
    
Sample Input
2
2 1
    
Sample Output
YES
    
Explanation
Since, f(1)=2 and f(2)=1, f^(-1)(1)=2 and f^(-1)(2)=1.
    
'''