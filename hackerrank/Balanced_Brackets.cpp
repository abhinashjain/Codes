#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stack"
using namespace std;

int main()
{
    int i,j,n,len;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char* s=(char *)malloc(512000 * sizeof(char));
        scanf("%s",s);
        len=strlen(s);
        stack<char> mystack;
        for(j=0;j<len;j++)
        {
            if(s[j]=='(' || s[j]=='[' || s[j]=='{')
            {
                mystack.push(s[j]);
            }
            else
            {
                if(!mystack.empty() && ((mystack.top()=='(' && s[j]==')') || (mystack.top()=='[' && s[j]==']') || (mystack.top()=='{' && s[j]=='}')))
                {
                    mystack.pop();
                }
                else
                {
                    j=-1;
                    break;
                }
            }
        }
        if(j!=-1 && mystack.empty())
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}


/*

A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
 
Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type.
There are three types of matched pairs of brackets: [], {}, and ().
 
A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not
balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].
 
By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:
1. It contains no unmatched brackets.
2. The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
 
Given n strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, print YES on a new line; otherwise, print NO on a new line.
 
Input Format
The first line contains a single integer, n, denoting the number of strings.
Each line i of the n subsequent lines consists of a single string, s, denoting a sequence of brackets.
 
Constraints
1<=n<=10^3
1<=length(s)<=10^3, where length(s) is the length of the sequence.
Each character in the sequence will be a bracket (i.e., {, }, (, ), [, and ]).
 
Output Format
For each string, print whether or not the string of brackets is balanced on a new line. If the brackets are balanced, print YES; otherwise, print NO.
 
Sample Input
3
{[()]}
{[(])}
{{[[(())]]}}
 
Sample Output
YES
NO
YES
 
Explanation
The string {[()]} meets both criteria for being a balanced string, so we print YES on a new line.
The string {[(])} is not balanced, because the brackets enclosed by the matched pairs [(] and (]) are not balanced. Thus, we print NO on a new line.
The string {{[[(())]]}} meets both criteria for being a balanced string, so we print YES on a new line.

*/
