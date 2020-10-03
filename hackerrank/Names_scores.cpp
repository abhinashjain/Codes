#include "iostream"
#include "iterator"
#include "string"
#include "map"
using namespace std;

int main()
{
    int n,q,i,sum,ind;
    string name;
    string::iterator it;
    map<string,int> mymap;
    map<string,int>::iterator first,iter;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin >> name;
        sum=0;
        for(it=name.begin();it!=name.end();it++)
            sum+=(*it)-'A'+1;
        mymap.insert(make_pair(name,sum));
    }
    scanf("%d",&q);
    first=mymap.begin();
    for(i=0;i<q;i++)
    {
        cin >> name;
        iter=mymap.find(name);
        ind=distance(first,iter)+1;
        cout << ind*(iter->second) << "\n";
    }
    return 0;
}



/*

You are given around five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its
alphabetical position in the list to obtain a name score.
 
For example, when the list in sample is sorted into alphabetical order, PAMELA, which is worth 16+1+13+5+12+1=48, is the 5th name in the list. So, PAMELA would obtain a score of
5x48=240.
 
You are given Q queries, each query is a name, you have to print the score.
 
Input Format
The first line contains an integer N , i.e., number of names.
Next N lines will contain a Name.
Followed by integer Q followed by Q lines each having a word.
 
Output Format
Print the values corresponding to each test case.
 
Constraints
1<=N<=5200
length of each word will be less than 12
1<=Q<=100
 
Sample Input
5
ALEX
LUIS
JAMES
BRIAN
PAMELA
1
PAMELA
 
Sample Output
240
 
*/