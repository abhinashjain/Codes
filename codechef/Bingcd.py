#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in range(t):
	n=int(raw_input())
	if(n&1):
		print 2
	elif(n&(n-1)==0):
		print n*2
	else:
		k=4
		while(n&(k-1)==0): #(n%k==0)
			k*=2
		print k
		

		
'''

This is probably the easiest task of this problem set. To help you understand the task let us define two key functions:
f(n,k), (with k <= n) which gives the number of ways we can draw a sample of k objects from a set of n-distinct objects where order of drawing is not important and we do not allow repetition.

G(x1, x2, x3, ... , xn) is the largest integer that perfectly divides all of  {x1, x2, x3, ... , xn}.

Given an integer N,  your task is to compute the value of Y where 

                                     Y =  G( f(2*N,1), f(2*N,3), f(2*N,5), ... , f(2*N,2*N-1)).

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. The first and the only line of each test case contains a single integer denoting the given N as described in the problem statement. 


Output

For each test case, output a single line containing the value of Y.
Constraints

    1 ≤ T ≤ 10000

    2 ≤ N ≤ 10^11

Example
Input:
3
6
5
4

Output:
4
2
8

'''
