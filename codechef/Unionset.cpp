#include "vector"
#include "iostream"
#include "algorithm"
#define FOR(i,begin,end) for(i=begin;i<end;i++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    dontsync()
	int t,n,k,i,j,x,len,tmp,cnt;
    cin >> t;
    FOR(i,0,t)
	{
        cin >> n >> k;
        vector<int> vect[n];
        FOR(j,0,n)
        {
            cin >> len;
            FOR(x,0,len)
            {
                cin >> tmp;
                vect[j].push_back(tmp);
            }
            sort(vect[j].begin(),vect[j].end());
        }
        cnt=0;
        FOR(j,0,n)
        {
            vector<int> res(k+5);
            vector<int>::iterator iter;
            FOR(x,j+1,n)
            {
                iter=set_union(vect[j].begin(), vect[j].end(), vect[x].begin(), vect[x].end(), res.begin());
                res.resize(iter - res.begin());
                if(res.size()==k)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
	}
    return 0;
}


/*

There are N sets of integers from 1 to K both inclusive. Find out number of pairs of sets whose union contains all the K elements.

Input
The first line contains an integer T denotes number of test cases.

The first line of each test case contains two space separated integers N, K.

The each of the next line first contains an integer leni denoting number of elements in the i-th set, followed by leni space separated integers in the range [1, K] denoting the
elements in the set.

Output
For each test case, output a single integer corresponding to the answer.

Constraints
1 ≤ T ≤ 10
1 ≤ N, K ≤ 2500
1 ≤ leni ≤ K
Note that a set can't contain repeated elements.
1 ≤ len1 + len2 + .. + lenN ≤ 10000

Subtasks
Subtask #1 (40 points)
1 ≤ T ≤ 10
1 ≤ N, K ≤ 250
1 ≤ len1 + len2 + .. + lenN ≤ 1000

Subtask #2 (60 points)
original constraints.

Example
Input
3
2 2
1 1
1 1
3 2
2 1 2
2 1 2
2 1 2
3 4
3 1 2 3
4 1 2 3 4
3 2 3 4

Output
0
3
3

Explanation
Example 1. No pair of sets is there with its union = 2.
For example 2 and 3, all the pairs are valid.

*/
