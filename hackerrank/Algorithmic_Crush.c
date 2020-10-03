#include "stdio.h"
#define MAX 10000002

long long arr[MAX];
int main()
{
    int n,m,a,b,k,i;
    long long max;
	scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&k);
        arr[a]+=k;
        arr[b+1]-=k;
    }
    max=arr[1];
    for(i=2;i<=n;i++)
    {
        arr[i]+=arr[i-1];
        if(arr[i]>max)
            max=arr[i];
    }
    printf("%lld\n",max);
	return 0;
}


/*

You are given a list of size N, initialized with zeroes. You have to perform M operations on the list and output the maximum of final values of all N the elements in the list. For 
every operation, you are given three integers a, b and k and you have to add value k to all the elements ranging from index a to b (both inclusive).

Input Format
First line will contain two integers N and M separated by a single space.
Next M lines will contain three integers a, b and k separated by a single space.
Numbers in list are numbered from 1 to N.

Constraints
3<=N<=10^7
1<=M<=2*10^5
1<=a<=b<=N
0<=k<=10^9

Output Format
A single line containing maximum value in the updated list.

Sample Input
5 3
1 2 100
2 5 100
3 4 100

Sample Output
200

Explanation
After first update list will be 100 100 0 0 0.
After second update list will be 100 200 100 100 100.
After third update list will be 100 200 200 200 100.
So the required answer will be 200.

*/
