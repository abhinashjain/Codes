#include "stdio.h"

int main()
{
    char key[1000], cipher[1000];
    int i, j=0, keylen, cipherlen, tmp1, tmp2;
    scanf("%s",key);
    scanf("%s",cipher);
    keylen=strlen(key);
    cipherlen=strlen(cipher);
    for(i=0;i<cipherlen;i+=2)
    {
        char c[4];
        strcpy(c,"0x");
        c[2]=cipher[i];
        c[3]=cipher[i+1];
        tmp1=key[j%keylen];
        tmp2=strtol(c,NULL,0);
        printf("%c",tmp1^tmp2);
        j++;
    }
    return 0;
}


/*

You are a budding hacker and you somehow have access to a stream of encrypted data. You are given access to the cipher key and told that the stream of encrypted information is encrypted
using Repeating Key XOR cipher. The key changes every 24 hours.
 
Given an encrypted text and also the key used, can you generate the original text back?
 
Input Format
The first line of input is the cipher key and the second line of input is the cipher text in it's hex format.
 
Constraints
1 <= len(cipher key) <= 1000
1 <= len(cipher text) <= 1000
All cipher keys are ASCII characters.
 
Output Format
Print the decoded original text.
 
Sample Input
hacker
0000000000001a000d00

Sample Output
hackerrank

Explanation
Using the key hacker on the encrypted text 0000000000001a000d00, the decrypted text is hackerrank

*/