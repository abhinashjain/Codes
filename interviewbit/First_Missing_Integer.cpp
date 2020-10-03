int firstMissingPositive(vector<int> &A)
{
    int ind,tmp,tmp2,n=A.end()-A.begin();
    for(ind=0;ind<n;ind++)
    {
        if(A[ind]<1 || A[ind]>n)
        {
            A[ind]=0;
        }
    }
    for(ind=0;ind<n;ind++)
    {
        if(A[ind]!=0 && A[A[ind]-1]==0)
        {
            A[A[ind]-1]=A[ind];
            A[ind]=0;
        }
    }
    for(ind=0;ind<n;ind++)
    {
        if(A[ind]!=0 && A[ind]!=(ind+1))
        {
            tmp=A[A[ind]-1];
            A[A[ind]-1]=A[ind];
            A[ind]=0;
            while(tmp!=0 && A[tmp-1]!=tmp)
            {
                tmp2=A[tmp-1];
                A[tmp-1]=tmp;
                tmp=tmp2;
            }
        }
    }
    for(ind=0;ind<n;ind++)
    {
        if(A[ind]==0)
            break;
    }
    return ind+1;
}


/*

Given an unsorted integer array, find the first missing positive integer.
 
Example:
Given [1,2,0] return 3,
 
[3,4,-1,1] return 2,
 
[-8, -7, -6] returns 1
 
Your algorithm should run in O(n) time and use constant space.

*/
