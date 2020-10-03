#!/usr/bin/python
# coding: utf-8

dict={"00":"00", "01":"10", "02":"20", "03":"30", "04":"40", "05":"50", "06":"-1", "07":"-1", "08":"-1", "09":"-1", "10":"01", "11":"11", "12":"21", "13":"31", "14":"41", "15":"51", "16":"-1", "17":"-1", "18":"-1", "19":"-1", "20":"02", "21":"12", "22":"22", "23":"32"}

(h,m)=map(str,raw_input().split(':'))
min_val=int(dict[h])
min=int(m)
if(min_val>=min):
    print min_val-min
else:
    tot=60-min
    hrs=int(h)
    if(hrs==23):
        hrs=0
    else:
        hrs+=1
    str_hrs=str(hrs)
    if(hrs<10):
        str_hrs="0"+str(hrs)
    min_val=dict[str_hrs]
    while(min_val=="-1"):
        tot+=60
        if(hrs==23):
            hrs=0
        else:
            hrs+=1
        str_hrs=str(hrs)
        if(hrs<10):
            str_hrs="0"+str(hrs)
        min_val=dict[str_hrs]
    tot+=int(min_val)
    print tot


'''

Karen is getting ready for a new school day!

It is currently hh:mm, given in a 24-hour format. As you know, Karen loves palindromes, and she believes that it is good luck to wake up when the time is a palindrome.

What is the minimum number of minutes she should sleep, such that, when she wakes up, the time is a palindrome?

Remember that a palindrome is a string that reads the same forwards and backwards. For instance, 05:39 is not a palindrome, because 05:39 backwards is 93:50. On the other hand, 05:50 
is a palindrome, because 05:50 backwards is 05:50.

Input
The first and only line of input contains a single string in the format hh:mm (00 ≤  hh  ≤ 23, 00 ≤  mm  ≤ 59).

Output
Output a single integer on a line by itself, the minimum number of minutes she should sleep, such that, when she wakes up, the time is a palindrome.

Examples
Input
05:39

Output
11

Input
13:31

Output
0

Input
23:59

Output
1

Note
In the first test case, the minimum number of minutes Karen should sleep for is 11. She can wake up at 05:50, when the time is a palindrome.

In the second test case, Karen can wake up immediately, as the current time, 13:31, is already a palindrome.

In the third test case, the minimum number of minutes Karen should sleep for is 1 minute. She can wake up at 00:00, when the time is a palindrome.

'''
