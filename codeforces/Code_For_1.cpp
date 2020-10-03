#include "iostream"
#include "math.h"
#define rep(loop_var,begin,end) for(loop_var=begin;loop_var<=end;loop_var++)
using namespace std;

long long divide_and_conquer(long long nodes_in_sub_tree, long long n, long long range_array_ind)
{
    if(n==0 || n==1)
        return n;
    if((range_array_ind*2)==(nodes_in_sub_tree+1))
        return n&1;
    nodes_in_sub_tree/=2;
    n/=2;
    if(range_array_ind > (nodes_in_sub_tree+1))
    {
        range_array_ind=range_array_ind-(nodes_in_sub_tree+1);
    }
    return divide_and_conquer(nodes_in_sub_tree,n,range_array_ind);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,l,r,nodes_in_tree,log_n,tmp,ans,loop_var;
    cin >> n >> l >> r;
    tmp=n;
    ans=log_n=0;
    while(tmp>0)
    {
        tmp=tmp>>1;
        log_n++;
    }
    nodes_in_tree=pow(2,log_n)-1;
    rep(loop_var,l,r)
    {
        ans+=divide_and_conquer(nodes_in_tree,n,loop_var);
    }
    cout << ans << "\n";
    return 0;
}


/*

Jon fought bravely to rescue the wildlings who were attacked by the white-walkers at Hardhome. On his arrival, Sam tells him that he wants to go to Oldtown to train at the Citadel to
become a maester, so he can return and take the deceased Aemon's place as maester of Castle Black. Jon agrees to Sam's proposal and Sam sets off his journey to the Citadel. However 
becoming a trainee at the Citadel is not a cakewalk and hence the maesters at the Citadel gave Sam a problem to test his eligibility.

Initially Sam has a list with a single element n. Then he has to perform certain operations on this list. In each operation Sam must remove any element x, such that x > 1, from the 
list and insert at the same position floor(x/2), x%2 , floor(x/2), sequentially. He must continue with these operations until all the elements in the list are either 0 or 1.

Now the masters want the total number of 1s in the range l to r (1-indexed). Sam wants to become a maester but unfortunately he cannot solve this problem. Can you help Sam to pass 
the eligibility test?

Input
The first line contains three integers n, l, r (0 ≤ n < 2^50, 0 ≤ r - l ≤ 10^5, r ≥ 1, l ≥ 1) – initial element and the range l to r.
It is guaranteed that r is not greater than the length of the final list.

Output
Output the total number of 1s in the range l to r in the final sequence.

Examples
Input
7 2 5

Output
4

Input
10 3 10

Output
5

Note
Consider first example:
[7] -> [3,1,3] -> [1,1,1,1,3] -> [1,1,1,1,1,1,1]
Elements on positions from 2-nd to 5-th in list is [1, 1, 1, 1]. The number of ones is 4.

For the second example:
[10] -> [1,0,1,1,1,0,1,0,1,0,1,1,1,0,1]
Elements on positions from 3-rd to 10-th in list is [1, 1, 1, 0, 1, 0, 1, 0]. The number of ones is 5.

*/
