#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
    arr=raw_input()
    length=len(arr)
    j=-1
    gmaxcnt=lmaxcnt=0
    while(j<(length-1)):
        j+=1
        ind=j
        if(arr[ind] != '='):
            gcnt=lcnt=1
            for k in xrange(ind+1,length):
                if(arr[ind]=='<'):
                    if(arr[k]=='<'):
                        gcnt+=1
                        j+=1
                    if(arr[k]=='>'):
                        break
                if(arr[ind]=='>'):
                    if(arr[k]=='>'):
                        lcnt+=1
                        j+=1
                    if(arr[k]=='<'):
                        break
            gmaxcnt=max(gcnt,gmaxcnt)
            lmaxcnt=max(lcnt,lmaxcnt)
    ans=max(gmaxcnt,lmaxcnt)
    print ans+1


'''

Chef found a strange string yesterday - a string of signs s, where each sign is either a '<', '=' or a '>'. Let N be the length of this string. Chef wants to insert N + 1 positive 
integers into this sequence and make it valid. A valid sequence is a sequence where every sign is preceded and followed by an integer, and the signs are correct. That is, if a
sign '<' is preceded by the integer a and followed by an integer b, then a should be less than b. Likewise for the other two signs as well.

Chef can take some positive integers in the range [1, P] and use a number in the range as many times as he wants.

Help Chef find the minimum possible P with which he can create a valid sequence.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The only line of each test case contains the string of signs s, where each sign is either '<', '=' or a '>'.

Output
For each test case, output a single line containing an integer corresponding to the minimum possible P.

Constraints
1 ≤ T, |s| ≤ 10^5
1 ≤ Sum of |s| over all test cases in a single test file ≤ 10^6

Subtasks
Subtask #1 (30 points)
1 ≤ T, |s| ≤ 10^3
1 ≤ Sum of |s| over all test cases in a single test file ≤ 10^4

Subtask #2 (70 points)
Original constraints

Example
Input:
4
<<<
<><
<=>
<=<

Output:
4
2
2
3

Explanation
Here are some possible valid sequences which can be formed with the minimum P for each of the test cases:
1 < 2 < 3 < 4
1 < 2 > 1 < 2
1 < 2 = 2 > 1
1 < 2 = 2 < 3

'''
