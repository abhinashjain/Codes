#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

arr=list(raw_input())
e=int(raw_input())
length=len(arr)
for i in xrange(length):
    arr[i]=(int(arr[i])+e)%10
for i in xrange(length):
    stdout.write(str(arr[i])+"")



'''

K denotes a set called the key space. Any element of K is called a key.

Each element e (belongs to K) uniquely determines a bijection from M to C, denoted by Ee. The Ee is called an encryption function. Similarly for each d (belongs to K), we have a bijection 
from C to M, denoted by Dd, and it is called a decryption function.

For example, consider the same shifting function that we dealt with in the previous challenge. Now, suppose the amount of shifting we do is some e. In the last challenge, e=1. Then e is a 
valid key representing the bijective function f(x,e) = shift_x_by_e.

For this task, consider a message that consists of decimal digits and a key, e, which operates by shifting each digit by e places. Find the corresponding ciphertext.

Constraints
1 <= Length of the string <=10
0 <= e <= 9

Input Format
The input consists of 2 lines.
The first line contains the message string.
The second line contains the key e.

Output Format
Output a single line that contains the cipher obtained by shifting each digit e places.

Sample Input
391
2

Sample Output
513

'''