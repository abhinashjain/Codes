#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
	long long t,a,b,c,i,j,n,f,sq;
	vector<long long> vect;
	vector<long long>::iterator low1,low2;
	for(i=1;i<100001;i++)
	{
		sq=i*i;
		n=sq;
		f=1;
		while(n>0)
		{
			c=n%10;
			n=n/10;
			if(c==2 || c==3 || c==5 || c==6 || c==7 || c==8)
			{
				f=0;
				break;
			}
		}
		if(f==1)
			vect.push_back(sq);
	}
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld %lld",&a,&b);
		low1=lower_bound(vect.begin(),vect.end(),a);
		low2=lower_bound(vect.begin(),vect.end(),b);
		if(vect[(low2-vect.begin())]==b)
			printf("%d\n",(low2-vect.begin())-(low1-vect.begin())+1);
		else
			printf("%d\n",(low2-vect.begin())-(low1-vect.begin()));
	}
	return 0;
}



/*

Recently Chef become very much interested in perfect squares. We all know Chef and his weird interests. Anyways Chef will be soon writing his masters thesis on perfect squares revealing what-not-known properties of perfect squares.

While doing his research, he happened to be confronted with some interesting perfect squares. These prefect squares consists only of digits which are themselves perfect squares. 0, 1, 4 and 9 are such digits. These are called perfect digits.

As we all know Chef also has habit of asking too many questions, he is asking- given two numbers a and b, how many perfect squares exists between these two numbers inclusive, that contains only perfect digits. 


Input:
First line of input will contains T, number of test cases. Then T lines follows, each containing two positive integers a and b.


Constraints:
T <= 500
1<= a <= b <= 10000000000 


Output:
For each input, output number of perfect digit squares between given numbers. 


Sample
Input:
2
1 10
100 10000

Output:
3
9

*/
