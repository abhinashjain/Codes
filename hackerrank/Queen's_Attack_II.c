#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,rq,cq,ri,ci,i,f,diagvalr,diagvalc;
    scanf("%d %d",&n,&k);
    int leftcol=0,rightcol=n+1,uprow=0,downrow=n+1,diag1=n+1,diag2=n+1,diag3=n+1,diag4=n+1;
    scanf("%d %d",&rq,&cq);
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&ri,&ci);
        f=1;
        if(rq==ri && f)
        {
            if(ci>cq && rightcol>ci)
            {
                rightcol=ci;
            }
            if(ci<cq && leftcol<ci)
            {
                leftcol=ci;
            }
            f=0;
        }
        if(cq==ci && f)
        {
            if(ri>rq && downrow>ri)
            {
                downrow=ri;
            }
            if(ri<rq && uprow<ri)
            {
                uprow=ri;
            }
            f=0;
        }
        diagvalr=abs(rq-ri);
        diagvalc=abs(cq-ci);
        if(diagvalr==diagvalc && f)
        {
            if(ri>rq && ci>cq)
            {
                if(diag1>diagvalc)
                {
                    diag1=diagvalc;
                }
            }
            if(ri>rq && ci<cq)
            {
                if(diag2>diagvalc)
                {
                    diag2=diagvalc;
                }
            }
            if(ri<rq && ci<cq)
            {
                if(diag3>diagvalc)
                {
                    diag3=diagvalc;
                }
            }
            if(ri<rq && ci>cq)
            {
                if(diag4>diagvalc)
                {
                    diag4=diagvalc;
                }
            }
        }
    }

    leftcol=cq-leftcol-1;
    rightcol=rightcol-cq-1;
    uprow=rq-uprow-1;
    downrow=downrow-rq-1;
    
    if(diag1==(n+1))
    {
        ri=rq+1;
        ci=cq+1;
        diag1=0;
        while(ri<=n && ci<=n)
        {
            ri++;
            ci++;
            diag1++;
        }
    }
    else
    {
        diag1--;
    }
    
    if(diag2==(n+1))
    {
        ri=rq+1;
        ci=cq-1;
        diag2=0;
        while(ri<=n && ci>=1)
        {
            ri++;
            ci--;
            diag2++;
        }
    }
    else
    {
        diag2--;
    }
    
    if(diag3==(n+1))
    {
        ri=rq-1;
        ci=cq-1;
        diag3=0;
        while(ri>=1 && ci>=1)
        {
            ri--;
            ci--;
            diag3++;
        }
    }
    else
    {
        diag3--;
    }
    
    if(diag4==(n+1))
    {
        ri=rq-1;
        ci=cq+1;
        diag4=0;
        while(ri>=1 && ci<=n)
        {
            ri--;
            ci++;
            diag4++;
        }
    }
    else
    {
        diag4--;
    }
    
    printf("%d\n",leftcol+rightcol+uprow+downrow+diag1+diag2+diag3+diag4);
    return 0;
}


/*

A queen is standing on an nxn chessboard. The chessboard's rows are numbered from 1 to n, going from bottom to top; its columns are numbered from 1 to n, going from left to right. 
Each square on the board is denoted by a tuple, (r,c), describing the row, r, and column, c, where the square is located.
 
The queen is standing at position (rq,cq) and, in a single move, she can attack any square in any of the eight directions (left, right, up, down, or the four diagonals). In the 
diagram below, the green circles denote all the cells the queen can attack from (4,4):
 
            Queen's_Attack_II_1.png
 
There are k obstacles on the chessboard preventing the queen from attacking any square that has an obstacle blocking the the queen's path to it. For example, an obstacle at location 
(3,5) in the diagram above would prevent the queen from attacking cells (3,5), (2,6), and (1,7):
 
            Queen's_Attack_II_2.png
 
Given the queen's position and the locations of all the obstacles, find and print the number of squares the queen can attack from her position at (rq,cq).
 
Input Format
The first line contains two space-separated integers describing the respective values of n (the side length of the board) and k (the number of obstacles).
The next line contains two space-separated integers describing the respective values of rq and cq, denoting the position of the queen.
Each line i of the k subsequent lines contains two space-separated integers describing the respective values of ri and ci, denoting the position of obstacle i.
 
Constraints
0<n<=10^5
0<=k<=10^5
A single cell may contain more than one obstacle; however, it is guaranteed that there will never be an obstacle at position (rq,cq) where the queen is located.
 
Subtasks
For 30% of the maximum score:
0<n<=100
0<=k<=100
 
For 55% of the maximum score:
0<n<=1000
0<=k<=10^5

Output Format
Print the number of squares that the queen can attack from position (rq,cq).
 
Sample Input 0
4 0
4 4
 
Sample Output 0
9
 
Explanation 0
The queen is standing at position (4,4) on a 4x4 chessboard with no obstacles:
 
        Queen's_Attack_II_3.png
 
We then print the number of squares she can attack from that position, which is 9.
 
Sample Input 1
5 3
4 3
5 5
4 2
2 3
 
Sample Output 1
10
 
Explanation 1
The queen is standing at position (4,3) on a 5x5 chessboard with k=3 obstacles:
 
        Queen's_Attack_II_4.png
 
We then print the number of squares she can attack from that position, which is 10.

*/
