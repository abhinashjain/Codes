#include "stdio.h"
#include "vector"
#include "algorithm"
#define rep(loop_var,begin,end) for(loop_var=begin;loop_var<end;loop_var++)
#define reverse_rep(loop_var,end,begin) for(loop_var=end;loop_var>=begin;loop_var--)
using namespace std;

int main()
{
    int t,i,x,y,n,k,f,tmp;
    scanf("%d",&t);
    rep(i,0,t)
    {
        scanf("%d %d",&n,&k);

        n+=1;
        k+=1;

        vector<vector<int> > mat(n);
        vector<int>::iterator iter;

        vector<pair<int,int> >max;
        max.push_back(make_pair(-1,0));

        int arr[k];
        rep(x,0,k)
        {
            arr[x]=0;
        }
        rep(x,1,n)
        {
            scanf("%d",&f);
            max.push_back(make_pair(f,x));
            rep(y,0,f)
            {
                scanf("%d",&tmp);
                mat[x].push_back(tmp);
            }
        }

        sort(max.begin(),max.end());
        reverse_rep(x,n-1,1)
        {
            tmp=1;
            f=max[x].second;

            for(iter=mat[f].begin();iter!=mat[f].end();iter++)
            {
                arr[(*iter)]=1;
            }

            rep(y,1,k)
            {
                if(arr[y]==0)
                {
                    tmp=0;
                    break;
                }
            }

            if(tmp)
            {
                if(x==1)
                    printf("all\n");
                else
                    printf("some\n");
                break;
            }
        }
        if(x==0)
            printf("sad\n");
    }
    return 0;
}


/*

Chef wants to serve mankind by making people immortal by preparing a dish, a dish of life - a dish with the best taste in the universe, one with the smell and splash of fresh water 
flowing down the springs of the mountain, one with the smell of the best lily flowers of the garden, one that has contained the very essence of life in a real sense.

This dish will contain K ingredients that are found only in remote islands amid mountains. For sake of convenience, we enumerate the ingredients by the integers from 1 to K, both 
inclusive. There are N islands and each of them offers some ingredients. Chef being a little child did not know how to collect the ingredients for the recipe. He went to all the 
islands and bought all the ingredients offered in each island. Could he possibly have saved some time by skipping some island? If it was not possible for Chef to collect the required 
ingredients (i.e. all the K ingredients), output "sad". If it was possible for him to skip some islands, output "some", otherwise output "all".

Input
First line of the input contains an integer T denoting number of test cases. The description of T test cases follow.

The first line of each test case contains two space separated integers N, K.

The i-th of the next lines will contain first an integer Pi, denoting the number of ingredients grown in the i-th island, followed by Pi distinct integers in the range [1, K]. All 
the integers are space separated.

Output
For each test case, output a single line containing one of the strings "sad", "all" or "some" (without quotes) according to the situation.

Constraints
1 ≤ T ≤ 10
1 ≤ N, K ≤ 10^5
1 ≤ Pi ≤ K
Sum of Pi over all test cases ≤ 10^6

Subtasks
Subtask #1 (30 points)
1 ≤ N, K ≤ 50

Subtask #2 (30 points)
1 ≤ K ≤ 50

Subtask #3 (40 points)
original constraints

Example
Input
3
3 4
3 1 2 3
2 1 3
2 1 2
2 3
3 1 2 3
2 1 3
2 3
2 1 2
2 1 3

Output
sad
some
all

Explanation
Example 1. The ingredient 4 is not available in any island, so Chef can't make the dish of life. Hence, the answer is "sad".

Example 2. Chef can just go to the first island and collect all the three ingredients required. He does not need to visit the second island. So, the answer is "some".

Example 3. Chef has to visit both the islands in order to obtain all the three ingredients. So, the answer is "all".

*/
