#include "stdio.h"
#define MAXSIZE 200001
#define max(x,y) (x > y) ? x : y
#define min(x,y) (x < y) ? x : y
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define reverse_rep(i,end,begin) for(i=end;i>=begin;i--)

int arr[MAXSIZE]={0}, present[MAXSIZE]={0}, tree[3*MAXSIZE];

int make_tree(int node, int start, int end)
{
    int left,right,mid;
    if(start==end)
    {
        tree[node] = arr[start];
        return 0;
    }
    left=node << 1;
    right=left+1;
    mid=(start+end) >> 1;
    
    make_tree(left, start, mid);
    make_tree(right, mid+1, end);
    tree[node]=max(tree[left], tree[right]);
    return 0;
}

int query(int node, int start, int end, int l, int r)
{
    int left,right,mid,i,j;
    if(l>r)
    {
        return 0;
    }
    
    if(l==start && r==end)
    {
        return tree[node];
    }

    left=node << 1;
    right=left+1;
    mid=(start+end) >> 1;
    
    i=query(left, start, mid, l, min(r, mid));
    j=query(right, mid+1, end, max(l, mid+1), r);
    return max(i, j);
}

int main()
{
    int i,j,n,k,p,cnt,size_double,start,end;
    scanf("%d %d %d",&n,&k,&p);
    char str[p];
    size_double=2*n;
    rep(i,1,n+1)
    {
        scanf("%d",&arr[i]);
        arr[n+i]=arr[i];
        if(arr[i]==1)
        {
            cnt++;
        }
        arr[i]=arr[i]+arr[i-1];
    }
    scanf("%s",str);

    if(k>=n)
    {
        rep(i,0,p)
        {
            if(str[i]=='?')
            {
                printf("%d\n",cnt);
            }
        }
    }
    else
    {
        rep(i,n+1,size_double+1)
        {
            arr[i]=arr[i]+arr[i-1];
        }
        reverse_rep(i,size_double,k)
        {
            arr[i]=arr[i]-arr[i-k];
        }
        start=n+k;
        end=size_double;
        make_tree(1,1,size_double);
        rep(i,0,p)
        {
            if(str[i]=='?')
            {
                if(present[start]==0)
                {
                    present[start]=query(1,1,size_double,start,end);
                }
                printf("%d\n",present[start]);
            }
            else
            {
                start--;
                end--;
                if(start==k)
                {
                    start=n+k;
                    end=size_double;
                }
            }
        }
    }
    return 0;
}


/*

Chef has a binary array A of length N. He also has a frame that can focus on at max K consecutive elements of the array.

Chef has a lovely dog which likes to do following two things.

Shifting the array A to the right by one element (N-th element becomes 1st, 1st becomes 2nd and so on)
Asking Chef what is the maximal number of elements equal to 1, that can be captured by a frame (frame can capture not more than K consecutive elements of array).

Help Chef entertain his Dog!

Input
The first line of each test case contains three integers N, K and P denoting the number of elements in array A, size of a frame and the number of Dog's requests.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of array.

The third line contains string consisting of P characters, i-th character stands for dog's i-th question and equals '!' if Dog shifts the array and '?' if dog asks what is the 
maximal number of ones captured by the frame.

Output
For each Dog's question output a single line containing an integer corresponding to the answer of the question.

Constraints
1 ≤ N, K, P ≤ 10^5
0 ≤ Ai ≤ 1

Subtasks
Subtask #1 (30 points) N, K, P ≤ 10^3
Subtask #2 (70 points) Original constraints.

Example
Input:
5 3 4
1 0 0 1 1
?!!?

Output:
2
3

Explanation
Example case 1.
For the first question , Chef can pick last 3 elements (or last two, no matter) for his frame, and will have 2 elements equal 1.

After first shift (exclamation mark) array will become: 1 1 0 0 1.

After second shift (exclamation mark) array will become: 1 1 1 0 0.

Now for the second question Chef can pick first 3 elements for his frame, and will have 3 elements equal 1.

*/
