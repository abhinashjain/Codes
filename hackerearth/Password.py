#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

def main():
	n=int(raw_input())
	list=stdin.readlines()
	list=[pwd.strip() for pwd in list]
	for pwd in list:
		rev=pwd[::-1]
		if rev in list:
			l=len(pwd)
			m=pwd[l/2]
			stdout.write(str(l)+" "+m+"\n")
			break

if __name__ == "__main__":
	main()
	


'''

Danny has a possible list of passwords of Manny's facebook account. All passwords length is odd. But Danny knows that Manny is a big fan of palindromes. So, his password and reverse of his password both should be in the list.

You have to print the length of Manny's password and it's middle character.

Note : The solution will be unique.

INPUT
The first line of input contains the integer N, the number of possible passwords.
Each of the following N lines contains a single word, its length being an odd number greater than 2 and lesser than 14. All characters are lowercase letters of the English alphabet.

OUTPUT
The first and only line of output must contain the length of the correct password and its central letter.

CONSTRAINTS
1 ≤ N ≤ 100

Sample Input
4
abc
def
feg
cba

Sample Output
3 b

'''
