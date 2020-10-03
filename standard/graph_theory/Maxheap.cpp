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
