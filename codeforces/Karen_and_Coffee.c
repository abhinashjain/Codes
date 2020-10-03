#include "stdio.h"
#define max(x,y) (x > y) ? x : y
#define min(x,y) (x < y) ? x : y
#define MAX 200005

int k, arr[MAX], tree[4*MAX];

int make_tree(int node , int beg , int endd)
{
    if(beg==endd)
    {
        tree[node]=0;
        if(arr[beg]>=k)
        {
            tree[node]=1;
        }
        return 0;
    }
    int left = node *2;
    int right = left + 1;
    int mid = (beg + endd ) >>1;
    
    make_tree(left , beg ,  mid);
    make_tree(right , mid+1 , endd);
    tree[node]=tree[left]+tree[right];
    return 0;
}

int query( int node , int beg , int endd , int i , int j)
{
    if(i > j)
        return 0;
    
    if(beg==i && endd == j )
        return tree[node];
    
    int left = node << 1;
    int right = left + 1;
    int mid = (beg + endd) >> 1;
    
    int l = query( left , beg , mid , i , min(j, mid));
    int r = query( right , mid+1 , endd , max(i, mid+1), j);
    return l+r;
}

int main()
{
    int n,q,l,r,i,j,cnt;
    scanf("%d %d %d",&n,&k,&q);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&l,&r);
        arr[l]++;
        arr[r+1]--;
    }
    for(i=1;i<MAX;i++)
    {
        arr[i]+=arr[i-1];
    }

    make_tree(1, 1, MAX-1);
    
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",query(1, 1, MAX-1, l, r));
    }
    return 0;
}


/*

To stay woke and attentive during classes, Karen needs some coffee!
Karen, a coffee aficionado, wants to know the optimal temperature for brewing the perfect cup of coffee. Indeed, she has spent some time reading several recipe books, including the
universally acclaimed "The Art of the Covfefe".

She knows n coffee recipes. The i-th recipe suggests that coffee should be brewed between li and ri degrees, inclusive, to achieve the optimal taste.

Karen thinks that a temperature is admissible if at least k recipes recommend it.

Karen has a rather fickle mind, and so she asks q questions. In each question, given that she only wants to prepare coffee with a temperature between a and b, inclusive, can you tell
her how many admissible integer temperatures fall within the range?

Input
The first line of input contains three integers, n, k (1 ≤ k ≤ n ≤ 200000), and q (1 ≤ q ≤ 200000), the number of recipes, the minimum number of recipes a certain temperature must be
recommended by to be admissible, and the number of questions Karen has, respectively.

The next n lines describe the recipes. Specifically, the i-th line among these contains two integers li and ri (1 ≤ li ≤ ri ≤ 200000), describing that the i-th recipe suggests that
the coffee be brewed between li and ri degrees, inclusive.

The next q lines describe the questions. Each of these lines contains a and b, (1 ≤ a ≤ b ≤ 200000), describing that she wants to know the number of admissible integer temperatures
between a and b degrees, inclusive.

Output
For each question, output a single integer on a line by itself, the number of admissible integer temperatures between a and b degrees, inclusive.

Examples
Input
3 2 4
91 94
92 97
97 99
92 94
93 97
95 96
90 100

Output
3
3
0
4

Input
2 1 1
1 1
200000 200000
90 100

Output
0

Note
In the first test case, Karen knows 3 recipes.

1. The first one recommends brewing the coffee between 91 and 94 degrees, inclusive.
2. The second one recommends brewing the coffee between 92 and 97 degrees, inclusive.
3. The third one recommends brewing the coffee between 97 and 99 degrees, inclusive.

A temperature is admissible if at least 2 recipes recommend it.

She asks 4 questions.

In her first question, she wants to know the number of admissible integer temperatures between 92 and 94 degrees, inclusive. There are 3: 92, 93 and 94 degrees are all admissible.

In her second question, she wants to know the number of admissible integer temperatures between 93 and 97 degrees, inclusive. There are 3: 93, 94 and 97 degrees are all admissible.

In her third question, she wants to know the number of admissible integer temperatures between 95 and 96 degrees, inclusive. There are none.

In her final question, she wants to know the number of admissible integer temperatures between 90 and 100 degrees, inclusive. There are 4: 92, 93, 94 and 97 degrees are all
admissible.

In the second test case, Karen knows 2 recipes.

1. The first one, "wikiHow to make Cold Brew Coffee", recommends brewing the coffee at exactly 1 degree.
2. The second one, "What good is coffee that isn't brewed at at least 36.3306 times the temperature of the surface of the sun?", recommends brewing the coffee at exactly 200000
    degrees.

A temperature is admissible if at least 1 recipe recommends it.

In her first and only question, she wants to know the number of admissible integer temperatures that are actually reasonable. There are none.

*/
