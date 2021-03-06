#include "stdio.h"
#include "queue"
using namespace std;

int main()
{
	int i,n;
	scanf("%d",&n);
	while(n!=0)
	{
		queue<int> magc;
		for(i=1;i<=n;i++)
			magc.push(i);
		while(magc.size()!=1)
		{
			magc.pop();
			magc.push(magc.front());
			magc.pop();
		}
		printf("%d\n",magc.front());
		scanf("%d",&n);
	}
	return 0;            
}


/*
You are walking on the streets of New York when the famous illusionist David Blaine comes up to you. He is holding an ordered deck of 10 cards numbered 1 to 10 with card 1 at the top and card 10 at the bottom. He gives the pack of cards to you. He asks you to throw away the top card and move the card that is now on the top of the deck to the bottom of the deck and to keep doing this as long as there are at least two cards in the deck. When you are left with the last card in your hand he takes a minute and then says 4. To your amazement when you turn the card over, it is 4. How does he do it?
Write a program to predict the last card when there are n cards in the ordered deck.
Input

Each line of input (except the last) contains a positive number n. The last line contains 0 denoting the end inputs.

Output
For each number from input produce one line of output giving the last remaining card.

Constraints
1 ≤ n ≤ 200000

 
Example

Input:
8
15
23
9
0


Output:
8
14
14
2

*/
