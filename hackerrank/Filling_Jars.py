#!/usr/bin/python
# coding: utf-8
import math
from sys import stdin, stdout

def main():
	tot=0
	n,m=raw_input().split(' ')
	n=int(n)
	m=int(m)
	list=stdin.readlines()
	for i in list:
		a,b,k=i.split(' ')
		a=int(a)
		b=int(b)
		k=int(k)
		tot+=(b-a+1)*k
	stdout.write(str(tot/n)+"\n")

if __name__ == "__main__":
	main()
	


'''

Animesh has N empty candy jars numbered from 1 to N with infinite capacity. He performs M operations. Each operation is described by 3 integers a, b and k where a and b are index of the jars and k is the number of candies to be added inside each jar with index between a and b (both inclusive). Can you tell the average number of candies after M operations?

Input Format
The first line contains two integers N and M separated by a single space.
M lines follow. Each of the M lines contain three integers a, b and k separated by single space.

Output Format
A single line containing the average number of candies across N jars, rounded down to the nearest integer.

Constraints
3 <= N <= 10^7
1 <= M <= 10^5
1 <= a <= b <= N
0 <= k <= 10^6

Sample Input #00
5 3
1 2 100
2 5 100
3 4 100

Sample Output #00
160

Explanation
Initially each of the jar contains 0 candies
0 0 0 0 0  

First operation
100 100 0 0 0  

Second operation
100 200 100 100 100  

Third operation
100 200 200 200 100  

Total = 800, Average = 800/5 = 160 

'''
