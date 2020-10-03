#include "stdio.h"

int main()
{
    int n,i;
    long long xd,yd,xv,yv;
    scanf("%lld %lld",&xv,&yv);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&xd,&yd);
        xv-=xd;
        yv-=yd;
    }
    printf("%lld %lld",xv,yv);
    return 0;
}


/*

After sailing the ocean for ages, Luffy the Pirate finally found the greatest treasure in the world, known as the One Piece. He wants to return to his village as the Pirate King, but
he forgot its coordinates! Fortunately, he has a list containing the sequence of directions he took from his village to the location of the treasure.
 
Each direction(i) consists of some xd(i) and yd(i) describing the number of units he traveled along the respective x and y axes when following direction(i). In other words, for each 
direction(i) in the list, Luffy traveled from some position (x,y) to position (x+xd(i), y+yd(i)).
 
Given two long integers describing the One Piece treasure's cartesian coordinates, (xt,yt), and a list of the n directions Luffy followed to get there, can you find the location of 
Luffy's village at (xv,yv)? Once you've located it, print two space-separated long integers describing the respective values of xv and yv on a new line.
 
Note: The directions describe the route Luffy took from his village at (xv,yv) to the treasure at (xt,yt) — they do not describe his route home.
 
Input Format
The first line contains two space-separated long integers describing the respective values of xt and yt (the location of the treasure).
The second line contains an integer denoting n (the number of directions in his list).
Each line i of the n subsequent lines contain two space-separated long integers describing the respective values of xd(i) and yd(i) for direction(i).
 
Constraints
-10^9 <= xt,yt,xd,yd <= 10^9
1<=n<=10^5

Output Format
Print two space-separated long integers describing the respective values of xv and yv (i.e., the coordinates of Luffy's village).
 
Sample Input 0
1 1
2
1 0
0 1
 
Sample Output 0
0 0
 
Sample Input 1
-3 -4
3
-2 -2
-1 0
0 1
 
Sample Output 1
0 -3

*/
