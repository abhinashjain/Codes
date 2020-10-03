#!/usr/bin/python
# coding: utf-8

sqnmod=[2]
for i in xrange(1,65):
	j=i-1
	p=(sqnmod[j]**2)%1000000007
	sqnmod.append(p)
t=int(raw_input())
for i in xrange(t):
	n=int(raw_input())
	a=raw_input()
	arr=map(int,a.split(' '))
	x=0
	for item in arr:
		x=(x|item)
	n-=1
	binofn=bin(n)[2:]
	rev=binofn[::-1]
	powr=1
	for ind, val in enumerate(rev):
		if(val=='1'):
			powr=(powr*sqnmod[ind])%1000000007
	sumxor=(x*powr)%1000000007
	print sumxor

	

'''

Given a list containing N integers, calculate the XOR_SUM of all the non-empty subsets of the list and print the value of sum % (10^9 + 7).

XOR operation on a list (or a subset of the list) is defined as the XOR of all the elements present in it.
E.g. XOR of list containing elements {A,B,C} = ((A^B)^C), where ^ represents XOR.

E.g. XOR_SUM of list A having three elements {X1, X2, X3} can be given as follows.
All non-empty subsets will be {X1, X2, X3, (X1,X2), (X2,X3), (X1,X3), (X1,X2,X3)}

XOR_SUM(A) = X1 + X2 + X3 + X1^X2 + X2^X3 + X1^X3 + ((X1^X2)^X3)

Input Format
An integer T, denoting the number of testcases. 2T lines follow.
Each testcase contains two lines, first line will contains an integer N followed by second line containing N integers separated by a single space.

Output Format
T lines, ith line containing the output of the ith testcase.

Constraints
1 <= T <= 5
1 <= N <= 10^5
0 <= A[i] <= 10^9

Sample Input #00
1
3
1 2 3

Sample Output #00
12

Explanation
The given case will have 7 non-empty subsets whose XOR is given below
1 = 1
2 = 2
3 = 3
1^2 = 3
2^3 = 1
3^1 = 2
1^2^3 = 0
So sum of all such XORs is 12.

'''
