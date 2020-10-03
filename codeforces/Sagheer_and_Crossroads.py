#!/usr/bin/python
# coding: utf-8

(l1,s1,r1,p1)=map(int,raw_input().split(' '))
(l2,s2,r2,p2)=map(int,raw_input().split(' '))
(l3,s3,r3,p3)=map(int,raw_input().split(' '))
(l4,s4,r4,p4)=map(int,raw_input().split(' '))
accident=0
if(p1):
    if(l1 or s1 or r1 or l2 or s3 or r4):
        accident=1
if(accident==0 and p2):
    if(l2 or s2 or r2 or l3 or s4 or r1):
        accident=1
if(accident==0 and p3):
    if(l3 or s3 or r3 or l4 or s1 or r2):
        accident=1
if(accident==0 and p4):
    if(l4 or s4 or r4 or l1 or s2 or r3):
        accident=1
if(accident):
    print "YES"
else:
    print "NO"


'''

Sagheer is walking in the street when he comes to an intersection of two roads. Each road can be represented as two parts where each part has 3 lanes getting into the intersection 
(one for each direction) and 3 lanes getting out of the intersection, so we have 4 parts in total. Each part has 4 lights, one for each lane getting into the intersection (l —
left, s — straight, r — right) and a light p for a pedestrian crossing.

                                            Sagheer_and_Crossroads.png
                                            
An accident is possible if a car can hit a pedestrian. This can happen if the light of a pedestrian crossing of some part and the light of a lane that can get to or from that same 
part are green at the same time.

Now, Sagheer is monitoring the configuration of the traffic lights. Your task is to help him detect whether an accident is possible.

Input
The input consists of four lines with each line describing a road part given in a counter-clockwise order.
Each line contains four integers l, s, r, p — for the left, straight, right and pedestrian lights, respectively. The possible values are 0 for red light and 1 for green light.

Output
On a single line, print "YES" if an accident is possible, and "NO" otherwise.

Examples
Input
1 0 0 1
0 1 0 0
0 0 1 0
0 0 0 1

Output
YES

Input
0 1 1 0
1 0 1 0
1 1 0 0
0 0 0 1

Output
NO

Input
1 0 0 0
0 0 0 1
0 0 0 0
1 0 1 0

Output
NO

Note
In the first example, some accidents are possible because cars of part 1 can hit pedestrians of parts 1 and 4. Also, cars of parts 2 and 3 can hit pedestrians of part 4.

In the second example, no car can pass the pedestrian crossing of part 4 which is the only green pedestrian light. So, no accident can occur.
'''
