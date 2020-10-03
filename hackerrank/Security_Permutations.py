#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

n=int(raw_input())
arr=map(int,raw_input().split(' '))
for i in xrange(n):
    print arr[arr[i]-1]



'''
    
Consider a function f: X -> X where X is any set.
If f is a bijection, then f is a permutation function of X. There is nothing special about the set X. It can be replaced by the set {1,2,3,...,n} where n=|X|.
    
Consider a permutation f given by (2,3,1). This means that f(1)=2, f(2)=3 and f(3)=1.
    
In this task, you're given a permutation f: {1,2,3,..,n} -> {1,2,3,...,n}.
    
Output f(f(x)) for all x belongs to {1,2,3,...,n}.
    
Constraints
1 <= n <= 20

Input Format
There are 2 lines in the input.
The first line contains a single positive integer n.
The second line contains n space separated integers, the values of f(1), f(2), f(3), ..., f(n), respectively.
    
Output Format
On separate lines, output the values of f(f(1)), f(f(2)), f(f(3)), ..., f(f(n)), respectively.
    
Sample Input
3
2 3 1
    
Sample Output
3
1
2
    
Explanation
f(f(1)) = f(2) = 3 and so on.
    
'''