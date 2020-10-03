#include<stdio.h>
#include<set>
#include<string.h>

using namespace std;

int main()
{
    int t;
    long int len, i, tempi;
    bool decreasing;
    char arr[100000];
    scanf("%d", &t);
    while(t--)
    {
        decreasing = true;
        multiset<int> str_dec;
        multiset<int>::iterator it;
        multiset<int>::iterator it2;
        scanf("%s", arr);
        len = strlen(arr);
        for(i=len-1; i>=1; i--)
        {

            if(arr[i] <= arr[i-1])       // checks from strictly decreasing order
            {
                str_dec.insert(arr[i] - 48);// printf("insert %c\n", arr[i]);
            }
            else
            {
                str_dec.insert(arr[i] - 48);//    printf("insert %c\n", arr[i]);
                str_dec.insert(arr[i-1] - 48);//  printf("insert %c\n", arr[i-1]);
                decreasing = false;
                break;
            }
        }
        if(decreasing == false)
        {
//            printf("enter decreasing false\n");
            tempi = i;
            it = str_dec.find(arr[i-1] - 48);//   printf("find for %c\n", arr[i-1]);
            arr[i-1] = *(++it) + 48;
            str_dec.erase(it);//  printf("erase %d\n", (*it));
//        for(it=str_dec.begin(); it!=str_dec.end(); it++)
//        {
//            printf("size of set is %d\n", str_dec.size());
//            printf("%d\n", (*it));
//        }

            it = str_dec.begin();
            for(i=tempi; i<len; i++)
            {
                arr[i] = (*it) + 48;
                it++;// printf("put %d\n", (*it));
//                printf("tempi = %d, it = %d", tempi, *it);
            }
            printf("%s\n", arr);
        }
        else
            printf("-1\n");
//        printf("%s\n", arr);
//        for(it=str_dec.begin(); it!=str_dec.end(); it++)
//        {
//            printf("%d\n", (*it));
//        }

    }
    return 0;
}


/*

Young Matt and Jeff loved playing with numbers. One fine day, when Matt's little brother Paul, was at his math lesson with plastic number toys i.e. plastic toys in shape of digits 0 to 9, Matt and Jeff decided to play a game.
Paul had left the plastic numbers arranged to form a number N.
The rules of the game were as follows:

    The first player has to rearrange the digits to form a larger number than the current number, after that the game will be played turn-wise.
    After the first turn, each player has to rearrange the digits so that it is smaller than the current number in that turn and greater than the original number N.
    The player loses if he cannot arrange a number.



What number should the first player form, so that he always wins?
Input

An integer T (1 ≤ T ≤ 100) denoting number of test cases followed by T lines each containing an integer N, the number Paul has formed. The number of digit in N is D(1 ≤ D ≤ 100000).
Output

For each test case, output a number which first player should form so that he wins, in a separate line.
If there is no winning strategy for first player, then output -1.
Example

Input:
3
17
81
123

Output:
71
-1
132

*/
