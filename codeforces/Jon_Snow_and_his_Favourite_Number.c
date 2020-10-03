#include "stdio.h"
#define MAX 1024
#define rep(i,begin,end) for(i=begin;i<end;i++)
#define reverse(i,end,begin) for(i=end;i>=begin;i--)

int main()
{
    int n,k,x,i,j,t,alternate,min,max,num,ind;
    int freq[MAX]={0};
    scanf("%d %d %d",&n,&k,&x);
    int arr[n];
    rep(i,0,n)
    {
        scanf("%d",&arr[i]);
        freq[arr[i]]++;
    }
    rep(t,0,k)
    {
        alternate=1;
        int tmp[MAX]={0};
        rep(i,0,MAX)
        {
            if(freq[i]>0)
            {
                ind=i^x;
                if(freq[i]&1)
                {
                    num=(freq[i]/2)+1;
                    tmp[ind]+=num-1;
                    tmp[i]+=num;
                    if(alternate&1)
                    {
                        tmp[ind]+=1;
                        tmp[i]-=1;
                    }
                }
                else
                {
                    num=freq[i]/2;
                    tmp[ind]+=num;
                    tmp[i]+=num;
                }
                alternate+=freq[i];
            }
        }
        rep(i,0,MAX)
        {
            freq[i]=tmp[i];
        }
    }
    rep(i,0,MAX)
    {
        if(freq[i]>0)
        {
            min=i;
            break;
        }
    }
    reverse(i,MAX-1,0)
    {
        if(freq[i]>0)
        {
            max=i;
            break;
        }
    }
    printf("%d %d\n",max,min);
    return 0;
}


/*

Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. Also Jon Snow has his favourite number x. Each ranger can fight with a white 
walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR
of strengths of some of rangers with his favourite number x, he might get soldiers of high strength. So, he decided to do the following operation k times:

1. Arrange all the rangers in a straight line in the order of increasing strengths.
2. Take the bitwise XOR (is written as xor) of the strength of each alternate ranger with x and update it's strength.

Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]
. Then he does the following:

1. The strength of first ranger is updated to 5 xor 2, i.e. 7.
2. The strength of second ranger remains the same, i.e. 7.
3. The strength of third ranger is updated to 9 xor 2, i.e. 11.
4. The strength of fourth ranger remains the same, i.e. 11.
5. The strength of fifth ranger is updated to 15 xor 2, i.e. 13.

The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times. He wants your help for this task. Can you help him?

Input
First line consists of three integers n, k, x (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^5, 0 ≤ x ≤ 10^3) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's
favourite number respectively.

Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 10^3).

Output
Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.

Examples
Input
5 1 2
9 7 11 15 5

Output
13 7

Input
2 100000 569
605 986

Output
986 605

*/
