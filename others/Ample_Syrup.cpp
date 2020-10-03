#include "vector"
#include "iostream"
#include "algorithm"
#define pi 3.141592653589795
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define precision_with_no_exponents()   cout.setf(ios::fixed, ios::floatfield); cout.setf(ios::showpoint); cout.precision(9);
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool sort_second_in_descending(const pair<double,long long> &a, const pair<double,long long> &b)
{
    //sort first in asecending order
    if(a.first<b.first)
        return 1;
    if(a.first>b.first)
        return 0;

    //if first elements are equal, then sort second in desccending order
    if(a.second > b.second)
        return 1;
    return 0;   //make sure to always return false (not true) in the last case. Otherwise it might get stuck on infinite loop and result in segfault
}

int main()
{
    dontsync()
    long long t,n,k,r,h,i,j,maxradius;
    double area,tmp,maxarea;
    cin >> t;
    rep(i,0,t)
    {
        cin >> n >> k;
        vector<pair<double,long long> > vect;
        rep(j,0,n)
        {
            cin >> r >> h;
            area=2 * r * h;
            vect.push_back(make_pair(area,r));
        }
        sort(vect.begin(),vect.end());//,sort_second_in_descending);
        reverse(vect.begin(),vect.end());
        maxradius=area=0;
        rep(j,0,k-1)
        {
            area+=vect[j].first;
            r=vect[j].second;
            maxradius=max(maxradius,r);
        }
        tmp=maxarea=0;
        rep(j,k-1,n)
        {
            r=vect[j].second;
            if(r>=maxradius)
            {
                tmp=(r * r) + vect[j].first;
                maxarea=max(maxarea,tmp);
            }
        }

        //some element between 0 to k-1 can have max radius
        tmp=(maxradius * maxradius); //add that elements pi*r*r because earlier we only considered it's 2*r*h.
        tmp+=vect[k-1].first; //consider the 2*r*h of k-1 th element

        area+=max(maxarea,tmp);

        precision_with_no_exponents()
        cout << "Case #" << i+1 << ": " << area*pi << "\n";
    }
    return 0;
}


/*

The kitchen at the Infinite House of Pancakes has just received an order for a stack of K pancakes! The chef currently has N pancakes available, where N ≥ K. Each pancake is a 
cylinder, and different pancakes may have different radii and heights.

As the sous-chef, you must choose K out of the N available pancakes, discard the others, and arrange those K pancakes in a stack on a plate as follows. First, take the pancake that 
has the largest radius, and lay it on the plate on one of its circular faces. (If multiple pancakes have the same radius, you can use any of them.) Then, take the remaining pancake 
with the next largest radius and lay it on top of that pancake, and so on, until all K pancakes are in the stack and the centers of the circular faces are aligned in a line 
perpendicular to the plate, as illustrated by this example:

                                                        Ample_Syrup.png

A stack of pancakes with varying radii and thicknesses, obeying the rules in the statement.

You know that there is only one thing your diners love as much as they love pancakes: syrup! It is best to maximize the total amount of exposed pancake surface area in the stack, 
since more exposed pancake surface area means more places to pour on delicious syrup. Any part of a pancake that is not touching part of another pancake or the plate is considered to 
be exposed.

If you choose the K pancakes optimally, what is the largest total exposed pancake surface area you can achieve?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each begins with one line with two integers N and K: the total number of available pancakes, and 
the size of the stack that the diner has ordered. Then, N more lines follow. Each contains two integers Ri and Hi: the radius and height of the i-th pancake, in millimeters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum possible total exposed pancake surface area, in 
millimeters squared. y will be considered correct if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means,
and what formats of real numbers we accept.

Limits
1 ≤ T ≤ 100.
1 ≤ K ≤ N.
1 ≤ Ri ≤ 10^6, for all i.
1 ≤ Hi ≤ 10^6, for all i.

Small dataset
1 ≤ N ≤ 10.

Large dataset
1 ≤ N ≤ 1000.

Sample
Input
4
2 1
100 20
200 10
2 2
100 20
200 10
3 2
100 10
100 10
100 10
4 2
9 3
7 1
10 1
8 4

Output
Case #1: 138230.076757951
Case #2: 150796.447372310
Case #3: 43982.297150257
Case #4: 625.176938064

In Sample Case #1, the "stack" consists only of one pancake. A stack of just the first pancake would have an exposed area of π × R02 + 2 × π * R0 × H0 = 14000π mm2. A stack of just 
the second pancake would have an exposed area of 44000π mm2. So it is better to use the second pancake.

In Sample Case #2, we can use both of the same pancakes from case #1. The first pancake contributes its top area and its side, for a total of 14000π mm2. The second pancake 
contributes some of its top area (the part not covered by the first pancake) and its side, for a total of 34000π mm2. The combined exposed surface area is 48000π mm2.

In Sample Case #3, all of the pancakes have radius 100 and height 10. If we stack two of these together, we effectively have a single new cylinder of radius 100 and height 20. The 
exposed surface area is 14000π mm2.

In Sample Case #4, the optimal stack uses the pancakes with radii of 8 and 9.

*/
