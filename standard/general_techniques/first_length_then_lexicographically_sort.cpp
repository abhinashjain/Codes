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
