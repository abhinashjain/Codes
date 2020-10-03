#!/usr/bin/python
# coding: utf-8

f=0
arr=[]
for i in xrange(26):
    arr.append(0)
str=raw_input()
length=len(str)
for i in xrange(length):
    ind=ord(str[i])-ord('a')
    for j in xrange(ind):
        if(arr[j]==0):
            f=1;
            break;
    arr[ind]=1
if(f):
    print "NO"
else:
    print "YES"


'''

Kostya likes Codeforces contests very much. However, he is very disappointed that his solutions are frequently hacked. That's why he decided to obfuscate (intentionally make less 
readable) his code before upcoming contest.

To obfuscate the code, Kostya first looks at the first variable name used in his program and replaces all its occurrences with a single symbol a, then he looks at the second variable 
name that has not been replaced yet, and replaces all its occurrences with b, and so on. Kostya is well-mannered, so he doesn't use any one-letter names before obfuscation. Moreover, 
there are at most 26 unique identifiers in his programs.

You are given a list of identifiers of some program with removed spaces and line breaks. Check if this program can be a result of Kostya's obfuscation.

Input
In the only line of input there is a string S of lowercase English letters (1 ≤ |S| ≤ 500) — the identifiers of a program with removed whitespace characters.

Output
If this program can be a result of Kostya's obfuscation, print "YES" (without quotes), otherwise print "NO".

Examples
Input
abacaba

Output
YES

Input
jinotega

Output
NO

Note
In the first sample case, one possible list of identifiers would be "number string number character number string number". Here how Kostya would obfuscate the program:

1. replace all occurences of number with a, the result would be "a string a character a string a",
2. replace all occurences of string with b, the result would be "a b a character a b a",
3. replace all occurences of character with c, the result would be "a b a c a b a",
4. all identifiers have been replaced, thus the obfuscation is finished.

'''
