#include <stdio.h>
#define number_of_elements 200001
int arr[number_of_elements];
int tree[4*number_of_elements]; // size is 2^((ceil of log2(number_of_elements)) + 1)

int make_tree(int node , int beg , int endd)
{
    if(beg==endd)
    {
        tree[node] = arr[beg];
        return 0;
    }
    int left = node *2;
    int right = left + 1;
    int mid = (beg + endd ) >>1;
    
    make_tree(left , beg ,  mid);
    make_tree(right , mid+1 , endd);
    tree[node] = max(tree[left], tree[right]);  //min() for making min-tree
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
    return max(l, r);
}

int main()
{
    arr[0]=0;
    int n=number_of_elements-1,res;
    int sizeofarray=n,start_index_of_array=1,end_index_of_array=n,start_of_range=2,end_of_range=n-3;
    make_tree(1, start_index_of_array, end_index_of_array);
    res=query(1, start_index_of_array, end_index_of_array, start_of_range, end_of_range);
    return 0;
}
