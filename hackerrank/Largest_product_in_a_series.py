#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
    (n,k)=map(int,raw_input().split(' '))
    arr=map(int,raw_input())
    length=len(arr)
    max=0
    for j in xrange(length-k+1):
        prod=1
        iter=j
        for r in xrange(k):
            prod*=arr[iter]
            iter+=1
        if(prod>max):
            max=prod
    print max




'''

Find the greatest product of K consecutive digits in the N digit number.

Input Format
First line contains T that denotes the number of test cases.
First line of each test case will contain two integers N & K.
Second line of each test case will contain a N digit integer.

Output Format
Print the required answer for each test case.

Constraints
1<=T<=100
1<=K<=7
K<=N<=1000

Sample Input
2
10 5
3675356291
10 5
2709360626

Sample Output
3150
0
    
'''