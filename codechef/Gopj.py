#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in range(t):
	(n,b)=(raw_input()).split(' ')
	n=int(n)
	b=int(b)
	maxm=0
	for j in range(1,n+1):
		maxm+=j
		if(maxm==b):
			maxm-=1
	print maxm
	

'''

Gopal is standing at the bottom of a longest stair in UVCE. And surprisingly steps are numbered sequentially form 1 to infinity. The bottommost step has number 1, the next step has number 2, and so on.
Gopal is now standing at bottom of the stairs, will now perform exactly N consecutive actions. When performing ith action , Gopal chooses between two options: either he does nothing, or he jumps exactly i steps up the stairs.

The steps are very old and Gopal know that the Bth step is broken, he cannot jump onto this step. You are given N, number of actions performed by Gopal and B, number or index of broken step. Your task is to find the number or index of the topmost step that can be reached by Gopal.
INPUT

First line contains T, number of test cases.
Each test case contains two space separated integers N and B.
OUTPUT

For each test case output the maximum number or index of step, that can be reached by Gopal in N actions.
CONSTRAINTS

    1 ≤ T ≤ 1000
    0 ≤ N ≤ 2000
    0 ≤ B ≤ 400000

EXAMPLE

Input

4
2 2
2 1
3 3
1313 5858

Output

3
2
5
862641 

'''
