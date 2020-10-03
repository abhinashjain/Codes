#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
	totsum=0
	rowcnt=colcnt=1
	m,n=raw_input().split(' ')
	y=raw_input()
	row=map(int,y.split(' '))
	x=raw_input()
	col=map(int,x.split(' '))
	rowlen=len(row)
	collen=len(col)
	row.sort()
	col.sort()
	while(rowlen!=0 or collen!=0):
		if(collen==0 and rowlen>0) or (rowlen>0 and row[-1]>=col[-1]):
			rowcnt+=1
			tmp=row.pop()
			totsum+=(tmp*colcnt)%1000000007
			rowlen-=1
		else:
#			if(rowlen==0 and collen>0) or (collen>0 and row[-1]<col[-1]):
				colcnt+=1
				tmp=col.pop()
				totsum+=(tmp*rowcnt)%1000000007		
				collen-=1
	print totsum%1000000007
	

	
'''

Alice gives a wooden board composed of M X N wooden square pieces to Bob and asks him to find the minimal cost of breaking the board into square wooden pieces. Bob can cut the board along horizontal and vertical lines and each cut divides the board in smaller parts. Each cut of the board has a cost depending on whether the cut is made along a horizontal or vertical line.

Let us denote the costs of cutting it along consecutive vertical lines with x1, x2, …, xn-1 and along horizontal lines with y1, y2, …, ym-1. If a cut (of cost c) is made and it passes through n segments, then total cost of this cut will of n*c.

The cost of cutting the whole board into single squares is the sum of the cost of successive cuts used to cut the whole board into square wooden pieces of size 1x1. Bob should compute the minimal cost of breaking the whole wooden board into squares of size 1x1.

Bob needs your help to find the minimal cost. Help Bob with this challenge?

Input Format
A single integer in the first line T, stating the number of test cases. T testcases follow.
For each test case, the first line contains two positive integers M and N separated by a single space. In the next line there are integers y1, y2, …, ym-1, separated by spaces. Following there are integers x1, x2, …, xn-1, separated by spaces.

Output Format
For each test-case, write one integer in separate lines which denots the minimal cost of breaking the whole wooden board into single wooden squares. Since the answer can be very large, output the answer modulo 10^9+7.

Constraints
1 <= T <= 20
2 <= M,N <= 1000000
0 <= xi <= 10^9
0 <= yi <= 10^9

Sample Input #00
1
2 2
2
1

Sample Output #00
4

Sample Input #01
1
6 4
2 1 3 1 4
4 1 2

Sample Output #01
42

Explanation
Sample Case #00:At first, board should be cut horizontally, where y1 = 2, then it should be cut vertically. So total cost will be 2*1 + 1*2 = 4.

Sample Case #01: We should start cutting using y5, x1, y3, y1, x3, y2, y4 and x2, in order. First cut will be a horizontal one where cost = y5 = 4. Next we will do a vertical cut with x1. Since this cut passes through two segments (created by previous vertical cut), it’s total cost will be 2*x1 = 2*4. Similarly next horizontal cut (y3) will pass through two segments and will cost 2*y3 = 2*3. We can proceed in similar way and get overall cost as 4 + 4*2 + 3*2 + 2*2 + 2*4 + 1*3 + 1*3 + 1*6 = 42.

'''
