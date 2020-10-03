#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
    int q,len,i,j,t,tmp,cnt;
    scanf("%d",&q);
    char* ch="hackerrank";
    for(t=0;t<q;t++)
    {
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s",s);
        len=strlen(s);
        tmp=cnt=0;
        for(i=0;i<10;i++)
        {
            for(j=tmp;j<len;j++)
            {
                if(s[j]==ch[i])
                {
                    cnt++;
                    tmp=j+1;
                    break;
                }
            }
        }
        if(cnt==10)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


/*

We say that a string, s, contains the word hackerrank if a subsequence of the characters in s spell the word hackerrank. For example, haacckkerrannkk does contain hackerrank, but
haacckkerannk does not (the characters all appear in the same order, but it's missing a second r).

More formally, let p0,p1,...,p9 be the respective indices of h, a, c, k, e, r, r, a, n, k in string s. If p0<p1<...<p9 is true, then s contains hackerrank.

You must answer q queries, where each query i consists of a string, si. For each query, print YES on a new line if si contains hackerrank; otherwise, print NO instead.

Input Format
The first line contains an integer denoting q (the number of queries).
Each line i of the q subsequent lines contains a single string denoting si.

Constraints
2<=q<=10^2
10<=|si|<=10^4

Output Format
For each query, print YES on a new line if si contains hackerrank; otherwise, print NO instead.
 
Sample Input 0
2
hereiamstackerrank
hackerworld
 
Sample Output 0
YES
NO
 
Explanation 0
We perform the following q=2 queries:

1. s = hereiamstackerrank
 The characters of hackerrank are bolded in the string above. Because the string contains all the characters in hackerrank in the same exact order as they appear in hackerrank, we
 print YES on a new line.
 
2. s = hackerworld does not contain the last four characters of hackerrank, so we print NO on a new line.

*/
