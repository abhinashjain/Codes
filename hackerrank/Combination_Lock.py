#!/usr/bin/python
# coding: utf-8

arr1=map(int,raw_input().split(' '))
arr2=map(int,raw_input().split(' '))
length=len(arr1)
tot=0
for i in xrange(length):
    min=arr1[i]
    max=arr2[i]
    if(arr1[i]>arr2[i]):
        min=arr2[i]
        max=arr1[i]
    tmp=min+10
    tmp-=max
    diff=max-min
    if(tmp>diff):
        tmp=diff
    tot+=tmp
print tot


'''
    
Consider a 5-slot combination lock where each slot contains a dial numbered with the ten sequential decimal integers in the inclusive range from 0 to 9. In one operation, you can choose a 
slot and rotate the dial by one click, either in the positive direction (to increase the displayed number by 1) or the negative direction (to decrease the displayed number by 1). Note 
that, due to the cyclical nature of the dial, the next number after 9 is 0 and the number before 0 is 9). For example, if the number 0 is currently displayed on the dial, you can rotate 
the dial to either 1 (positive direction) or 9 (negative direction) in a single operation.
    
Fig: Combination_Lock.jpeg.
    
Given the initial configuration of numbers in each slot and some desired configuration of numbers, determine the minimum number of operations you must perform to change the lock's slots 
to the desired configuration.
    
Input Format
The first line contains 5 space-separated integers denoting the current slot configuration.
The second line contains 5 space-separated integers denoting the desired slot configuration.
    
Constraints
Each number in a slot is belongs to {0,1,2,3,4,5,6,7,8,9}.
    
Output Format
Print a single integer denoting the minimum number of moves to change this configuration to the correct one.
    
Sample Input
1 2 9 5 7
1 3 2 0 7
    
Sample Output
9
    
Explanation
We perform the following operations on each slot:
Slot 1: We rotate the dial 0 times because this slot is already displaying the desired number (i.e., 1).
Slot 2: We rotate the dial 1 time, changing it from 2 -> 3.
Slot 3: We rotate the dial 3 times, changing it from 9 -> 0 -> 1 -> 2.
Slot 4: We rotate the dial 5 times, changing it from 5 -> 4 -> 3 -> 2 -> 1 -> 0.
Slot 5: We rotate the dial 0 times because this slot is already displaying the desired number (i.e., 7).
    
Finally, we sum the number of operations performed at each slot: 0+1+3+5+0=9. Thus, we print 9 as our answer.
    
'''