#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

palin=[]
for i in xrange(143,1000):
    for j in xrange(100,1000):
        mul=i*j
        arr=map(int,str(mul))
        tmp=1
        length=len(arr)
        for k in xrange(length/2):
            if(arr[k]!=arr[length-k-1]):
                tmp=0
        if tmp:
            palin.append(mul)
palin.sort()

t=int(raw_input())
list=stdin.readlines()
for i in list:
    n=int(i)
    ans=palin[0]
    for j in palin:
        if(j>=n):
            break
        ans=j
    print ans




'''

A palindromic number reads the same both ways. The smallest 6 digit palindrome made from the product of two 3-digit numbers is 101101=143×707.

Find the largest palindrome made from the product of two 3-digit numbers which is less than N.

Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format
Print the required answer for each test case in a new line.

Constraints
1<=T<=100
101101<N<1000000

Sample Input
2
101110
800000

Sample Output
101101
793397

'''