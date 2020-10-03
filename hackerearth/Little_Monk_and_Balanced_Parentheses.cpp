#include "stdio.h"
#include "stdlib.h"
#include "stack"
using namespace std;

int main()
{
    int n,i,cnt=0,max=0,top;
    stack<int> mystack;
    scanf("%d",&n);
    int arr[n+1];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mystack.push(0);
    for(i=1;i<=n;i++)
    {
        if(arr[i]>0)
        {
            mystack.push(i);
        }
        else
        {
            if(mystack.top()!=0)
            {
                top=mystack.top();
                mystack.pop();
                if(abs(arr[i])==arr[top])
                    cnt=i-mystack.top();
                else
                {
                    while(mystack.top()!=0)
                        mystack.pop();
                    mystack.push(i);
                }
            }
            else
                mystack.push(i);
            if(cnt>max)
                max=cnt;
        }
    }
    printf("%d\n",max);
	return 0;
}


/*

Given an array of positive and negative integers, denoting different types of parentheses. The positive numbers xi denotes opening parentheses of type xi and negative number −xi
denotes closing parentheses of type xi.

Open parentheses must be closed by the same type of parentheses. Open parentheses must be closed in the correct order, i.e., never close an open pair before its inner pair is closed
(if it has an inner pair). Thus, [1,2,−2,−1] is balanced, while [1,2,−1,−2] is not balanced.
 
You have to find out the length of the longest subarray that is balanced.
 
Input Format:
First line contains an input N (1≤N≤2∗10^5), denoting the number of parentheses. Second line contains N space separated integers. 
xi (−10^5≤xi≤10^5,xi≠0) denoting the ith parentheses of the array.
 
Output Format:
Print the length of the longest subarray that is balanced.

SAMPLE INPUT
5
1 -1 2 3 -2
 
SAMPLE OUTPUT
2
 
Explanation
The longest subarray that is balanced is (1,−1). (2,3,−2) is not balanced as (3) is not balanced.

*/
