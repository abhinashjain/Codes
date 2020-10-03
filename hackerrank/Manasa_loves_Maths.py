#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
	n=raw_input()
	arr=map(int,str(n))
	flag=0
	if len(arr)<3:
		if len(arr)==1:
			if arr[0]%8==0:
				print "YES"
			else:
				print "NO"
		else:
			num=int(str(arr[0])+str(arr[1]))
			if num%8==0:
				print "YES"
			else:
				num=int(str(arr[1])+str(arr[0]))
				if num%8==0:
					print "YES"
				else:
					print "NO"
	else:
		for j in xrange(len(arr)):
			for k in xrange(len(arr)):
				if j!=k:				
					for l in xrange(len(arr)):
						if j!=l and k!=l:
							num=int(str(arr[j])+str(arr[k])+str(arr[l]))
							if num%8==0:
								flag=1
								print "YES"
								break
					if flag:
						break
			if flag:
				break
		if not flag:
			print "NO"
			

'''

You are given an integer N. Is there a permutation of digits of integer that’s divisible by 8? A permutation of digits of integer N is defined as an integer formed by rearranging the digits of N. For example, if the number N = 123, then {123, 132, 213, 231, 312, 321} are the possible permutations.

Input Format
The first line contains an integer T i.e. number of test cases.
T lines follow, each containing the integer N.

Output Format
For each test case print YES if there exists one such re-arrangement of N such that it is divisible by 8 or NO if there isn’t.

Constraints
1 <= T <= 45
0 <= N <= 10^110

Note
Re-arrangements of 10 are {10, 01} which boils down to {10, 1}.

Sample Input
2
61
75

Sample Output
YES
NO

Explanation
Test case #00: 16 is permutation of 61 which is divisible by 8.
Test case #01: None of permutation of 75, {57, 75}, are divisible by 8.

'''
