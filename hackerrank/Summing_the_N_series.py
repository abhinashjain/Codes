#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
	n=long(raw_input())
	ans=(n*n)%1000000007
	print ans
	

'''

You are given a series, whose nth term is defined as

Tn = n^2 - (n-1)^2

You have to find the Sum of the series Sn = T1 + T2 + T3 + …. + Tn

Find Sn % (10^9 + 7)

Input Format
First line contains T, denoting the number of testcases.
Each Test case contains 1 line
n

Output Format
Print the required sum % (10^9 + 7)

Constraints
1 <= T <= 10
1 <= n <= 10^16

Sample Input
2
2 
1

Sample Output
4
1

Explanation
Case#00 : we have 4 = 1 + 3
Case#01 : we have 1 = 1

'''
