#include "stdio.h"
#include "string.h"
#define MAXSIZE 300005

int main()
{
    char s[MAXSIZE];
    int k,m,b,i,j,len,ans,sum=0;
    scanf("%s",s);
    scanf("%d %d %d",&k,&b,&m);
    int power[k];
    power[0]=1;
    for(i=1;i<k;i++)
    {
        power[i]=( (power[i-1]%m) * (b%m) )%m;
    }
    for(i=0;i<k;i++)
    {
        sum=( (sum%m) + ( ( (( s[i]-'0' )%m) * (power[k-(i+1)]%m) )%m ) )%m;
    }
    ans=sum;
    len=strlen(s);
    for(i=k;i<len;i++)
    {
        sum=((( (b%m) * (( (sum%m) - ( ( (( s[i-k]-'0' )%m) * (power[k-1]%m) )%m ) +m ) %m) ) %m) + ( (s[i]-'0')%m ) )%m;
        ans+=sum;
    }
    printf("%d\n",ans);
    return 0;
}


/*

Alexa performs the following sequence of operations on a string, s, of integers:

1. Make a list of all substrings of s that are a given length, k.
2. Consider each substring to be a base b number (where b is given). Convert each substring in the list from base b to base 10 (i.e., convert (substring)b => (substring)10),
   replacing the base b numbers with base-10 numbers.
3. Replace each base-10 number with its value modulo a given m(i.e., (x)10 => (x)10 mod m).
4. Calculate the magic number by summing all the integers in the final list.

The diagram shows an example where s=12212, k=3, b=3, and m=5:

                        Numeric_String.png

Given s, k, b, and m, can you find the magic number?

Input Format
The first line contains a string denoting s.
The second line contains three space-separated integers describing the respective values of k (the substring length), b (the base), and m (the modulo).

Constraints
1 <= |s| <= 3*10^5
1 <= k <= |s|
1 <= m <= 1000
2 <= b <= 10
String s is composed of decimal digits in the inclusive range [0,b-1], so each substring of length k always forms a valid base b number.
String s may contain leading zeros.

Subtasks
1 <= |s| <= 3*100 for 60% of the maximum score.

Output Format
Print an integer denoting the magic number.

Sample Input 0
12212
3 3 5

Sample Output 0
5

Sample Input 1
111101
4 2 15

Sample Output 1
27

Sample Input 2
0111
2 10 100

Sample Output 2
23

*/
