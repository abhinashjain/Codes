#include "vector"
#include "iostream"
#include "math.h"
#define MAXNUMBER   1000000000
#define SQROOT      31623
#define max(x,y) (x > y) ? x : y
#define min(x,y) (x < y) ? x : y
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

// Set your CPU's L1 data cache size (in bytes) here
const long long L1D_CACHE_SIZE = 32768;
vector<char> is_prime(SQROOT+1, 1);

void simple_seive()
{
    long long i,j,k;
    
    // generate small primes <= SQROOT
    for(i=3;(i*i)<SQROOT;i+=2)
    {
        if(is_prime[i])
        {
            k=i<<1;
            for(j=(i*i);j<SQROOT;j+=k)
            {
                is_prime[j] = 0;
            }
        }
    }
}

// Generate primes using the segmented sieve of Eratosthenes.
// This algorithm uses O(n log log n) operations and O(sqrt(n)) space.
long long segmented_sieve(long long range)
{
    long long i,j,k,segment_size,count=0,s=3,n=3,low,high;
    
    count++;
    cout << "2\n";
    
    segment_size=max(SQROOT, L1D_CACHE_SIZE);
    
    // vector used for sieving
    vector<char> sieve(segment_size);
    vector<long long> primes, next;
    
    for(low=0;low<=range;low+=segment_size)
    {
        fill(sieve.begin(),sieve.end(),1);
        
        // current segment = interval [low, high]
        high=min(low + segment_size - 1, range);
        
        // add new sieving primes <= sqrt(high)
        for(;(s*s)<=high;s+=2)
        {
            if(is_prime[s])
            {
                primes.push_back(s);
                next.push_back((s*s)-low);
            }
        }
        
        // sieve the current segment
        for(i=0;i<primes.size();i++)
        {
            j=next[i];
            for(k=(primes[i]*2);j<segment_size;j+=k)
            {
                sieve[j] = 0;
            }
            next[i]=j-segment_size;
        }
        
        for(;n<=high;n+=2)
        {
            if(sieve[n-low]) // n is a prime
            {
                count++;
                cout << n << "\n";
            }
        }
    }
    return count;
}

int main()
{
    dontsync()
    long long range;
    simple_seive();
    cin >> range;    // 1000000000 i.e. [0,1000000000]
    cout << segmented_sieve(range) << " primes found." << "\n";
    return 0;
}
