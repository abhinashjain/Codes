#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int t,i,j,count,c;
	char nm[200];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		map<char,int> name;
		map<char, int>::iterator iter;
		scanf("%s",nm);
		for(j=0;j<strlen(nm);j++)
		{
			iter=name.find(nm[j]);
			if(iter == name.end())
			{
				name.insert ( pair<char,int>(nm[j],1) );
			}
			else
			{
				count=(*iter).second;
				count++;
				name[nm[j]]=count;
			}
		}
		c=0;
		for (iter = name.begin(); iter != name.end(); iter++)
		{
			count=(*iter).second;
			if((count % 2)==0)
			{
				c += count/2;
			}
			else
			{
				c+= (count+1)/2;
			}
		}
		printf("%d\n",c);
	}
	return 0;
}

/*

One day Alice visited Byteland to purchase jewels for her upcoming wedding anniversary.

In Byteland, every Jewelry shop has their own discount methods to attract the customers. One discount method called Buy1-Get1 caught Alice's attention. That is, Alice buys one jewel, then she can get one additional jewel with the same color without charge by Buy1-Get1.

Alice lists the needed jewels as a string S, each letter denotes one jewel, and the same letters denote the same colors of jewels, and the different letters denote the different colors of jewels. The cost of each jewel is 1. Your task is to calculate the minimum cost for getting all the jewels Alice listed.
Input

The first line of input contains a single line T, which represents the number of test cases. Then T lines will follow, and each contains a string S, which represents the jewels Alice needed.
Output

Output the minimum cost for each test case.
Constraints

1 ≤ T ≤ 100
1 ≤ |S| ≤ 200, where |S| represents the length of the string S.
The string S is case sensitive, and will contain only English characters in the range [a-z], [A-Z].
Sample

Input:
5
ssss
ssas
sa
s
saas

Output:
2
3
2
1
2

Explanation

In the first sample case, Alice needs 4 jewel of color s. One of the optimal way is the following:
Buy the first s with cost 1, and she can get the second s without charge. Then buy the third s with cost 1, and she can get the last s without charge. In this case, she get 4 jewels with only cost 2.

In the second sample case, Alice needs 3 jewels of color s and 1 jewel of color a. One of the optimal way is the following:
Buy the second s with cost 1, and she can get the last s without charge. Then buy the a and the first s with cost 2. In this case, she get 4 jewels with only cost 3.

In the third and fourth sample cases, she cannot save her money by using Buy1-Get1.

*/
