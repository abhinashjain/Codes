#include "vector"
#include "iostream"
#include "algorithm"
#define FOR(i,begin,end) for(i=begin;i<end;i++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

vector<int> vect, BIT;

unsigned long long getSum(int index)
{
    unsigned long long sum=0;
    while(index > 0)
    {
        sum+=BIT[index];
        index-=index & (-index);
    }
    return sum;
}

void updateBIT(int n, int index, int val)
{
    while(index<=n)
    {
        BIT[index]+=val;
        index+=index & (-index);
    }
}

unsigned long long getInvCount(int n)
{
    int i;
    unsigned long long invcount=0;
    
    vector<int> temp=vect;
    sort(temp.begin(), temp.end());
    FOR(i,0,n)
    {
        vect[i]=lower_bound(temp.begin(), temp.end(), vect[i]) - temp.begin() + 1;
    }
    
    BIT.assign(n+1,0);
    for(i=n-1;i>=0;i--)
    {
        invcount += getSum(vect[i]-1);
        updateBIT(n, vect[i], 1);
    }
    
    return invcount;
}

int main()
{
    dontsync()
    int t,n,i,j,tmp;
    cin >> t;
    FOR(i,0,t)
    {
        cin >> n;
        vect.clear();
        FOR(j,0,n)
        {
            cin >> tmp;
            vect.push_back(tmp);
        }
        cout << getInvCount(n) << "\n";
    }
    return 0;
}


/*

Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find
the number of inversions of A.

Input
The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a
number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.

Output
For every test output one line giving the number of inversions of A.

Example
Input:
2

3
3
1
2

5
2
3
8
6
1


Output:
2
5

*/
