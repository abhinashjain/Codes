#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in range(t):
	n=int(raw_input())
	ans=((n*(3*n+1))/2) % 1000007;
	print ans
	
	



'''

Maricruz have a lot of cards, she always uses her cards to build pyramids as shown in Crds.jpg image:
A pyramid card of 3 leves.
She always wonder how many cards does she need to make a pyramid card of N levels. Your task is to answer that question.

Input
The first line of the input contains an integer 1<= T <= 1,000. Each of the
following T lines will have an integer 1<= N <= 1,000,000.
Output
For each case, output a single line consisting of the number of cards needed to
build a pyramid card of level N modulo 1,000,007.


Input Example
2
3
7
1000000
Output Example
15
77
70

'''
