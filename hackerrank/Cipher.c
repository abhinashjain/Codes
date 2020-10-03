#include "stdio.h"

int main()
{
    int n,k,i,len,cnt,ind,tmp,val;
	scanf("%d %d",&n,&k);
    int plain[n];
    len=n+k-1;
    char cipher[len];
    scanf("%s",cipher);
    plain[0]=cipher[0]-'0';
    plain[n-1]=cipher[len-1]-'0';
    cnt=2;
    for(i=1;i<k;i++)
    {
        plain[i]=(cipher[i-1]-'0')^(cipher[i]-'0');
        plain[n-(i+1)]=(cipher[len-(i+1)]-'0')^(cipher[len-i]-'0');
        cnt+=2;
    }
    tmp=k;
    while(cnt<n)
    {
        val=cipher[tmp]-'0';
        for(i=1;i<k;i++)
        {
            ind=tmp-i;
            if(ind<0)
                break;
            val=val^plain[ind];
        }
        plain[tmp]=val;
        cnt++;
        tmp++;
    }
    for(i=0;i<n;i++)
        printf("%d",plain[i]);
	return 0;
}


/*

Jack and Daniel are friends.
They want to encrypt their conversation so that they can save themselves from interception by a detective agency. So they invent a new cipher.
Every message is encoded to its binary representation B of length N.
Then it is written down K times, shifted by 0,1,...,K-1 bits.
If B=1001010 and K=4 it looks so:
 
1001010
 1001010
  1001010
   1001010
 
Then calculate XOR in every column and write it down. This number is called S. For example, XOR-ing the numbers in the above example results in
 
1110100110
 
Then the encoded message S and K are sent to Daniel.
 
Jack is using this encoding algorithm and asks Daniel to implement a decoding algorithm.
Can you help Daniel implement this?
 
Input Format
The first line contains two integers N and K.
The second line contains string S of length N+K-1 consisting of ones and zeros.
 
Output Format
Decoded message of length N, consisting of ones and zeros.
 
Constraints
1<=N<=10^6
1<=K<=10^6
|S|=N+K-1
It is guaranteed that is correct.
 
Sample Input#00
7 4
1110100110
 
Sample Output#00
1001010
 
Sample Input#01
6 2
1110001
 
Sample Output#01
101111
 
Explanation
Input#00
1001010
 1001010
  1001010
   1001010
----------
1110100110
 
Input#01
101111
 101111
-------
1110001

*/
