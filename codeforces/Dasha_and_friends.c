#include "stdio.h"

int main()
{
    int n,l,i,cnt,tmp,num;
    scanf("%d %d",&n,&l);
    int arr1[n],arr2[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    tmp=arr1[n-1];
    for(i=(n-1);i>0;i--)
    {
        arr1[i]-=arr1[i-1];
    }
    arr1[0]+=l-tmp;

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr2[i]);
    }
    tmp=arr2[n-1];
    for(i=(n-1);i>0;i--)
    {
        arr2[i]-=arr2[i-1];
    }
    arr2[0]+=l-tmp;

    i=cnt=num=0;
    while(cnt!=n && num<=n)
    {
        if(arr1[i]==arr2[i])
        {
            cnt++;
            i++;
        }
        else
        {
            num++;
            tmp=arr1[n-1];
            for(i=(n-1);i>0;i--)
            {
                arr1[i]=arr1[i-1];
            }
            arr1[0]=tmp;
            i=cnt=0;
        }
    }
    if(cnt==n)
        printf("YES\n");
    else
        printf("NO\n");
	return 0;
}


/*

Running with barriers on the circle track is very popular in the country where Dasha lives, so no wonder that on her way to classes she saw the following situation:
 
The track is the circle with length L, in distinct points of which there are n barriers. Athlete always run the track in counterclockwise direction if you look on him from above. All 
barriers are located at integer distance from each other along the track.
 
Her friends the parrot Kefa and the leopard Sasha participated in competitions and each of them ran one lap. Each of the friends started from some integral point on the track. Both 
friends wrote the distance from their start along the track to each of the n barriers. Thus, each of them wrote n integers in the ascending order, each of them was between 0 and L - 
1, inclusively.

                        Dasha_and_friends.png

Consider an example. Let L = 8, blue points are barriers, and green points are Kefa's start (A) and Sasha's start (B). Then Kefa writes down the sequence [2, 4, 6], and Sasha writes 
down [1, 5, 7].
 
There are several tracks in the country, all of them have same length and same number of barriers, but the positions of the barriers can differ among different tracks. Now Dasha is 
interested if it is possible that Kefa and Sasha ran the same track or they participated on different tracks.
 
Write the program which will check that Kefa's and Sasha's tracks coincide (it means that one can be obtained from the other by changing the start position). Note that they always 
run the track in one direction — counterclockwise, if you look on a track from above.
 
Input
The first line contains two integers n and L (1 ≤ n ≤ 50, n ≤ L ≤ 100) — the number of barriers on a track and its length.

The second line contains n distinct integers in the ascending order — the distance from Kefa's start to each barrier in the order of its appearance. All integers are in the range
from 0 to L - 1 inclusively.
 
The second line contains n distinct integers in the ascending order — the distance from Sasha's start to each barrier in the order of its overcoming. All integers are in the range 
from 0 to L - 1 inclusively.

Output
Print "YES" (without quotes), if Kefa and Sasha ran the coinciding tracks (it means that the position of all barriers coincides, if they start running from the same points on the 
track). Otherwise print "NO" (without quotes).
 
Examples
Input
3 8
2 4 6
1 5 7
 
Output
YES
 
Input
4 9
2 3 5 8
0 1 3 6
 
Output
YES
 
Input
2 4
1 3
1 2
 
Output
NO
 
Note
The first test is analyzed in the statement.

*/
