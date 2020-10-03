#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

n=int(raw_input())
arr=map(int,raw_input().split(' '))
for i in xrange(1,n+1):
    for j in xrange(n):
        if(i==arr[j]):
            print j+1
            break



'''
    
Consider a bijective function f: X -> Y.
Define another function g: Y -> X so that for x belongs to X and y belongs to Y if f(x)=y then g(y)=x.
    
Now, the function g is said to be the inverse function of f and is denoted as g=f^(-1).
    
In this task, you'll be given an integer n and a bijective function f: X -> X where X = {1,2,3,...,n}.
    
Output the inverse of f.
    
Input Format
There are 2 lines in the input.
The first line contains a single positive integer n.
The second line contains n space separated integers, the values of f(1), f(2), f(3), ..., f(n), respectively.
    
Constraints
1 <= n <= 20

Output Format
Output n lines. The ith line should contain the value of f^(-1)(i).
    
Sample Input#00
3
1 2 3
    
Sample Output#00
1
2
3
    
Sample Input#01
3
2 3 1
    
Sample Output#01
3
1
2
    
Explanation
First sample :-
Basically, this is the function f(x)=x. Hence, it's the inverse of itself.
    
Second Sample :-
Here you can see that
f(1)=2
f(2)=3
f(3)=1
    
hence is f^(-1)(1) is 3
f^(-1)(2) is 1
f^(-1)(3) is 2
    
One way to confirm is f(f^(-1)(x))=x.
    
'''
