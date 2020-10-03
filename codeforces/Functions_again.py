#!/usr/bin/python
# coding: utf-8

n=int(raw_input())
arr=map(long,raw_input().split(' '))
arr1=[]
for i in xrange(n-1):
    tmp=abs(arr[i+1]-arr[i])
    tmp=tmp*((-1)**i)
    arr1.append(tmp)

arr2=[]
for i in xrange(n-1):
    arr2.append(arr1[i]*(-1))

max=current=0
for i in xrange(n-1):
    current+=arr1[i]
    if(current<0):
        current=0
    if(max<current):
        max=current

current=0
for i in xrange(n-1):
    current+=arr2[i]
    if(current<0):
        current=0
    if(max<current):
        max=current

print max


'''

Something happened in Uzhlyandia again... There are riots on the streets... Famous Uzhlyandian superheroes Shean the Sheep and Stas the Giraffe were called in order to save the 
situation. Upon the arriving, they found that citizens are worried about maximum values of the Main Uzhlyandian Function f, which is defined as follows:

                                                                    Functions_again.png

In the above formula, 1 ≤ l < r ≤ n must hold, where n is the size of the Main Uzhlyandian Array a, and |x| means absolute value of x. But the heroes skipped their math lessons in 
school, so they asked you for help. Help them calculate the maximum value of f among all possible values of l and r for the given array a.

Input
The first line contains single integer n (2 ≤ n ≤ 10^5) — the size of the array a.
The second line contains n integers a1, a2, ..., an (-10^9 ≤ ai ≤ 10^9) — the array elements.

Output
Print the only integer — the maximum value of f.

Examples
Input
5
1 4 2 3 1

Output
3

Input
4
1 5 4 7

Output
6

Note
In the first sample case, the optimal value of f is reached on intervals [1, 2] and [2, 5].

In the second case maximal value of f is reachable only on the whole array.

'''
