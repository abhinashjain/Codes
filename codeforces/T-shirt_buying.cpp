#include "set"
#include "iostream"
#include "algorithm"
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    dontsync()
    int i,j,n,m,c,price,front,back,buy,flag;
    set<int> cust[4];
    set<int>::iterator iter;
    cin >> n;
    int p_arr[n],a_arr[n],b_arr[n];
    rep(i,0,n)
    {
        cin >> p_arr[i];
    }
    rep(i,0,n)
    {
        cin >> a_arr[i];
        
    }
    rep(i,0,n)
    {
        cin >> b_arr[i];
    }
    rep(i,0,n)
    {
        cust[a_arr[i]].insert(p_arr[i]);
        if(a_arr[i]!=b_arr[i])
        {
            cust[b_arr[i]].insert(p_arr[i]);
        }
    }
    cin >> m;
    rep(i,0,m)
    {
        cin >> c;
        flag=1;
        if(cust[c].size())
        {
            iter=cust[c].begin();
            buy=*(iter);
            cust[c].erase(iter);
            cout << buy << " ";
            if(c==1)
            {
                iter=cust[2].find(buy);
                if(iter!=cust[2].end())
                {
                    flag=0;
                    cust[2].erase(iter);
                }
                if(flag)
                {
                    iter=cust[3].find(buy);
                    if(iter!=cust[3].end())
                    {
                        cust[3].erase(iter);
                    }
                }
            }
            else
            {
                if(c==2)
                {
                    iter=cust[1].find(buy);
                    if(iter!=cust[1].end())
                    {
                        flag=0;
                        cust[1].erase(iter);
                    }
                    if(flag)
                    {
                        iter=cust[3].find(buy);
                        if(iter!=cust[3].end())
                        {
                            cust[3].erase(iter);
                        }
                    }
                }
                else
                {
                    iter=cust[2].find(buy);
                    if(iter!=cust[2].end())
                    {
                        flag=0;
                        cust[2].erase(iter);
                    }
                    if(flag)
                    {
                        iter=cust[1].find(buy);
                        if(iter!=cust[1].end())
                        {
                            cust[1].erase(iter);
                        }
                    }
                }
            }
        }
        else
        {
            cout << "-1 ";
        }
    }
    return 0;
}


/*

A new pack of n t-shirts came to a shop. Each of the t-shirts is characterized by three integers pi, ai and bi, where pi is the price of the i-th t-shirt, ai is front color of the 
i-th t-shirt and bi is back color of the i-th t-shirt. All values pi are distinct, and values ai and bi are integers from 1 to 3.

m buyers will come to the shop. Each of them wants to buy exactly one t-shirt. For the j-th buyer we know his favorite color cj.

A buyer agrees to buy a t-shirt, if at least one side (front or back) is painted in his favorite color. Among all t-shirts that have colors acceptable to this buyer he will choose 
the cheapest one. If there are no such t-shirts, the buyer won't buy anything. Assume that the buyers come one by one, and each buyer is served only after the previous one is served.

You are to compute the prices each buyer will pay for t-shirts.

Input
The first line contains single integer n (1 ≤ n ≤ 200000) — the number of t-shirts.
The following line contains sequence of integers p1, p2, ..., pn (1 ≤ pi ≤ 1000000000), where pi equals to the price of the i-th t-shirt.
The following line contains sequence of integers a1, a2, ..., an (1 ≤ ai ≤ 3), where ai equals to the front color of the i-th t-shirt.
The following line contains sequence of integers b1, b2, ..., bn (1 ≤ bi ≤ 3), where bi equals to the back color of the i-th t-shirt.
The next line contains single integer m (1 ≤ m ≤ 200000) — the number of buyers.

The following line contains sequence c1, c2, ..., cm (1 ≤ cj ≤ 3), where cj equals to the favorite color of the j-th buyer. The buyers will come to the shop in the order they are 
given in the input. Each buyer is served only after the previous one is served.

Output
Print to the first line m integers — the j-th integer should be equal to the price of the t-shirt which the j-th buyer will buy. If the j-th buyer won't buy anything, print -1.

Examples
Input
5
300 200 400 500 911
1 2 1 2 3
2 1 3 2 1
6
2 3 1 2 1 1

Output
200 400 300 500 911 -1

Input
2
1000000000 1
1 1
1 2
2
2 1

Output
1 1000000000

*/
