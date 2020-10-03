#include "stdio.h"
#include "vector"
using namespace std;

int main()
{
    int n,m,l,r,k,i,tmp,cnt=1,ind;
    vector<pair<int,int> > vect;
    vector<pair<int,int> >::iterator iter;
    vect.push_back(make_pair(-1,-1));

    scanf("%d %d",&n,&m);
    scanf("%d",&tmp);
    vect.push_back(make_pair(tmp,cnt));

    for(i=2;i<=n;i++)
    {
        scanf("%d",&tmp);
        if((vect[i-1].first)==tmp)
            cnt++;
        else
            cnt=1;
        vect.push_back(make_pair(tmp,cnt));
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&l,&r,&k);
        ind=(r+l+1)/2;
        cnt=vect[ind].second-vect[l].second+1;

        if(cnt==k)
        {
            printf("%d\n",vect[ind].first);
        }
        else
        {
            tmp=k-vect[ind].second;
            if(vect[ind].first==vect[l].first && (ind-l)==(vect[ind].second-vect[l].second))
            {
                tmp=k-cnt;
            }
            cnt=ind+tmp;
            if(cnt<=r && vect[ind].first==vect[cnt].first && (vect[ind].second+tmp) == vect[cnt].second)
            {
                printf("%d\n",vect[ind].first);
            }
            else
            {
                printf("-1\n");
            }
        }
    }
    return 0;
}


/*

Given an array of size n, you have to answer queries of the form : L R k . For each query, you have to find an element which occurs consecutively in the subarray [L,R] more than or 
equal to k times. k will always be greater than floor((R-L+1)/2). If no such element exists, print -1.

Input
First line of the input contains 2 space separated N and M, denoting the size of the array and the number of queries.
 
The next line contains N space separated integers, where the i-th integer Ai denotes the ith element of the array.
 
Each of the next M lines contains 3 integers space separated integers L, R and k.
 
Output
Output M lines where each line contains the answer to the i-th query.

Constraints
1 ≤ N, M ≤ 10^5
1 ≤ L ≤ R ≤ N
floor((R-L+1)/2) < k ≤ R-L+1
0 ≤ Ai ≤ 10^9
 
Subtasks
Subtask #1 (10 points):
1 ≤ Ai ≤ 3
1 ≤ M ≤ 10
 
Subtask #2 (30 points):
1 ≤ N ≤ 1000
 
Subtask #3 (60 points):
No other constraints
 
Example
Input:
5 1
1 2 2 2 2
1 5 3
 
Output:
2

Explanation
The element 2 occurs more than 3 times in the range [1,5].

*/
