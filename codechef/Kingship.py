#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

t=int(raw_input())
list=stdin.readlines()
for i in range(0,len(list),2):
	n=int(list[i])
	p=list[i+1]
	arr=map(int,p.split())
	arr.sort()
	minsum=0
	for item in arr:
		minsum+=(item*arr[0])
	minsum-=arr[0]*arr[0]
	stdout.write(str(minsum)+"\n")
	

'''

Chef is the new king of the country Chefland. As first and most important responsibility he wants to reconstruct the road system of Chefland. There are N (1 to N) cities in the country and each city i has a population Pi. Chef wants to build some bi-directional roads connecting different cities such that each city is connected to every other city (by a direct road or through some other intermediate city) and starting from any city one can visit every other city in the country through these roads. Cost of building a road between two cities u and v is Pu x Pv. Cost to build the road system is the sum of cost of every individual road that would be built.

Help king Chef to find the minimum cost to build the new road system in Chefland such that every city is connected to each other.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
First line contains an integer N denoting the number of cities in the country. Second line contains N space separated integers Pi, the population of i-th city.

Output
For each test case, print a single integer, the minimum cost to build the new road system on separate line.

Constraints
    1 ≤ T ≤ 10
    1 ≤ N ≤ 10^5
    1 ≤ Pi ≤ 10^6

Example
Input:
2
2
5 10
4
15 10 7 13

Output:
50
266

'''
