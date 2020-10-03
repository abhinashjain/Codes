#include "string"
#include "algorithm"
using namespace std;

class EllysSquareWords
{
    public:
        int getScore(string S)
        {
            string::iterator iter;
            int arr[26]={0}, ind, i, ans;
            for(iter=S.begin();iter!=S.end();iter++)
            {
                ind=(*iter)-'A';
                arr[ind]++;
            }
            ans=0;
            sort(arr,arr+26);
            arr[25]+=arr[24];
            arr[24]=0;
            for(i=0;i<26;i++)
            {
                ans+=arr[i]*arr[i];
            }
            return ans;
        }
};


/*

Elly has a S containing uppercase letters from the English alphabet. The girl can either do nothing, or she can take exactly one action: she can change all occurrences of one letter
into another letter (e.g., change all 'T's into 'C's). The "score" of the resulting word is defined as the sum of the squared number of occurrences of each letter.

For example, let's S = "TOPCODERROCKS". It has one 'T', three 'O's, one 'P', two 'C's, one 'D', one 'E', two 'R's, one 'K', and one 'S'. Thus, if the girl doesn't change any letter
the score of the word would be 1*1 + 3*3 + 1*1 + 2*2 + 1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 23. However, if the girl chooses to change the 'R's into 'S's she would get "TOPCODESSOCKS"
with score 27. Even better, if she changes the 'C's into 'O's she would get "TOPOODERROOKS" with score 35.

Now the girl wonders what is the maximal score that can be achieved for various words. Help her by writing a program, that given the S returns the maximal score after at most one
change of letters.

Constraints
- S will contain between 1 and 50 characters, inclusive.
- Each character of S will be an uppercase letter from the English alphabet ('A'-'Z').

Examples
0)
"TOPCODERROCKS"
Returns: 35
The sample from the problem statement.

1)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
Returns: 28
This time S contains each letter of the English alphabet exactly once. Elly should change any letter into any other letter.

2)
"AWOIDUIWAHCSZNGAIOWIAWEWIUYTIUEAXKLMFCAWMAWVAWUBVA"
Returns: 374
Random keystrokes on the keyboard.

3)
"ROVERWANDERERNOMADVAGABOND"
Returns: 108

4)
"WITHOUTITIMJUSTESPR"
Returns: 65

*/
