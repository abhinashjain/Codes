#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout


def customrange(start, stop, step):
    while start*start <= stop:
        yield start
        start += step

t=int(raw_input())
list=stdin.readlines()
for i in list:
    n=int(i)
    if(n&(n-1) != 0):
        sum=0
        for j in customrange(2,n,1):
            if(n%j == 0):
                sum += j
                if(j*j != n):
                    sum += n/j
        print 1+sum+n
    else:
        print n*2-1


'''

Chef wants to hire a new assistant. He published an advertisement regarding that in a newspaper. After seeing the advertisement, many candidates has applied for the job. Now chef wants 
to shortlist people for the interviews, so he gave all of them one problem which they must solve in order to get shortlisted.

The problem was: For a given positive integer N, what is the maximum sum of distinct numbers such that the Least Common Multiple of all these numbers is N.

Your friend Rupsa also applied for the job, but was unable to solve this problem and hence you've decided to help her out by writing a code for solving this problem.

Input
The first line of the input contains an integer T denoting the number of test cases.
Each test case contains a single integer N.

Output
For each test case, output a single line containing an integer corresponding to the answer for that test case.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 10^9

Subtask 1 (30 points):
1 ≤ T ≤ 100
1 ≤ N ≤ 10^5

Subtask 2 (70 points):
original constraints

Example
Input:
2
1
2

Output:
1
3

Explanation
Example 1 : Only possible number is 1, so the maximum sum of distinct numbers is exactly 1.
Example 2 : The distinct numbers you can have are just 1 and 2, so the sum is 3. If we consider any other number greater than 2, then the least common multiple will be more than 2.

'''