#include "stdio.h"
#include "vector"
#define MAX 5000001
using namespace std;

int main()
{
    int t,i,j,cnt,max,ind;
    unsigned long long n;
    vector<pair<int,int> > coll(MAX,make_pair(0,0));
    coll[0]=make_pair(0,0);
    coll[1]=make_pair(1,1);
    max=ind=1;
    for(i=2;i<MAX;i++)
    {
        if(coll[i].first==0)
        {
            n=i;
            cnt=1;
            vector<int> vect;
            vector<int>::iterator iter;
            vect.push_back(n);
            while(n!=1)
            {
                if(n&1)
                    n=3*n+1;
                else
                    n=n>>1;
                if(n<i)
                {
                    cnt+=coll[n].first;
                    break;
                }
                if(n<MAX && coll[n].first==0)
                {
                    coll[n].first-=cnt;
                    vect.push_back(n);
                }
                cnt++;
            }
            for(iter=vect.begin();iter!=vect.end();iter++)
            {
                coll[*iter].first+=cnt;
            }
        }
        if(coll[i].first>=max)
        {
            ind=i;
            max=coll[i].first;
        }
        coll[i].second=ind;
    }
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%llu",&n);
        printf("%d\n",coll[n].second);
    }
	return 0;
}



/*
 
The following iterative sequence is defined for the set of positive integers:
 
n -> n/2    n is even
n -> 3n+1   n is odd
 
Using the rule above and starting with 13, we generate the following sequence:
 
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers 
finish at 1.
 
Which starting number, <=N produces the longest chain? If many possible such numbers are there print the maximum one.
 
Note: Once the chain starts the terms are allowed to go above N.
 
Input Format
The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integers N.
 
Output Format
Print the values corresponding to each test case.
 
Constraints
1 <= T <= 10^4
1 <= N <= 5*10^6
 
Sample Input
3
10
15
20
 
Sample Output
9
9
19
 
*/