#!/usr/bin/python
# coding: utf-8

def gcd(a,b):
    while b:
        a, b = b, a % b
    return a

t=int(raw_input())
for i in xrange(t):
    n=int(raw_input())
    arr=map(int,raw_input().split(' '))
    div=arr[0]
    for j in xrange(1,n):
        if(div==1):
            break
        div=gcd(div,arr[j])
    print div*n



'''
    
Sereja has an array A of N positive integers : A[1], A[2], A[3], ... , A[N].
    
In a single operation on the array, he performs the following two steps :
Pick two indices i, j s.t. A[i] > A[j]
A[i] -= A[j]
    
Sereja can apply these operations any number of times (possibly zero), such that the sum of resulting elements of the array is as small as possible.
Help Sereja find this minimum sum.

Input
First line of input contains an integer T - the number of test cases. T test cases follow.
First line of each test case contains the integer N. The next line contains N integers — A[1], A[2], A[3], ... , A[N].

Output
For each test case, output a single line with the answer.

Constraints
1 <= T <= 10
1 <= N <= 10^5
1 <= A[i] <= 10^9
    
Example
Input:
2
1
1
3
2 4 6
    
Output:
1
6
    
Explanation
Example case 2. In this case, one possible way in which Sereja can perform the operations could be as follows.
Pick i = 2, j = 1. A[2] -= A[1]. Now the resulting array would be [2, 2, 6].
Pick i = 3, j = 2. A[3] -= A[2]. Now the resulting array would be [2, 2, 4].
Pick i = 3, j = 2. A[3] -= A[2]. Now the resulting array would be [2, 2, 2].
    
As the resulting array is [2 2 2], so the sum is 6.
    
'''