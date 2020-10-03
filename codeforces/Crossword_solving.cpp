#include "stdio.h"
#include "vector"
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define reverse_rep(i,end,begin) for(i=end;i>=begin;i--)
using namespace std;

int main()
{
    int i,j,k,l,n,m,ans=1000000,cnt,len;
    vector<int> vect;
    vector<int>::iterator it;
    scanf("%d %d",&n,&m);
    char s[n],t[m];
    scanf("%s",s);
    scanf("%s",t);
    len=m-n+1;
    rep(i,0,len)
    {
        l=i+n;
        k=cnt=0;
        vector<int> vect2;
        rep(j,i,l)
        {
            if(t[j]!=s[k])
            {
                cnt++;
                vect2.push_back(k);
            }
            k++;
        }
        if(cnt<ans)
        {
            ans=cnt;
            vect=vect2;
            if(ans==0)
            {
                break;
            }
        }
    }
    printf("%d\n",ans);
    if(vect.size()!=0)
    {
        printf("%d",(*(vect.begin()))+1);
        for(it=vect.begin()+1;it!=vect.end();it++)
        {
            printf(" %d",(*it)+1);
        }
    }
    return 0;
}


/*

Erelong Leha was bored by calculating of the greatest common divisor of two factorials. Therefore he decided to solve some crosswords. It's well known that it is a very interesting
occupation though it can be very difficult from time to time. In the course of solving one of the crosswords, Leha had to solve a simple task. You are able to do it too, aren't
you?

Leha has two strings s and t. The hacker wants to change the string s at such way, that it can be found in t as a substring. All the changes should be the following: Leha chooses one
position in the string s and replaces the symbol in this position with the question mark "?". The hacker is sure that the question mark in comparison can play the role of an
arbitrary symbol. For example, if he gets string s="ab?b" as a result, it will appear in t="aabrbb" as a substring.

Guaranteed that the length of the string s doesn't exceed the length of the string t. Help the hacker to replace in s as few symbols as possible so that the result of the
replacements can be found in t as a substring. The symbol "?" should be considered equal to any other symbol.

Input
The first line contains two integers n and m (1 ≤ n ≤ m ≤ 1000) — the length of the string s and the length of the string t correspondingly.
The second line contains n lowercase English letters — string s.
The third line contains m lowercase English letters — string t.

Output
In the first line print single integer k — the minimal number of symbols that need to be replaced.
In the second line print k distinct integers denoting the positions of symbols in the string s which need to be replaced. Print the positions in any order. If there are several
solutions print any of them. The numbering of the positions begins from one.

Examples
Input
3 5
abc
xaybz

Output
2
2 3

Input
4 10
abcd
ebceabazcd

Output
1
2

*/
