#!/bin/python
# coding: utf-8

def solve(s, k):
    arr=[0]*26
    start=[-1]*26
    end=[-1]*26
    length=len(s)
    for i in xrange(length):
        ind=ord(s[i])-97
        arr[ind]+=1
        if(start[ind]==-1):
            start[ind]=i
        end[ind]=i
    
    ch=""
    for i in xrange(25,-1,-1):
        if(arr[i]>=k):
            ch=chr(97+i)
            break

    st=start[ord(ch)-97]
    for i in xrange(st):
        ind=ord(s[i])-97
        arr[ind]-=1

    ans=""
    for i in xrange(st,length):
        ind=ord(s[i])-97
        if(s[i]==ch):
            ans+=s[i]
        elif(s[i]>ch and arr[ind]>=k):
            ans+=s[i]
        elif(s[i]<ch and arr[ind]>=k):
            if(i>end[ord(ch)-97]):
                tmp=1
                for j in xrange(26):
                    if(chr(j+97)>s[i] and end[j]>i):
                        tmp=0
                        break
                if(tmp):
                    ans+=s[i]
                else:
                    arr[ind]-=1
            else:
                arr[ind]-=1
    return ans

if __name__ == "__main__":
    s = raw_input().strip()
    k = int(raw_input().strip())
    result = solve(s, k)
    print result


'''

You have a string s and an integer k. You have to find another string t which have the following properties:

1. t must be a subsequence of s.
2. Every character in t must occur at least k times.
3. t must be lexicographically largest.

Your task is to find and print the string t.

For example, let's say the string is s=hackerrank and k=1.

                                            Finding_Subsequence_1.png

The solution for this is t=rrnk. Here t is a subsequence of s and contains the characters r, n and k, each of them occurs at least k=1 times.

Input Format
The first line conatins a string s denoting the original string.
The second line contains an integer k.

Constraints
1<=|s|<=10^5
1<=k<=10^5
String s will only contain lowercase english letters.
Input will be such that for every input there is a valid solution.

Output Format
Print the string t on a single line.

Sample Input 0
hackerrank
1

Sample Output 0
rrnk

Explanation 0
Here all possible subsequences are valid but rrnk is the lexicographically largest one.

Sample Input 1
banana
2

Sample Output 1
nn

Explanation 1
Here are four possible subsequences where each chracter exists at least k=2 times:

                                            Finding_Subsequence_2.png

From the above subsequences, nn is the laxicographically largest.

'''
