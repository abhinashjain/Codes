#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int arr[10000001]={0};
int main()
{
    int n,x,i,j,len,ind;
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        ind=(s[i]-'a')+1;
        arr[ind]=1;
        j=i+1;
        while(j<len && s[i]==s[j])
        {
            ind+=(s[i]-'a')+1;
            arr[ind]=1;
            j++;
        }
        i=j-1;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(arr[x]==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}


/*

A weighted string is a string of lowercase English letters where each letter has a weight in the inclusive range from 1 to 26, defined below:

        Weighted_Uniform_Strings_1.png
 
We define the following terms:
1. The weight of a string is the sum of the weights of all the string's characters. For example:
    
        Weighted_Uniform_Strings_2.png

2. A uniform string is a string consisting of a single character repeated zero or more times. For example, ccc and a are uniform strings, but bcb and cd are not (i.e., they consist 
of more than one distinct character).
 
Given a string, s, let U be the set of weights for all possible uniform substrings (contiguous) of string s. You have to answer n queries, where each query i consists of a single 
integer, xi. For each query, print Yes on a new line if xi is an element of set U; otherwise, print No instead.
 
Input Format
The first line contains a string denoting s (the original string).
The second line contains an integer denoting n (the number of queries).
Each line i of the n subsequent lines contains an integer denoting xi (the weight of a uniform subtring of s that may or may not exist).
 
Constraints
1<=|s|,n<=10^5
1<=xi<=10^7
s will only contain lowercase English letters.
 
Output Format
For each xi, print Yes on a new line if xi is an element of set U; otherwise, print No instead.
 
Sample Input 0
abccddde
6
1
3
12
5
9
10
 
Sample Output 0
Yes
Yes
Yes
Yes
No
No
 
Explanation 0
The weights of every possible uniform substring in the string abccddde are shown below:

        Weighted_Uniform_Strings_3.png
 
We print Yes on the first four lines because the first four queries match weights of uniform substrings of s. We print No for the last two queries because there are no uniform 
substrings in s that have those weights.
 
Note that while de is a substring of s that would have a weight of 9, it is not a uniform substring.
 
Note that we are only dealing with contiguous substrings. So ccc is not a substring of the string ccxxc.

*/
