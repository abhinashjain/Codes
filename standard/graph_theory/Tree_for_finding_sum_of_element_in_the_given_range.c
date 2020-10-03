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
