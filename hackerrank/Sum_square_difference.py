#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

diffarr=[]
diffarr.append(0)
diffarr.append(0)
diffarr.append(4)
for i in xrange(3,100001):
    tmp=i*i*(i-1)+diffarr[i-1]
    diffarr.append(tmp)
t=int(raw_input())
list=stdin.readlines()
for i in list:
	stdout.write(str(diffarr[int(i)])+"\n")






'''

The sum of the squares of the first ten natural numbers is, 1^2+2^2+...+10^2=385. The square of the sum of the first ten natural numbers is, (1+2+...+10)^2=55^2=3025. Hence the
difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025-385=2640.

Find the difference between the sum of the squares of the first N natural numbers and the square of the sum.

Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format
Print the required answer for each test case.

Constraints
1<=T<=10^4
1<=N<=10^4

Sample Input
2
3
10

Sample Output
22
2640

'''