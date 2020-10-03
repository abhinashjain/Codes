#include "stdio.h"

int main()
{
	int i,j,t,n,min,tmp,cnt;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
        scanf("%d",&n);
        int arr[n];
        scanf("%d",&arr[0]);
        min=arr[0];
        cnt=1;
        for(j=1;j<n;j++)
        {
            scanf("%d",&arr[n]);
            if(arr[n]==min)
                cnt++;
            else
                if(arr[n]<min)
                {
                    min=arr[n];
                    cnt=1;
                }
        }
        if(cnt&1)
            printf("Lucky\n");
        else
            printf("Unlucky\n");
	}
	return 0;
}

/*
 
Monk just purchased an array A having N integers. Monk is very superstitious. He calls the array A
Lucky if the frequency of the minimum element is odd, otherwise he considers it Unlucky. Help Monk in finding out if the array is Lucky or not.
 
Input:
First line consists of a single integer T denoting the number of test cases.
First line of each test case consists of a single integer N denoting the size of array A.
Second line of each test case consists of N space separated integers denoting the array A.
 
Output:
For each test case, print "Lucky" (without quotes) if frequency of minimum element is odd, otherwise print "Unlucky"(without quotes). Print a new line after each test case.
 
Constraints:
1≤T≤10
1≤N≤10^5
1≤A[i]≤10^9
 
SAMPLE INPUT
2
5
8 8 9 5 9
5
3 3 3 5 3
 
SAMPLE OUTPUT
Lucky
Unlucky
 
Explanation
In first case, value of minimum element is 5 and it's frequency is 1 which is odd, so the array is Lucky.
In second case, value of minimum element is 3 and it's frequency is 4 which is even, so the array is Unlucky.

*/
