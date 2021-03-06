#include <stdio.h>

int main()
{
	int n,t;
	scanf("%d",&t);
	for(;t!=0;t--)
	{
		scanf("%d",&n);
		if(n%2==0)
			printf("YES\n");
		else	if(n%3==0)	
				printf("YES\n");
			else 
				printf("NO\n");
	}
	return 0;     
}

/*
Ted (the popular talking bear) has been given a job at the printing firm. Looking at his previous employment record, the firm is watching very strictly on his work product. Recently, he has been assigned a task to print on a square sheet of dimension NxN. You may think of the sheet containing N2 cells of dimension 1x1 each. Since, Ted is a lazy bear, he somehow steals two stamps, a horizontal printing stamp which covers a 1*2 block and a vertical printing stamp which covers a 3*1 block. He may use these two stamps in any order and as many times as he wants. But the sheets are old, if the sheet is stamped twice at any cell, it will tear off. Now, there is a shipment of sheets coming with varying sizes. But he observes that in some of the cases it is not possible to completely fill the square sheet with no overlapping stamps. So, he asks for your help in deciding whether it is possible to fill the square sheet with the stamps without any overlapping.
Input

The first line of the input contains an integer T, denoting the number of sheets in the shipment.
It is followed by T lines each containing a single integer N denoting the side of the square sheet.
Output

For each test case, output a single line containing “YES” (without quotes) if it is possible to fill the square sheet without overlapping the stamps and “NO” (without quotes) otherwise.
Constraints

    1 ≤ T ≤ 5*105
    1 ≤ N ≤ 106

Example

Input:
1
2

Output:
YES
*/
