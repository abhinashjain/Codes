#include "math.h"
#include "vector"
#include "iostream"
#include "algorithm"
#define MAXSIZE 500001
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int prime[MAXSIZE];
vector<int> primelist;

void primes()
{
    int i,j,z;
    prime[0]=1;
    prime[1]=1;
    for(i=3;(i*i)<MAXSIZE;i+=2)
    {
        if(prime[i]==0)
        {
            z=i<<1;
            for(j=i*i;j<MAXSIZE;j+=z)
            {
                prime[j]=1;
            }
        }
    }
    primelist.push_back(2);
    for(i=3;i<MAXSIZE;i+=2)
    {
        if(prime[i]==0)
        {
            primelist.push_back(i);
        }
    }
}

int main()
{
    dontsync()
    int t,n,i,j,num,sqroot,sub,div,cnt;
    primes();
    vector<int>::iterator up;
    cin >> t;
    rep(i,0,t)
    {
        cin >> n;
        cnt=0;
        up=upper_bound(primelist.begin(), primelist.end(), n);
        num=up-primelist.begin();
        rep(j,0,num)
        {
            sub=n-primelist[j];
            if(sub&1)
            {
                continue;
            }
            div=sub >> 1;
            sqroot=(int) sqrt(div);
            if((sqroot*sqroot)==div)
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
	return 0;
}


/*

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

                                            9  = 7  + 2 * 1^2
                                            15 = 7  + 2 * 2^2
                                            21 = 3  + 2 * 3^2
                                            25 = 7  + 2 * 3^2
                                            27 = 19 + 2 * 2^2
                                            33 = 31 + 2 * 1^2

It turns out that the conjecture was false as you'll discover some values can't be represented as a sum of prime and twice a square.
You are given N, print the number of ways N can be represented as a sum of prime and twice a square.
Example 15 can be represented in two ways as 15 = 7 + 2 * 2^2 and 15 = 13 + 2 * 1^2

Input Format
The first line contains an integer T, i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1 <= T <= 100
9 <= N < 5 * 10^5
N belongs to {odd composite number}

Output Format
Print the values corresponding to each test case.

Sample Input
2
9
15

Sample Output
1
2

*/
