#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
    neg_arr=[]
    pos=neg=cnt=0
    n=int(raw_input())
    arr=map(long,raw_input().split(' '))
    for val in arr:
        if(val>=0):
            cnt+=1
            pos+=val
        else:
            neg_arr.append(val)
    neg_arr.sort(reverse=True)
    hap=cnt*pos
    for val in neg_arr:
        tmp=(pos+val)*(cnt+1)
        if(tmp>=hap):
            cnt+=1
            pos+=val
            hap=tmp
        else:
            neg+=val
    print hap+neg


'''

Chef has prepared a feast with N dishes for you. You like Chef's cooking, and so you want to eat all the dishes he has prepared for you. You are also given an array A of size N, 
where Ai represents the happiness you get by eating the i-th dish.You will eat all the dishes in a series of steps. In each step, you pick a non empty subset of the remaining dishes 
and eat them. The happiness you get from eating these dishes is the size of the subset multiplied by the sum of the individual happiness from the dishes in the subset. You want to 
maximize the happiness you get from the entire feast, which is the sum of happiness in each step.

Input
The first line contains T, the number of test cases.
The first line of each test case contains a single integer N, denoting the number of dishes prepared by the Chef.
The second line of each test case contains contains N space-separated integers: A1, A2, ..., AN denoting the happiness gained by eating the dishes.

Output
Output a single number denoting the maximum happiness you can get from the feast.

Constraints
1 ≤ T ≤ 8
1 ≤ N ≤ 10^5
-10^8 ≤ Ai ≤ 10^8

Subtasks
Subtask #1: Ai ≤ 0 (30 points)
Subtask #2: Original Constraints (70 points)

Example 1
Input:
1
3
-8 0 -2

Output:
-10

Example 2
Input:
1
3
1 2 3

Output:
18

Explanation
Example case 1. You can eat the first dish in the first step, the second dish in the second step and the third dish in the third step. total happiness = 1*(-8) + 1*0 + 1*(-2) = -10

'''
