#include "vector"
#include "iostream"
#define FOR(i,begin,end) for(i=begin;i<end;i++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    dontsync()
	int t,n,i,j;
    cin >> t;
    FOR(i,0,t)
	{
        cin >> n;
        vector<int> vect;
        vect.push_back(1);
        FOR(j,1,n)
        {
            vect.push_back(vect[j-1]+2);
        }
        FOR(j,0,n)
        {
            cout << vect[j] << " ";
        }
        cout << "\n";
	}
    return 0;
}


/*

A set of integers is called good if there does not exist three distinct elements a, b, c in it such that a + b = c.

Your task is simple. Just output any good set of n integers. All the elements in this set should be distinct and should lie between 1 and 500, both inclusive.

Input
The first line of the input contains an integer T denoting number of test cases. The descriptions of T test cases follow.
The only line of each test case contains an integer n, denoting the size of the needed good set.

Output
For each test case, output a single line containing n integers denoting the elements of the good set, in any order. There can be more than one possible good set, and you can output
any one of them.

Constraints
1 ≤ T, n ≤ 100

Subtasks
Subtask #1 (50 points): 1 ≤ T, n ≤ 10
Subtask #2 (50 points): original constraints

Example
Input
5
1
2
3
4
5

Output
7
1 2
1 2 4
1 2 4 16
3 2 15 6 10

Explanation

Example 1 and 2. Any set of size less than or equal to 2 is good by definition.

Example 3 onwards. For each pair of elements in the set, you can see that their sum doesn't exist in the set.

*/
