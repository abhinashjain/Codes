#include "vector"
#include "iostream"
#include "algorithm"
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define rep_stl(iter,begin,end) for(iter=begin;iter!=end;iter++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    dontsync()
    char type;
    int i,j,n,c,d,b,p,price,beauty,beauty2,two_max_coin,two_max_diamond,rem_price,total_beauty;
    int max_coin[100001]={0}, max_diamond[100001]={0}, max2_coin[100001]={-1}, max2_diamond[100001]={-1};
    vector<pair<int,int> > coin,diamond;
    vector<pair<int,int> >::iterator it,iter;
    cin >> n >> c >> d;
    rep(i,0,n)
    {
        cin >> b >> p >> type;
        if(type=='C')
        {
            if(p<=c)
            {
                coin.push_back(make_pair(p,b));
            }
        }
        else
        {
            if(p<=d)
            {
                diamond.push_back(make_pair(p,b));
            }
        }
    }

    if((coin.size()+diamond.size()) < 2)
    {
        cout << "0\n";
    }
    else
    {
        sort(coin.begin(),coin.end());
        sort(diamond.begin(),diamond.end());

        if(coin.size()>0)
        {
            j=1;
            rep_stl(it,coin.begin(),coin.end())
            {
                price=(*it).first;
                beauty=(*it).second;
                rep(i,j,price)
                {
                    max_coin[i]=max_coin[i-1];
                    max2_coin[i]=max2_coin[i-1];
                }
                if(max_coin[price-1] <= beauty)
                {
                    max2_coin[price]=max(max_coin[price],max_coin[price-1]);
                    max_coin[price]=beauty;
                }
                else
                {
                    max2_coin[price]=max(max2_coin[price-1],beauty);
                    max_coin[price]=max_coin[price-1];
                }
                j=price+1;
            }

            rep(i,j,c+1)
            {
                max_coin[i]=max_coin[i-1];
                max2_coin[i]=max2_coin[i-1];
            }
        }
        
        if(diamond.size()>0)
        {
            j=1;
            rep_stl(it,diamond.begin(),diamond.end())
            {
                price=(*it).first;
                beauty=(*it).second;
                rep(i,j,price)
                {
                    max_diamond[i]=max_diamond[i-1];
                    max2_diamond[i]=max2_diamond[i-1];
                }
                if(max_diamond[price-1] <= beauty)
                {
                    max2_diamond[price]=max(max_diamond[price],max_diamond[price-1]);
                    max_diamond[price]=beauty;
                }
                else
                {
                    max2_diamond[price]=max(max2_diamond[price-1],beauty);
                    max_diamond[price]=max_diamond[price-1];
                }
                j=price+1;
            }
            
            rep(i,j,d+1)
            {
                max_diamond[i]=max_diamond[i-1];
                max2_diamond[i]=max2_diamond[i-1];
            }
        }

        two_max_coin=0;
        rep_stl(it,coin.begin(),coin.end())
        {
            price=(*it).first;
            beauty=(*it).second;
            rem_price=c-price;
            if(max_coin[rem_price]!=0)
            {
                beauty2=max_coin[rem_price];
                if(beauty == beauty2)
                {
                    beauty2=max2_coin[rem_price];
                }
                total_beauty=beauty + beauty2;
                two_max_coin=max(total_beauty,two_max_coin);
            }
        }
        
        two_max_diamond=0;
        rep_stl(it,diamond.begin(),diamond.end())
        {
            price=(*it).first;
            beauty=(*it).second;
            rem_price=d-price;
            if(max_diamond[rem_price]!=0)
            {
                beauty2=max_diamond[rem_price];
                if(beauty == beauty2)
                {
                    beauty2=max2_diamond[rem_price];
                }
                total_beauty=beauty + beauty2;
                two_max_diamond=max(total_beauty,two_max_diamond);
            }
        }

        beauty=beauty2=0;
        if(max_coin[c]!=0 && max_diamond[d]!=0)
        {
            beauty=max_coin[c]+max_diamond[d];
        }
        beauty2=max(two_max_coin,two_max_diamond);
        cout << max(beauty,beauty2) << "\n";
    }
    return 0;
}


/*

Arkady plays Gardenscapes a lot. Arkady wants to build two new fountains. There are n available fountains, for each fountain its beauty and cost are known. There are two types of 
money in the game: coins and diamonds, so each fountain cost can be either in coins or diamonds. No money changes between the types are allowed.
Help Arkady to find two fountains with maximum total beauty so that he can buy both at the same time.

Input
The first line contains three integers n, c and d (2 ≤ n ≤ 100000, 0 ≤ c, d ≤ 100000) — the number of fountains, the number of coins and diamonds Arkady has.
The next n lines describe fountains. Each of these lines contain two integers bi and pi (1 ≤ bi, pi ≤ 100000) — the beauty and the cost of the i-th fountain, and then a letter "C"
or "D", describing in which type of money is the cost of fountain i: in coins or in diamonds, respectively.

Output
Print the maximum total beauty of exactly two fountains Arkady can build. If he can't build two fountains, print 0.

Examples
Input
3 7 6
10 8 C
4 3 C
5 6 D

Output
9

Input
2 4 5
2 5 C
2 1 D

Output
0

Input
3 10 10
5 5 C
5 5 C
10 11 D

Output
10

Note
In the first example Arkady should build the second fountain with beauty 4, which costs 3 coins. The first fountain he can't build because he don't have enough coins. Also Arkady 
should build the third fountain with beauty 5 which costs 6 diamonds. Thus the total beauty of built fountains is 9.

In the second example there are two fountains, but Arkady can't build both of them, because he needs 5 coins for the first fountain, and Arkady has only 4 coins.

*/
