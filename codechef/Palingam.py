#!/usr/bin/python
# coding: utf-8

t=int(raw_input())
for i in xrange(t):
    s=raw_input()
    t=raw_input()
    sarr=[0]*26
    tarr=[0]*26
    for j in s:
        ind=ord(j)-97
        sarr[ind]+=1
    for j in t:
        ind=ord(j)-97
        tarr[ind]+=1
    bwin=1
    for j in xrange(26):
        if(tarr[j]==0 and sarr[j]>0):
            bwin=0
            break
    if(bwin):
        print "B"
    else:
        awin=0
        for j in xrange(26):
            if(tarr[j]==0):
                if(sarr[j]>1):
                    awin=1
                    break
        if(awin):
            print "A"
        else:
            awin=bwin=0
            for j in xrange(26):
                if(tarr[j]==0):
                    if(sarr[j]==1):
                        sarr[j]=0
                        break
            for j in xrange(26):
                if(sarr[j]==0):
                    if(tarr[j]>0):
                        bwin=1
                        break
            if(bwin):
                print "B"
            else:
                print "A"


'''

There are two players A, B playing a game. Player A has a string s with him, and player B has string t with him. Both s and t consist only of lower case English letters and are of 
equal length. A makes the first move, then B, then A, and so on alternatively. Before the start of the game, the players know the content of both the strings s and t.

These players are building one other string w during the game. Initially, the string w is empty. In each move, a player removes any one character from their respective string and
adds this character anywhere (at any position) in the string w (Note that w is a string at all times, and you can insert between characters or at the ends. It is not an empty
array where you can add a character at any index. Please see the Explanations for further clarification). If at any stage of the game, the string w is of length greater than 1
and is a palindrome, then the player who made the last move wins.

If even after the game finishes (ie. when both s and t have become empty strings), no one is able to make the string w a palindrome, then player B wins.

Given the strings s, and t, find out which of A, B will win the game, if both play optimally.

Input
The first line of the input contains an integer T, corresponding to the number of test cases. The description of each testcase follows.
The first line of each testcase will contain the string s.
The second line of each testcase will contain the string t.

Output
For each test case, output "A" or "B" (without quotes) corresponding to the situation, in a new line.

Constraints
Subtask 1 (20 points) : 1 ≤ T ≤ 500, All characters of string s are equal, All characters of string t are equal. 1 ≤ |s| = |t| ≤ 500
Subtask 2 (80 points) : 1 ≤ T ≤ 500, 1 ≤ |s| = |t| ≤ 500

Example
Input:
3
ab
ab
aba
cde
ab
cd

Output:
B
A
B

Explanation
Testcase 1: If A adds 'a' to w in the first move, B can add 'a' and make the string w = "aa", which is a palindrome, and hence win. Similarly, you can show that no matter what A 
plays, B can win. Hence the answer is B.

Testcase 2: Player A moves with 'a', player B can put any of the character 'c', 'd' or 'e', Now Player A can create a palindrome by adding 'a'.

Testcase 3: None of the players will be able to make a palindrome of length > 1. So B will win.

'''
