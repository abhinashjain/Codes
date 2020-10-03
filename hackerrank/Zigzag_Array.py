#!/usr/bin/python
# coding: utf-8

n=int(raw_input())
arr=map(int,raw_input().split(' '))
ans=0
for i in xrange(n-2):
    if((arr[i]<arr[i+1] and arr[i+1]<arr[i+2]) or (arr[i]>arr[i+1] and arr[i+1]>arr[i+2])):
        ans+=1
print ans


'''

We say an array of n distinct integers, A=[a0,a1,...,a(n-1)], is zigzag if no three consecutive elements in the array are either increasing or decreasing.

In other words, if there are three elements ai, ai+1, ai+2 in the array such that ai < ai+1 < ai+2 or ai > ai+1 > ai+2, the array is not zigzag.

For example:
Ordinary Arrays:
[6,5,4,9,1]
[9,5,7,8,2,1]
[1,2,3,4]

Zigzag Arrays:
[6,5,7,2,3]
[4,2,6,3,10,1]
[4,9]

Given A, find and print the minimum number of elements you must remove to make the given array zigzag.

Input Format
The first line contains n, denoting the number of elements.
The second line contains n space-separated integers describing the respective values of a0,a1,...,a(n-1).

Constraints
1<=n<=100
1<=ai<=100
The elements of A are distinct.

Output Format
Print the minimum number of elements you must remove to make the given array zigzag.

Sample Input 0
6
4 2 6 3 10 1

Sample Output 0
0

Explanation 0
The array [4,2,6,3,10,1] is already zigzag, so we return 0.

Sample Input 1
5
5 2 3 6 1

Sample Output 1
1

Explanation 1
The array [5,2,3,6,1] is not zigzag because here a1<a2<a3 (2<3<6).

If we remove 6, the array becomes [5,2,3,1] which is zigzag. Because we only needed to remove one element, we return 1 as our answer.

'''
