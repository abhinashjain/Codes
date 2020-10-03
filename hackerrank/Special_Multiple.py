#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

def main():
	arr=[9]
	i=0
	for item in arr:
		tmp=str(item)+'0'
		arr.append(long(tmp))
		tmp=str(item)+'9'
		arr.append(long(tmp))
		i+=1
		if(i==10000):
			break
	num=[0]
	for i in xrange(1,501):		
		for item in arr:
			if(item%i==0):
				num.append(item)
				break
	t=int(raw_input())
	list=stdin.readlines()
	for n in list:
		n=int(n)
		stdout.write(str(num[n])+"\n")

if __name__ == "__main__":
	main()
	

'''

You are given an integer N. Can you find the least positive integer X made up of only 9’s and 0’s such that X is a multiple of N?

Update
X is made up of one or more occurences of 9 and zero or more occurences of 0.

Input Format
The first line contains an integer T which denotes the number of test cases. T lines follow.
Each line contains the integer N for which the solution has to be found.

Output Format
Print the answer X to STDOUT corresponding to each test case. The output should not contain any leading zeroes.

Constraints
1 <= T <= 10^4
1 <= N <= 500

Sample Input
3
5
7
1

Sample Output
90
9009
9

Explanation
90 is the smallest number made up of 9’s and 0’s divisible by 5. You can derive similarly for other cases.

'''
