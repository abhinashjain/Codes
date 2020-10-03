#include <iostream>
using namespace std;

class node
{
    public:
        int val;
        node * right, * left;
};

void insert(node ** tree, node * item)
{
    if(!(*tree))
    {
        *tree = item;
        return;
    }
    if(item->val<(*tree)->val)
    {
        insert(&(*tree)->left, item);
    }
    
    else
    {
        if(item->val>(*tree)->val)
            insert(&(*tree)->right, item);
    }
}

int isPresent(node* root, int val)
{
    static int ans=0;
    if(val==root->val)
        ans=1;
    if (root->left != NULL)
        isPresent(root->left,val);
    if (root->right != NULL)
        isPresent(root->right,val);
    return ans;
}

int main()
{
    node  * _root, * root_curr;
    int root_i=0, root_cnt = 0, root_num = 0, _x;
    _root = NULL;
    cin >> root_cnt;
    for(root_i = 0; root_i < root_cnt; root_i++)
    {
        scanf("%d", &root_num);
        root_curr = (node *)malloc(sizeof(node));
        
        root_curr->left = root_curr->right = NULL;
        root_curr->val = root_num;
        
        insert(&_root, root_curr);
    }
    
    cin >> _x;
    cout << isPresent(_root, _x) << "\n";
    return 0;
}


/*

Sample Input Tree for #1 and #2:
                    20
        10                      30
    8       12              25      40
6       11      13      23

Input #1:
11
20
10
30
8
12
25
40
6
11
13
23
30

Output #1:
1

Explanation #1:
The element 30 is present in the given tree so return 1.

Input #2:
11
20
10
30
8
12
25
40
6
11
13
23
79

Output #2:
0

Explanation #2:
The element 79 is not present in the given tree so return 0.
 
*/
