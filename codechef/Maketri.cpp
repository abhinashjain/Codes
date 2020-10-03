#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
    long long n,l,r,i,a,b,y,z,cnt=0;
    vector<pair<long long,long long> >vect;
    vector<pair<long long,long long> >::iterator iter,iter1,iter2;
    scanf("%lld %lld %lld",&n,&l,&r);
    long long arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    
    sort(arr,arr+n);
    for(i=1;i<n;i++)
    {
        y=arr[i]-arr[i-1]+1;
        z=arr[i]+arr[i-1]-1;
        if(l<=y && z<=r)
            vect.push_back(make_pair(y,z));
        if(l<=y && y<=r && z>r)
            vect.push_back(make_pair(y,r));
        if(l>y && l<=z && z<=r)
            vect.push_back(make_pair(l,z));
        if(l>y && l<=z && z>r)
            vect.push_back(make_pair(l,r));
    }

    sort(vect.begin(),vect.end());
    for(iter2=vect.begin()+1;iter2!=vect.end();iter2++)
    {
        iter1=iter2-1;
        a=(*iter1).first;
        b=(*iter1).second;
        y=(*iter2).first;
        z=(*iter2).second;
        if(y<=b)
        {
            (*iter2).first=a;
            (*iter1).first=0;
            (*iter1).second=0;
            if(z<b)
            {   
                (*iter2).second=b;
            }
        }
    }

    for(iter=vect.begin();iter!=vect.end();iter++)
    {
        a=(*iter).first;
        b=(*iter).second;
        if(a!=0 && b!=0)
        {
            cnt+=b-a+1;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}


/*

Chef is long been involved in cooking recipes. He has now got bored with it, and has to decided to play with food instead of cooking it up.

He has already selected N spaghetti strands for his dish. He has to select just one extra strand such that this strand's length makes a non-degenerate triangle with some of the two 
other strands already present in the dish. A triangle formed by three collinear points is called a degenerate triangle. The length of the strand to be selected must be an integer in 
the range [L, R] (both inclusive).

Formally, let array L denote the lengths of N strands, then the extra strand of length X can be selected if there exists two different indices i, j (i ≠ j) such that there can be 
made a triangle of side lengths Li, Lj and X.

Can you help him find the number of possible valid lengths of the extra strand?

Note again that three collinear points are not considered to form a triangle.

Input
First line of the input contains three space separated N, L and R, denoting the number of strands already present in the dish and the range of the length of the new strand to be 
selected respectively.

The next line contains N space separated integers, where the i-th integer Li denotes the length of the i-th strand.

Output
Output a single line corresponding to the answer of the problem.

Constraints
2 ≤ N ≤ 10^6
1 ≤ L ≤ R ≤ 10^18
1 ≤ Li ≤ 10^18

Subtasks
Subtask #1 (10 points):
2 ≤ N ≤ 100
1 ≤ L ≤ R ≤ 10^6

Subtask #2 (30 points):
2 ≤ N ≤ 1000
1 ≤ L ≤ R ≤ 10^18

Subtask #3 (60 points):
2 ≤ N ≤ 10^6
1 ≤ L ≤ R ≤ 10^18

Example
Input:
5 1 4
1 2 3 4 5

Output:
3

Explanation
If Chef chooses the strand of length 1, he can't form a triangle using this strand and the any of the pair of strands of length 1, 2, 3, 4, 5. However, for each of the extra strand 
of length 2, 3, 4, one can find at least one pair of strands such that those pair of strands and the extra strand makes a triangle. So, the answer will be 3.

*/
