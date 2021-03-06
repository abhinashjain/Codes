#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in range(t):
	c,d=raw_input().split(' ')
	c=int(c)
	d=int(d)
	x=c*d-c-d
	print x


'''
In the country of Numberia, there is a city called Primeland. Sherry is one of the rich inhabitants of the city, who likes to collect coins of various denominations. Coins in primeland are little strange , they are only available in prime denominations (i.e as coins of value 2,3,5 etc.).Sherry is taking a tour of the country but as he visits people ask him for change, unfortunately Sherry took coins of only two kinds of denominations(the coins are of Primeland), he has already made a lot of such changes but then he wonders what is the maximum amount which he can't give change for using the coins he has.Remember he has coins of only two different denominations and has infinite number of them..

 
Input

First line of input will contain number of testcases,T.Following T lines will contain two integers c and d separated by a space denoting the denominations which sherry has while he is on the tour, both c and d are guaranteed to be prime.
 
Output

For each of the T testcases output one number per line the maximum amount which sherry can't afford to give change for.
Constraints

    1 ≤ T ≤ 100
    2 ≤ c,d ≤ 10^6

 
Example

Input:
2
3 5
2 3

Output:
7
1

 
Explanation

For Test Case 1 :

We see that 2 cannot be paid using coins of value 3 and 5.
In fact we can pay the following series of numbers using coins of value 3 and 5.

3,5,6,8,9,10.....and so on.

Clearly we cannot make change for 1,2,4,7. Out of these numbers 7 is maximum therefore 7 is the correct answer.
Basically find the list of numbers for which change can't be made using the two coins given in the input and print the maximum of those numbers as your answer.
'''
