#!/usr/bin/python
# coding: utf-8
from sys import stdin, stdout

def main():
	sqnmod=[2]
	for i in range(1,65):
		j=i-1
		p=(sqnmod[j]**2)%1000000007
		sqnmod.append(p)
	t=int(raw_input())
	list=stdin.readlines()
	for n in list:
		n=int(n)
		binofn=int(bin(n)[2:])
		binofbin=bin(binofn)[2:]
		rev=binofbin[::-1] #reverses the string
		ans=1
		for ind, val in enumerate(rev):
			if(val=='1'):
				ans=(ans*sqnmod[ind])%1000000007
		stdout.write(str((ans**2)%1000000007)+"\n")
#		print (ans**2)%1000000007

if __name__ == "__main__":
	main()

'''

Cyael is a very gifted girl who loves Magic (she even reached the finals on a very famous tournament in Byteland ;) ) and Computer Science. As we know, CS is a very vast subject and Cyael learns what she can, little by little, by reading the editorials of codechef.com, her favourite programming website.

Today, she came across a problem that was about calculating powers of two, and she got bored of it really fast, as she considers she knows all there is to know about powers of two. She knows how to compute even very big powers, like powers of 10, so it's obvious that for her, powers of two have no secrets :D

But her friend Lira, as she was tired of hearing her boasting about her skills for calculating powers, decided to challenge her with a brand new task: computing what she calls, SuperPowers of 2 .

Cyael: "Okay Lira, tell me about SuperPower of 2 so that I can solve one more problem and prepare for Codechef's November Long Challenge!! It's less than a month away!"

Lira: "I define the Nth Superpower of 2 as being the number (2^N_bin)^2 , where N_bin stands for the decimal number encoded by the representation in base 2 of the number N.

So, for example, the 2nd SuperPower of 2 is then equal to the number:

(2^10)^2 = 1048576

because, N = 2 , and its binary encoding is 10 in decimal it is ten. So 2^10 = 1024 and 1024^2 = 1048576

Since the answer can be large, you are asked to compute SuperPowers of 2 modulo 1000000007."

After some time, Cyael finally solved the problem and decided to call Lira:

Cyael: "Well, I admit I struggled more than I'd have expected on this problem... You should consider becoming a problem setter and set this problem for Codechef... Do you want me to call Bruno and ask him to set this problem on your behalf? He always finds a way of writing a fun problem statement!!"

Lira: "Wooow!! That means Codechef community would solve my problem, modified by Bruno himself? Please do so, I'd love it!!!"

And now, here I am (yes, Bruno :D ) setting Lira's problem to all of you, but, with some differences regarding Lira's initial version, which hopefully you will appreciate.
Input

The first line of the input contains an integer T denoting the number of test cases.

Then on the following T lines, there is an integer N, denoting the index of the SuperPower of 2 you need to compute modulo 1000000007.
Output

For each test case, output a single line containing the required value: the Nth SuperPower of 2 modulo 1000000007.
Constraints

    1 ≤ N ≤ 600000
    T = 100000 on each official test-case file.
    Note: Your code will be judged against several input files. 

Example
Input:
2
1
2

Output:
4
1048576

'''
