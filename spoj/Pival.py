#!/usr/bin/python
# coding: utf-8

t=0
a=1192873628597647240
b=842468587426513207
s="3."
while True:
	t = t + 1
	d = a/b
	if d < 1:
		s += "0"
	else:
		s += str(d)
		a = a % b
	a = a * 10
	if t == 1000000:
		break
print s

'''
In this problem you have to find as many digits of PI as possible.
Output

Output must contain as many digits of PI as possible (not more than 1000000).
Score

The score awarded to your program will be the first position of the digit where the first difference occured.
Example

Output:
3.1415926535897932384626433832795

will be awarded with 33 points.
'''
