#!/usr/bin/python
# coding: utf-8

n=int(raw_input())
cnt=0
for i in range(n):
	x1,y1,x2,y2,x3,y3=raw_input().split(' ')
	x1=int(x1)
	y1=int(y1)
	x2=int(x2)
	y2=int(y2)
	x3=int(x3)
	y3=int(y3)
	a=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)
	b=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)
	c=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)
	if((a+b)==c or (a+c)==b or (b+c)==a):
		cnt=cnt+1		
print cnt



'''

The Chef is given a list of N triangles. Each triangle is identfied by the coordinates of its three corners in the 2-D cartesian plane. His job is to figure out how many
of the given triangles are right triangles. A right triangle is a triangle in which one angle is a 90 degree angle. The vertices
of the triangles have integer coordinates and all the triangles given are valid( three points aren't colinear ).  

 
Input

The first line of the input contains an integer N denoting the number of triangles. Each of the following N
lines contain six space separated integers x1 y1 x2 y2 x3 y3 where (x1, y1),
(x2, y2) and (x3, y3) are the vertices of a triangle.

 
Output

Output one integer, the number of right triangles among the given triangles.

 
Constraints

    1 ≤ N ≤ 100000 (10^5)
    0 ≤ x1, y1, x2, y2, x3, y3 ≤ 20

 
Example

Input:
5
0 5 19 5 0 0
17 19 12 16 19 0
5 14 6 13 8 7
0 4 0 14 3 14
0 2 0 14 9 2

Output:
3

 
Explanation

The first triangle and the last two triangles of the example are right triangles.

'''
