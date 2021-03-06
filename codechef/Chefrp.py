#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
    n=int(raw_input())
    arr=map(int,raw_input().split(' '))
    if(n==1):
        if(arr[0]<2):
            print "-1"
        else:
            print "2"
    else:
        tot=tmp=arr[0]
        if(arr[0]<2):
            print "-1"
        else:
            for j in xrange(1,n):
                if(arr[j]<2):
                    tot=tmp-3
                    break
                tot+=arr[j]
                if(arr[j]<tmp):
                    tmp=arr[j]
            print tot-tmp+2



'''
    
Rupsa recently started to intern under Chef. He gave her N type of ingredients of varying quantity A1, A2, ..., AN respectively to store it. But as she is lazy to arrange them she puts
them all in a storage box.

Chef comes up with a new recipe and decides to prepare it. He asks Rupsa to get two units of each type ingredient for the dish. But when she went to retrieve the ingredients, she 
realizes that she can only pick one item at a time from the box and can know its type only after she has picked it out. The picked item is not put back in the bag.

She, being lazy, wants to know the maximum number of times she would need to pick items from the box in the worst case so that it is guaranteed that she gets at least two units of each 
type of ingredient. If it is impossible to pick items in such a way, print -1.

Input
The first line of the input contains an integer T denoting the number of test cases.
The first line of each test case contains a single integer N denoting the number of different type of ingredients.
The second line contains N space-separated integers A1, A2, ..., AN denoting the quantity of each ingredient.

Output
For each test case, output a single line containing an integer denoting the answer corresponding to that test case.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
1 ≤ Ai ≤ 10^4

Sub tasks
Subtask #1: 1 ≤ N ≤ 1000 (30 points)
Subtask #2: original constraints (70 points)

Example
Input:
2
2
2 2
1
6

Output:
4
2

Explanation
In Example 1, she need to pick up all items.
In Example 2, since there is only one type of ingredient, picking two items is enough.

'''