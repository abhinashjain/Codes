#!/usr/bin/python
# coding: utf-8

(n,k)=map(int,raw_input().split(' '))
arr=map(int,raw_input().split(' '))
arr.sort()
div=n/k
if(n%k!=0):
    div+=1
sum=0
cnt=n
for x in xrange(div):
    tmp=n-k
    if(tmp<0):
        tmp=0
    for i in range(tmp,n):
        sum=sum+(x+1)*arr[i]
        cnt-=1
        if(cnt==0):
            break
    if(cnt==0):
        break
    n=tmp
print sum


'''

You and K-1 friends want to buy N flowers. Each flower fi has some cost ci. The florist is greedy and wants to maximize his number of new customers, so he increases the sale price of 
flowers for repeat customers; more precisely, if a customer has already purchased x flowers, price P for fi is P(fi)=(x+1)*ci.

Find and print the minimum cost for your group to purchase N flowers.

Note: You can purchase the flowers in any order.

Input Format
The first line contains two integers, N (number of flowers to purchase) and K (the size of your group of friends, including you).
The second line contains N space-separated positive integers describing the cost (c0,c1,...,cN-2,cN-1) for each flower fi.

Constraints
1<=N,K<=100
1<=ci<=10^6
answer<2^31
0<=i<=N-1

Output Format
Print the minimum cost for buying N flowers.

Sample Input 0
3 3
2 5 6

Sample Output 0
13

Sample Input 1
3 2
2 5 6

Sample Output 1
15

Explanation
Sample Case 0:
There are 3 flowers and 3 people in your group. Each person buys one flower and the sum of prices paid is 13 dollars, so we print 13.

Sample Case 1:
There are 3 flowers and 2 people in your group. The first person purchases 2 flowers, f0 and f1, in order of decreasing price; this means they buy the more expensive flower first at 
price P(f1)=(0+1)*5=5 dollars and the less expensive flower second at price P(f0)=(1+1)*2=4 dollars. The second person buys the most expensive flower at price P(f2)=(0+1)*6=6 dollars
. We print the sum of these purchases (5+4+6), which is 15.

'''
