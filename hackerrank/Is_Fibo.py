#!/usr/bin/python
# coding: utf-8
import math
from sys import stdin, stdout

def main():
	t=int(raw_input())
	list=stdin.readlines()
	for n in list:
		n=long(n)
		tmp=5*(math.pow(n,2))
		ans1=tmp+4
		sqrt1=math.sqrt(ans1)
		ans3=long(math.ceil(sqrt1))
		sqrt1=long(sqrt1)
		ans2=tmp-4
		sqrt2=math.sqrt(ans2)
		ans4=long(math.ceil(sqrt2))
		sqrt2=long(sqrt2)
		if(sqrt1==ans3 or sqrt2==ans4):
			stdout.write("IsFibo\n")
		else:
			stdout.write("IsNotFibo\n")				

if __name__ == "__main__":
	main()
	

'''

You are given an integer N, can you check if the number is an element of fibonacci series? The first few elements of fibonacci series are 0,1,1,2,3,5,8,13…. A fibonacci series is one where every element is a sum of the previous two elements in the series. The first two elements are 0 and 1.

Formally:

fib0 = 0
fib1 = 1
fibn = fibn-1 + fibn-2 ∀ n > 1

Input Format
First line contains T, number of test cases.
T lines follows. Each line will contain an integer N.

Output Format
Output “IsFibo” (without quotes) if N is a fibonacci number and “IsNotFibo” (without quotes) if it is not a fibonacci number, in a new line corresponding to each test case.

Constraints
1 <= T <= 10^5
1 <= N <= 10^10

Sample Input
3
5
7
8

Sample Output
IsFibo
IsNotFibo
IsFibo

Explanation
5 is a Fibonacci number given by fib5 = 3 + 2
7 is not a Fibonacci number
8 is a Fibonacci number given by fib6 = 5 + 3 

'''
