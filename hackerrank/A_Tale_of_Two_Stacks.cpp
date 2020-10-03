#include "stdio.h"
#include "stack"
using namespace std;

int main()
{
    int i,j,k=0,q,type,x,cnt=0,top;
    stack<int> mystack1, mystack2;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d",&x);
            while(!mystack2.empty())
            {
                mystack1.push(mystack2.top());
                mystack2.pop();
            }
            mystack1.push(x);
        }
        else
        {
            if(type==2)
            {
                if(!mystack2.empty())
                    mystack2.pop();
                else
                    cnt++;
                k=0;
            }
            else
            {
                if(k)
                {
                    printf("%d\n",top);
                }
                else
                {
                    while(!mystack1.empty())
                    {
                        mystack2.push(mystack1.top());
                        mystack1.pop();
                    }
                    for(j=0;j<cnt;j++)
                    {
                        if(!mystack2.empty())
                            mystack2.pop();
                    }
                    cnt=0;
                    k=1;
                    top=mystack2.top();
                    printf("%d\n",top);
                }
            }
        }
    }
	return 0;
}


/*

A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added
to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always
the first one to be removed.
 
A basic queue has the following operations:
Enqueue: add a new element to the end of the queue.
Dequeue: remove the element from the front of the queue and return it.
 
In this challenge, you must first implement a queue using two stacks. Then process q queries, where each query is one of the following types:
1 x: Enqueue element x into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
 
Input Format
The first line contains a single integer, q, denoting the number of queries.
Each line i of the q subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query type, 
but only query 1 is followed by an additional space-separated value, x, denoting the value to be enqueued.
 
Constraints
1<=q<=10^5
1<=type<=3
1<=|x|<=10^9
It is guaranteed that a valid answer always exists for each query of type 3.
 
Output Format
For each query of type 3, print the value of the element at the front of the queue on a new line.
 
Sample Input
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2
 
Sample Output
14
14
 
Explanation
We perform the following sequence of actions:
 
Enqueue 42; queue={42}.
Dequeue the value at the head of the queue, 42; queue={}.
Enqueue 14; queue={14}.
Print the value at the head of the queue, 14; queue={14}.
Enqueue 28; queue={14 <- 28}.
Print the value at the head of the queue, 14; queue={14 <- 28}.
Enqueue 60; queue={14 <- 28 <- 60}.
Enqueue 78; queue={14 <- 28 <- 60 <- 78}.
Dequeue the value at the head of the queue, 14; queue={28 <- 60 <- 78}.
Dequeue the value at the head of the queue, 28; queue={60 <- 78}.

*/
