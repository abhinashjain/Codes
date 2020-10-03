#include "stdio.h"

int main()
{
    int t,i,y,c,d,l,tot;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d %d",&c,&d,&l);
        tot=c+d;
        if(l%4!=0)
        {
            y=0;
        }
        else
        {
            l=l/4;
            if(l>tot || l<d)
            {
                y=0;
            }
            else
            {
                if(tot==l)
                {
                    y=1;
                }
                else
                {
                    tot=tot-l;
                    if(tot<=(d*2))
                        y=1;
                    else
                        y=0;
                }
            }
        }
        if(y==1)
            printf("yes\n");
        else
            printf("no\n");
	}
	return 0;
}


/*
 
Chef is a farmer and a pet lover. He has a lot of his favorite pets cats and dogs in the barn. He does not know their exact count. But he knows that there are C cats and D dogs in
the barn. Also, one day went to field and found that there were L legs of the animals touching the ground. Chef knows that cats love to ride on the dogs. So, they might ride on the
dogs, and their legs won't touch the ground and Chef would miss counting their legs. Chef's dogs are strong enough to ride at max two cats on their back.
 
It was a cold foggy morning, when Chef did this counting. So he is now wondering whether he counted the legs properly or not. Specifically, he is wondering is there a some 
possibility of his counting being correct. Please help Chef in finding it.
 
Input
First line of the input contains an integer T denoting number of test cases. T test cases follow.
The only line of each test case contains three space separated integers C, D, L denoting number of the cats, number of the dogs and number of legs of animals counted by Chef, 
respectively.
 
Output
For each test case, output a single line containing a string "yes" or "no" (both without quotes) according to the situation.
 
Constraints
1 ≤ T ≤ 10^5
0 ≤ C, D, L ≤ 10^9
 
Subtasks
Subtask #1 (20 points)
1 ≤ T ≤ 10^4
0 ≤ C, D ≤ 10^2
 
Subtask #2 (30 points)
1 ≤ T ≤ 10^5
0 ≤ C, D ≤ 10^3
 
Subtask #3 (50 points)
Original constraints
 
Example
Input:
3
1 1 8
1 1 4
1 1 2
 
Output:
yes
yes
no
 
Explanation
Example 1. There is one cat and one dog. The number of legs of these animals on the ground are 8, it can be possible when both cat and dog are standing on the ground.
Example 2. There is one cat and one dog. The number of legs of these animals on the ground are 4, it can be possible if the cat will ride on the dog, so its legs won't be counted by 
Chef, only the dog's legs will be counted.
Example 3. There is one cat and one dog. The number of legs of these animals are 2, it can not be true at all, Chef might have made some mistake. Hence answer is "no".
 
*/
