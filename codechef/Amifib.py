#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

def main():
	a=0
	b=1
	c=a+b
	count={0:1,1:1}
	while(c<10**999):
		a,b=b,c
		c=a+b
		count[c]=1
	t=int(raw_input())
	list=stdin.readlines()
	for n in list:
		n=long(n)
		try:
			if(count[n]):
				stdout.write("YES\n")
		except:
			stdout.write("NO\n")

if __name__ == "__main__":
	main()
	


'''

The Head Chef has been playing with Fibonacci numbers for long . He has learnt several tricks related to Fibonacci numbers . Now he wants to test his chefs in the skills .

A fibonacci number is defined by the recurrence :

f(n) = f(n-1) + f(n-2) for n > 2
and f(1) = 0
and f(2) = 1 .

Given a number A , determine if it is a fibonacci number.


Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The only line of each test case contains a single integer A denoting the number to be checked .


Output
For each test case, output a single line containing "YES" if the given number is a fibonacci number , otherwise output a single line containing "NO" .


Constraints
    1 ≤ T ≤ 1000
    1 ≤ number of digits in A ≤ 1000
    The sum of number of digits in A in all test cases <= 10000.


Example
Input:
3
3
4
5

Output:
YES
NO
YES

Explanation
Example case 1. The first few fibonacci numbers are 0 , 1 , 1 , 2 , 3 ,5 , 8 , 13 and so on and the series is increasing . Only 3 and 5 appear in this series while 4 does not appear in the series.

'''
