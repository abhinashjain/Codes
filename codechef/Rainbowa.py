#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
    n=int(raw_input())
    arr=map(int,raw_input().split(' '))
    greater=0
    for j in arr:
        if(j>7):
            greater=1
            break
    if(greater):
        print "no"
    else:
        mid=int(n/2)
        if(arr[mid]!=7):
            print "no"
        else:
            ind=mid
            while(ind<(n-6) and arr[ind]==7):
                ind+=1
            if(ind==n-6 and arr[ind]==7):
                print "no"
            else:
                r=ind
                ind=mid
                while(ind>5 and arr[ind]==7):
                    ind-=1
                if(ind==5 and arr[ind]==7):
                    print "no"
                else:
                    l=ind
                    while(l>=0 and r<n and arr[l]==arr[r]):
                        l-=1
                        r+=1
                    if(r==n and l==-1):
                        print "yes"
                    else:
                        print "no"


'''

Chef likes all arrays equally. But he likes some arrays more equally than others. In particular, he loves Rainbow Arrays.

An array is Rainbow if it has the following structure:

1. First a1 elements equal 1.
2. Next a2 elements equal 2.
3. Next a3 elements equal 3.
4. Next a4 elements equal 4.
5. Next a5 elements equal 5.
6. Next a6 elements equal 6.
7. Next a7 elements equal 7.
8. Next a6 elements equal 6.
9. Next a5 elements equal 5.
10. Next a4 elements equal 4.
11. Next a3 elements equal 3.
12. Next a2 elements equal 2.
13. Next a1 elements equal 1.
14. ai can be any non-zero positive integer.
15. There are no other elements in array.

Help Chef in finding out if the given array is a Rainbow Array or not.

Input
The first line of the input contains an integer T denoting the number of test cases.
The first line of each test case contains an integer N, denoting the number of elements in the given array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of array.

Output
For each test case, output a line containing "yes" or "no" (without quotes) corresponding to the case if the array is rainbow array or not.

Constraints
1 ≤ T ≤ 100
7 ≤ N ≤ 100
1 ≤ Ai ≤ 10

Subtasks
Subtask 1 (100 points) : Original constraints

Example
Input
3
19
1 2 3 4 4 5 6 6 6 7 6 6 6 5 4 4 3 2 1
14
1 2 3 4 5 6 7 6 5 4 3 2 1 1
13
1 2 3 4 5 6 8 6 5 4 3 2 1

Output
yes
no
no

Explanation
The first example satisfies all the conditions.
The second example has 1 element of value 1 at the beginning and 2 elements of value 1 at the end.
The third one has no elements with value 7 after elements with value 6.

'''
