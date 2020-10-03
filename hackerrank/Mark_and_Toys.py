#!/usr/bin/python
# coding: utf-8

price=[]
sum=0
n,k=raw_input().split(' ')
n=int(n)
k=int(k)
for i in raw_input().split(' '):
    price.append(int(i))       
price.sort()
for i in range(n):
	sum+=price[i]
	if(sum>k):
		break        
print i



'''

Mark and Jane are very happy after having their first kid. Their son is very fond of toys. Therefore, Mark wants to buy some toys for his son. But he has a limited amount of money. But he wants to buy as many toys as he can. So, he is in a dilemma and is wondering how he can maximize the number of toys he can buy. He has N items in front of him, tagged with their prices and he has only K rupees.

Now, you being Mark’s best friend have the task to help him buy as many toys for his son as possible.

Input Format
The first line will contain two inputs N and K, followed by a line containing N integers

Output Format
Maximum number of toys Mark can buy for his son.

Constraints
1<=N<=10^5
1<=K<=10^9
1<=price of any toy<=10^9

Sample Input

7 50
1 12 5 111 200 1000 10

Sample Output

4

Explanation

He can buy only 4 toys at most. These toys have the following prices: 1,12,5,10.
Submissions Leaderboard Discussions

'''
