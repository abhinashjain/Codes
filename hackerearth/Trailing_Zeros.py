#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

list=stdin.readlines()
for n in list:
	n=int(n)
	f=1
	z=0
	s=n/(5**f)
	while(s!=0):
		z=z+s
		f+=1
		s=n/(5**f)
	print z
	

'''

Given a number find the number of trailing zeroes in its factorial.

Input Format
A single integer - N

Output Format
Print a single integer which is the number of trailing zeroes.

Input Constraints
1 <= N <= 1000

Sample Input
10

Sample Output
2

Explanation
10! = 3628800 has 2 zeros in the end. 

'''
