#include "stdio.h"

int main()
{
    int q,i;
    long long l,r;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%lld %lld",&l,&r);
        if(r%8==0 || r%8==1)
            r=r;
        if(r%8==6 || r%8==7)
            r=0;
        if(r%8==2 || r%8==3)
            r=2;
        if(r%8==4 || r%8==5)
            r=r+2;

        l--;
        if(l%8==0 || l%8==1)
            l=l;
        if(l%8==6 || l%8==7)
            l=0;
        if(l%8==2 || l%8==3)
            l=2;
        if(l%8==4 || l%8==5)
            l=l+2;
        printf("%lld\n",r^l);
    }
    return 0;
}


/*

An array, A, is defined as follows:
A[0]=0
A[x]=A[x-1] xor x for x>0, where xor is the symbol for XOR
 
You must answer Q questions. Each ith question, is in the form Li Ri, and the answer is 
A[Li] xor A[Li+1] xor ... xor A[Ri-1] xor A[Ri] (the Xor-Sum of segment [Li,Ri]).
 
Print the answer to each question.
 
Input Format
The first line contains Q (the number of questions).
The Q subsequent lines each contain two space separated integers, L and R, respectively. Line contains Li and Ri.
 
Constraints
1<=Q<=10^5
1<=Li<=Ri<=10^15
 
Subtasks
For 50% score: 1<=Li<=Ri<=10^5
 
Output Format
On a new line for each test case i, print the exclusive-or of A's elements in the inclusive range between indices Li and Ri.
 
Sample Input
3
2 4
2 8
5 9
 
Sample Output
7
9
15
 
Explanation
The beginning of our array looks like this: A=[0,1,3,0,4,1,7,0,8,1,11,...]
 
Test Case 0:
3 xor 0 xor 4 = 7
 
Test Case 1:
3 xor 0 xor 4 xor 1 xor 7 xor 0 xor 8 = 9
 
Test Case 2:
1 xor 7 xor 0 xor 8 xor 1 = 15

*/
