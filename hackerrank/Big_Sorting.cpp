#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool length_then_lexico(const string &left, const string &right)
{
    //first sort by length/size
    if (left.size() != right.size())
    {
        return left.size() < right.size();
    }
    
    //if lenght is same then sort lexicographically
    return left < right;
}

int main()
{
    int i,n;
    string str;
    cin >> n;
    vector<string> vect;
    for(i=0;i<n;i++)
    {
        cin >> str;
        vect.push_back(str);
    }
    sort(vect.begin(),vect.end(),length_then_lexico);
    for(i=0;i<n;i++)
    {
        cout << vect[i] << "\n";
    }
    return 0;
}


/*

Consider an array of numeric strings, unsorted, where each string is a positive number with anywhere from 1 to 10^6 digits. Sort the array's elements in non-decreasing (i.e., 
ascending) order of their real-world integer values and print each element of the sorted array on a new line.

Input Format
The first line contains an integer, n, denoting the number of strings in unsorted.
Each of the n subsequent lines contains a string of integers describing an element of the array.

Constraints
1<=n<=2*10^5
Each string is guaranteed to represent a positive integer without leading zeros.
The total number of digits across all strings in unsorted is between 1 and 10^6 (inclusive).

Output Format
Print each element of the sorted array on a new line.

Sample Input 0
6
31415926535897932384626433832795
1
3
10
3
5

Sample Output 0
1
3
3
5
10
31415926535897932384626433832795

Explanation 0
The initial array of strings is unsorted = [31415926535897932384626433832795, 1, 3, 10, 3, 5]. When we order each string by the real-world integer value it represents, we get:
1 <= 3 <= 3 <= 5 <= 10 <= 31415926535897932384626433832795

We then print each value on a new line, from smallest to largest.

*/
