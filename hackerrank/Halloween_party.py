#!/usr/bin/python
import math
# coding: utf-8

t=int(raw_input())
for i in range(t):
	k=int(raw_input())
	r=k/2
	c=int(math.ceil(k/2.0))
	print r*c
	
	

'''

Alex is attending a Halloween party with his girlfriend Silvia. At the party, Silvia spots a giant chocolate bar. If the chocolate can be served as only 1 x 1 sized pieces and Alex can cut the chocolate bar exactly K times, what is the maximum number of chocolate pieces Alex can cut and give Silvia?

Input Format
The first line contains an integer T denoting the number of testcases. T lines follow.
Each line contains an integer K

Output Format
T lines. Each containing the output corresponding to the testcase.

Constraints
1<=T<=10
1<=K<=10^7

Sample Input #00
4
5
6
7
8

Sample Output #00
6
9
12
16

'''
