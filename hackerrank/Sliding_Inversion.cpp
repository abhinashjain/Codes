#include "map"
#include "math.h"
#include "vector"
#include "iostream"
#include "algorithm"
#define MAXSIZE 500010
#define FOR(i,begin,end) for(i=begin;i<end;i++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int cnt,block;
int arr[MAXSIZE],temp[MAXSIZE];
long long sum, ans, BIT[MAXSIZE];

map<int,int> mymap;
vector<pair<pair<int,int>,int> > vect;

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
    int aa=a.first.first/block;
    int bb=b.first.first/block;
    if(aa==bb)
    {
        return a.first.second < b.first.second;
    }
    return aa<bb;
}

void cmprs(int n)
{
    int i;
    sort(temp+1,temp+n+1);
    FOR(i,1,n+1)
    {
        if(!mymap[temp[i]])
        {
            cnt++;
            mymap[temp[i]]=cnt;
        }
    }
    FOR(i,1,n+1)
    {
        arr[i]=mymap[arr[i]];
    }
}

void update(int n, int x, int val)
{
    while(x<=n)
    {
        BIT[x]+=val;
        x=x+(x & -x);
    }
}

long long Query(int x)
{
    long long ans=0;
    while(x>0)
    {
        ans+=BIT[x];
        x=x-(x & -x);
    }
    return ans;
}

int main()
{
    dontsync()
    int n,m,u,v,i,l,r,lf,rf,inx;
    cin >> n >> m;
    FOR(i,1,n+1)
    {
        cin >> arr[i];
        temp[i]=arr[i];
    }
    cmprs(n);
    block=sqrt(n);

    u=1;
    v=m;
    FOR(i,0,n-m+1)
    {
        vect.push_back(make_pair(make_pair(u,v),i));
        u++;
        v++;
    }
    
    l=1;
    r=0;
    sort(vect.begin(),vect.end(),compare);
    FOR(i,0,n-m+1)
    {
        lf=vect[i].first.first;
        rf=vect[i].first.second;
        inx=vect[i].second;

        while(r<rf)
        {
            r++;
            update(n,arr[r],1);
            ans=ans + Query(n) - Query(arr[r]);
        }

        while(r>rf)
        {
            update(n,arr[r],-1);
            ans=ans - Query(n) - Query(arr[r]);
            r--;
        }

        while(l<lf)
        {
            update(n,arr[l],-1);
            ans=ans - Query(arr[l]-1);
            l++;
        }

        while(l>lf)
        {
            l--;
            update(n,arr[l],1);
            ans=ans + Query(arr[l]-1);
        }
        sum+=ans;
    }
    cout << sum << "\n";
    return 0;
}


/*

You have an array of n integers a0,a1,...,an-1. Inversion count of an array is defined by number of pair of indices (i,j) such that i<j and ai>aj.
Inversion count is useful to find how close the array is from being sorted.

Your task is to find the inversion count for every contiguous subarray of size m and calculate the sum of inversion counts for all possible subarrays of that size.

For example, let's say the array is {1,4,3,2} and m=3.

Let's calculate the number of inversions for each subarray of size 3:

{1,4,3} = 1 inversion
{4,3,2} = 3 inversion

The answer will be total number of inversions = 1+3 = 4.

Input Format
The first line contains two space-separated integers n and m.
The second line contains n integers a0,a1,...,an-1.

Constraints
1<=n<=5*10^5
1<=m<=n
-10^9<=ai<=10^9

Subtasks
1<=n<=10000 for 50% of the maximum score.
1<=n<=100 for 30% of the maximum score.

Output Format
Find the inversion count for every subarray of size m and print the sum of those invertion counts for all possible subarrays of that size.

Sample Input 0
4 3
1 4 3 2

Sample Output 0
4

Explanation 0
This sample corresponds to the example mentioned in the problem statement.

Sample Input 1
5 2
100 5 100 5 5

Sample Output 1
2

Sample Input 2
10 5
15 51 44 44 76 50 29 88 48 50

Sample Output 2
25

*/
