#include "stdio.h"

int main()
{
    int i,n,tmp,cnt=0,arr[101]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        arr[tmp]++;
    }
    for(i=1;i<101;i++)
        if(arr[i]>0)
            cnt+=arr[i]/2;
    printf("%d\n",cnt);
	return 0;
}


/*

John's clothing store has a pile of n loose socks where each sock i is labeled with an integer, Ci, denoting 
its color. He wants to sell as many socks as possible, but his customers
will only buy them in matching pairs. Two socks, i and j, are a single matching pair if Ci = Cj.
 
Given n and the color of each sock, how many pairs of socks can John sell?
 
Input Format
The first line contains an integer, n, denoting the number of socks.
The second line contains n space-separated integers describing the respective values of C0,C1,C2,...,Cn-1.
 
Constraints
1<=n<=10
1<=Ci<=10

Output Format
Print the total number of matching pairs of socks that John can sell.
 
Sample Input
9
10 20 20 10 10 30 50 10 20
 
Sample Output
3

*/
