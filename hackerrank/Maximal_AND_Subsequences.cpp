#include "vector"
#include "iostream"
#define mod 1000000007
#define rep(loop_var,begin,end) for(loop_var=begin;loop_var<end;loop_var++)
#define reverse_rep(loop_var,begin,end) for(loop_var=begin;loop_var>=end;loop_var--)
using namespace std;

long long bigmod(long long a, long long p, long long m)
{
    long long res=1%m, x=a%m;
    while(p)
    {
        if(p&1)
        {
            res=(res*x)%m;
        }
        x=(x*x)%m;
        p >>= 1;
    }
    return res;
}

int main()
{
    long long i,j,n,k,tmp,a,b,c,ans;
    cin >> n >> k;
    vector<long long> vect1;
    vector<long long>::iterator iter;
    rep(i,0,n)
    {
        cin >> tmp;
        vect1.push_back(tmp);
    }
    reverse_rep(i,62,0)
    {
        vector<long long> vect2;
        rep(j,0,vect1.size())
        {
            if(vect1[j] & (1LL << i))
            {
                vect2.push_back(vect1[j]);
            }
        }
        if(vect2.size()>=k)
        {
            vect1.clear();
            vect1=vect2;
        }
    }
    ans=vect1[0];
    rep(i,1,vect1.size())
    {
        ans = ans & vect1[i];
    }

    n=vect1.size();
    a=b=c=1;
    rep(i,1,n+1)
    {
        a=(a*i)%(mod);
    }
    rep(i,1,k+1)
    {
        b=(b*i)%(mod);
    }
    rep(i,1,n-k+1)
    {
        c=(c*i)%(mod);
    }

    b = bigmod(b, mod-2, mod);
    c = bigmod(c, mod-2, mod);
    a = (a*b)%mod;
    a = (a*c)%mod;

    cout << ans << "\n" << a << "\n";
    return 0;
}


/*

Alice has an array of n long integers, A=[a0,a1,...,a(n-1)]. She wants to find all the k-element subsequences of A where the bitwise AND of the subsequence's elements is maximal.

For example, let A=[6,3,7,4] and k=3. Now, let's apply the AND operation on all possible subsequences of size k:

Subsequences           Decimal                  Binary
{6,3,7}             6 & 3 & 7 = 2       110 & 011 & 111 = 010
{6,7,4}             6 & 7 & 4 = 4       110 & 111 & 100 = 100
{6,3,4}             6 & 3 & 4 = 0       110 & 011 & 100 = 000
{3,7,4}             3 & 7 & 4 = 0       011 & 111 & 100 = 000
 
The maximal AND value of these subsequences is 4, and only 1 subsequence has that value: {6,7,4}.
Given A and k, find the maximal bitwise AND value of any subsequence of A, as well as the total number of subsequences having that maximal value modulo 10^9 + 7.

Input Format
The first line contains two space-separated integers describing the respective values of n (the number of elements in the array) and k (the size of the subsequence).
Each of the n subsequent line contains a long integer describing the respective values of a0,a1,...,a(n-1).

Constraints
2<=k<=n<=10^5
0<=ai<=10^18

Output Format
Print two lines of output:
1. The first line contains the maximal bitwise AND value of any k-element subsequence of A.
2. The second line contains the number of subsequences of A having that maximal AND value, modulo (10^9 + 7).

Sample Input 0
3 2
3
5
6

Sample Output 0
4
1

Explanation 0
For A=[3,5,6] and k=2, there are three possible subsequences of size k. Let's apply the AND operation to each subsequence:

3 & 5 = 1
3 & 6 = 2
5 & 6 = 4

The maximum bitwise AND of any subsequence is 4, and only 1 subsequence ({5,6}) gives us that value. We then print 4 as our first line of output and the result of 1 mod (10^9 + 7) = 
1 as our second line of output.

Sample Input 1
4 2
21
19
22
20

Sample Output 1
20
3

Explanation 1
For A=[21,19,20,22] and k=2, we perform the following AND operations on each subsequence:

21 & 19 = 17
21 & 22 = 20
21 & 20 = 20
19 & 22 = 18
19 & 20 = 16
22 & 20 = 20

The maximum bitwise AND of any subsequence is 20, and there are 3 such subsequences ({21,22}, {21,20}, and {22,20}) giving us that value. We then print 20 as our first line of output 
and the result of 3 mod (10^9 + 7) = 3 as our second line of output.

Sample Input 2
4 3
9
15
27
14

Sample Output 2
10
1

Explanation 2
For A=[9,15,27,14] and k=3, there are four k-element subsequences: {9,15,27}, {9,15,14}, {9,27,14}, and {15,27,14}. The maximum bitwise AND of any subsequence is 10, and there is 1 
such subsequence ({15,27,14}) giving us that value. We then print 10 as our first line of output and the result of 1 mod (10^9 + 7) = 1 as our second line of output.

*/
