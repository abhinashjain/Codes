#include "string"
using namespace std;

class EllysAnagrams
{
    public:
        int getCount(string A, string B)
        {
            string::iterator iter;
            int arrA[26]={0}, arrB[26]={0}, arr[26]={0}, ind, i, j, f, cnt, ans=0;
            for(iter=A.begin();iter!=A.end();iter++)
            {
                ind=(*iter)-'A';
                arrA[ind]++;
            }
            for(iter=B.begin();iter!=B.end();iter++)
            {
                ind=(*iter)-'A';
                arrB[ind]++;
            }
            for(i=0;i<26;i++)
            {
                arr[i]=arrB[i]-arrA[i];
            }
            for(i=0;i<26;i++)
            {
                while(arr[i]<0)
                {
                    arr[i]++;
                    cnt=f=0;
                    for(j=i+1;j<26;j++)
                    {
                        cnt++;
                        if(arr[j]>0)
                        {
                            f=1;
                            arr[j]--;
                            break;
                        }
                    }
                    if(!f)
                    {
                        for(j=0;j<i;j++)
                        {
                            cnt++;
                            if(arr[j]>0)
                            {
                                arr[j]--;
                                break;
                            }
                        }
                    }
                    ans+=cnt;
                }
            }
            return ans;
        }
};


/*

Elly has two strings of the same length: A and B. Now she wants to transform A into an anagram of B by changing some of its letters. The only operation the girl can make is to
increment some (possibly none or all) characters in A. E.g., she can change an 'A' to a 'B', or a 'K' to an 'L'. She can increment each character arbitrarily many times. E.g., she
can increment an 'A' three times to get a 'D'. The incrementation is cyclic: if she increments a 'Z', she gets an 'A' again.

For example, she can transform "ELLY" to "KRIS" character by character by shifting 'E' to 'K' (6 operations), 'L' to 'R' (again 6 operations), the second 'L' to 'I'
(23 operations, going from 'Z' to 'A' on the 15-th operation), and finally 'Y' to 'S' (20 operations, again cyclically going from 'Z' to 'A' on the 2-nd operation). 
The total number of operations would be 6 + 6 + 23 + 20 = 55. However, to make "ELLY" an anagram of "KRIS" it would be better to change it to "IRSK" with only 29 operations.

You are given the s A and B. Find the minimal number of operations needed to transform A into some other string X, such that X is an anagram of B.

Notes
- We call two strings X and Y anagrams of each-other if we can re-arrange the letters in one of them to get the other.

Constraints
- A and B will be between 1 and 50 characters long.
- A and B will have the same length.
- A and B will contain only uppercase letters from the English alphabet ('A'-'Z').

Examples
0)
"ELLY"
"KRIS"
Returns: 29
The example from the problem statement.

1)
"TOPCODER"
"TCOINDIA"
Returns: 57
Several of the letters are present in both strings.

2)
"HARDEST"
"THREADS"
Returns: 0
The first string is already an anagram of the second.

3)
"AAAAAAAAAA"
"ZZZZZZZZZZ"
Returns: 250
Some strings may require many operations.

4)
"AWIODJGWAMBAUWNMQEROAIQWYRZSVEPTT"
"BNSIAELDALCGAWOPIWEQTYCNAZEKJXVYU"
Returns: 105
Random keystrokes.

*/
