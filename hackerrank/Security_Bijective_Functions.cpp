#include "stdio.h"
#include "set"
using namespace std;

int main()
{
    int n,i,y;
    set<int> img;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&y);
        img.insert(y);
    }
    if(img.size() == n)
        printf("YES");
    else
        printf("NO");
    return 0;
}


/*

Now that we know about one-to-one functions, let's talk about onto functions and bijective functions.

A function f: X -> Y is onto if and only if each element in the co-domain Y is the image of, at least, one element in the domain X. That is:

Im(f) = Y

If the function f is both one-to-one and onto then f is a bijection from X to Y or, equivalently, f: X -> Y is a bijective function.

In this task, you'll be given an integer n and a function f: X -> X where X={1,2,3,...,n}. Determine whether the given function is a bijective function or not.

Constraints
1 <= n <= 20

Input Format
There are 2 lines in the input.
The first line contains a single positive integer n.
The second line contains n space separated integers, the values of f(1), f(2), f(3), ..., f(n), respectively.

Output Format
On a single line, output "YES" if f is bijective. Otherwise, output "NO".

Sample Input
3
1 2 3

Sample Output
YES

Explanation
Basically, this is the function f(x)=x.
    
*/