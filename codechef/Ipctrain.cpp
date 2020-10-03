#include "vector"
#include "iostream"
#include "algorithm"
#define FOR(i,begin,end) for(i=begin;i<end;i++)
#define FOR_stl(iter,begin,end) for(iter=begin;iter!=end;iter++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    dontsync()
	long long t,n,d,x,y,z,i,j,cnt;
    cin >> t;
    FOR(i,0,t)
	{
        cnt=0;
        cin >> n >> d;
        vector<pair<long long,long long> > vect[d+1],heap;
        vector<pair<long long,long long> >::iterator iter;
        FOR(j,0,n)
        {
            cin >> x >> y >> z;
            vect[x].push_back(make_pair(z,y));
            cnt+=(y*z);
        }
        FOR(j,1,d+1)
        {
            if(vect[j].size())
            {
                FOR_stl(iter,vect[j].begin(),vect[j].end())
                {
                    heap.push_back(make_pair((*iter).first,(*iter).second));
                    push_heap(heap.begin(),heap.end());
                }
            }
            if(heap.size())
            {
                cnt=cnt-(heap.front()).first;
                if((heap.front()).second==1)
                {
                    pop_heap(heap.begin(),heap.end());
                    heap.pop_back();
                }
                else
                {
                    (heap.front()).second--;
                }
            }
        }
        cout << cnt << "\n";
	}
    return 0;
}


/*

During the Indian Programming Camp (IPC), there are N trainers. The camp runs for D days. Each day, there can be at most one lecture. The i-th trainer arrives on day Di and then
stays till the end of the camp. He also wants to teach exactly Ti lectures. For each lecture that a trainer was not able to teach, he will feel sad and his sadness level will be
increased by Si.

You are the main organizer of the contest. You want to find minimum total sadness of the trainers.

Input
The first line of the input contains an integer T, denoting the number of testcases.
For each test case, the first line contains two space separated integers, N, D.
The i-th of the next N lines will contain three space separated integers: Di, Ti, Si respectively.

Output
For each test case, output a single integer corresponding to the minimum total sadness of the trainers achievable.

Constraints
1 ≤ T ≤ 10
1 ≤ N, D ≤ 10^5
1 ≤ Di, Ti ≤ D
1 ≤ Si ≤ 10^5

Subtasks
Subtask #1 (40 points)
1 ≤ T ≤ 10
1 ≤ N, D ≤ 10^3
1 ≤ Di, Ti ≤ D
1 ≤ Si ≤ 10^3

Subtask #2 (60 points)
Original constraints

Example
Input
3
2 3
1 2 300
2 2 100
2 3
1 1 100
2 2 300
2 3
3 2 150
1 1 200

Output
100
0
150

Explanation
Example case 1. Both the first and second trainer want to take exactly two lectures. The first trainer arrives on the 1st day and the second trainer arrives on the 2nd day. Consider
a schedule where the first trainer takes the first two lectures, and the second trainer takes the last lecture on the day 3. This way the second trainer will take only one
lecture but wanted to take two. Thus, his sadness will be 100. The first trainer took all the lectures that he wanted to take (ie. two lectures). Thus the total sadness is 100 +
0 = 100. You can check that no other way of assigning trainers to the days will give a better answer than this.

Example case 2. In this case, the trainers can all take all their ideal number of lectures.

Example case 3. In this case, the first trainer arrives on day 3 and wants to take two lectures. This is not possible as he can take at most one lecture on day 3 and the camp ends on
day 3. The second trainer wants to take only one lecture which he can take on any one of the 1st or 2nd days. You can see that in one of the first or second days, no lecture will
be held.

*/
