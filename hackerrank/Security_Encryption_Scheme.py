#!/usr/bin/python
# coding: utf-8

n=int(raw_input())
prod=1
for i in xrange(1,n+1):
	prod*=i
print prod


'''

An encryption scheme consists of a set {Ee : e belongs to K} and a corresponding set {Dd : d belongs to K} of encrypting and decrypting functions, respectively.
For each e belongs to K, there is a unique key d belongs to K where Dd=(Ee)^(-1). (i.e. Ee and Dd are inverse function.)
An encryption scheme is also called a cipher.

It should be clear that every e is actually a representative of some bijection from M to C. 
In this task, you have to count the number of such bijections and, hence, the number of keys that produce different encryption functions.

Assume that |M| = |C| = n which is given as the input.

Constraints
1 <= n <= 10

Input Format
The input consists of a single positive integer n.

Output Format
Output a single positive integer, the number of bijections.

Sample Input
3

Sample Output
6

Explanation
Let us assume that M = {1,2,3} and C = {3,2,1}.
We can have encryption schemes where 1 can be mapped to 3 or 2 or 1, 2 can be mapped to the remaining two, and 3 can be mapped to the unmapped one.

This accounts for 3 * 2 * 1 = 6 such encryption functions.
    
'''