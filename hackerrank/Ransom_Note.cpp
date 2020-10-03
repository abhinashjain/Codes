#include "stdio.h"
#include "iostream"
#include "map"
#include "vector"
#include "string"
using namespace std;

int m,n;
bool ransom_note(vector<string> magazine, vector<string> ransom)
{
    int i;
    if(n>m)
        return 0;
    map<string,int> mymap;
    map<string,int>::iterator iter;
    for(i=0;i<m;i++)
    {
        iter=mymap.find(magazine[i]);
        if(iter!=mymap.end())
            mymap[magazine[i]]++;
        else
            mymap.insert(pair<string,int>(magazine[i],1));
    }
    for(i=0;i<n;i++)
    {
        iter=mymap.find(ransom[i]);
        if(iter!=mymap.end())
        {
            mymap[ransom[i]]--;
            if(mymap[ransom[i]]<0)
                return 0;
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    int i;
    scanf("%d %d",&m,&n);
    vector<string> magazine(m), ransom(n);
    for(i=0;i<m;i++)
        cin >> magazine[i];
    for(i=0;i<n;i++)
        cin >> ransom[i];
    if(ransom_note(magazine, ransom))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}


/*
 
A kidnapper wrote a ransom note but is worried it will be traced back to him. He found a magazine and wants to know if he can cut out whole words from it and use them to create an
untraceable replica of his ransom note. The words in his note are case-sensitive and he must use whole words available in the magazine, meaning he cannot use substrings or
concatenation to create the words he needs.
 
Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.
 
Input Format
The first line contains two space-separated integers describing the respective values of m (the number of words in the magazine) and n (the number of words in the ransom note).
The second line contains m space-separated strings denoting the words present in the magazine.
The third line contains n space-separated strings denoting the words present in the ransom note.
 
Constraints
1<=m,n<=30000
1<=length of any word<=5.
Each word consists of English alphabetic letters (i.e., a to z and A to Z).
The words in the note and magazine are case-sensitive.
 
Output Format
Print Yes if he can use the magazine to create an untraceable replica of his ransom note; otherwise, print No.
 
Sample Input
6 4
give me one grand today night
give one grand today
 
Sample Output
Yes
 
Explanation
All four words needed to write an untraceable replica of the ransom note are present in the magazine, so we print Yes as our answer.

*/
