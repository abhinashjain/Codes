int* plusOne(int* A, int n1, int *length_of_array)
{
    int i,tmp,inc=1;
    for(i=n1-1;i>=0;i--)
    {
        if(A[i]==9 && inc==1)
        {
            A[i]=0;
        }
        else
        {
            A[i]+=inc;
            inc=0;
        }
    }
    int* result;
    if(inc)
    {
        *length_of_array=(n1+1);
        result=(int *)malloc(*length_of_array * sizeof(int));
        result[0]=inc;
        for(i=1;i<=n1;i++)
        {
            result[i]=A[i-1];
        }
    }
    else
    {
        for(i=0;i<n1;i++)
        {
            if(A[i]>0)
            {
                tmp=i;
                break;
            }
        }
        *length_of_array=n1-tmp;
        result=(int *)malloc(*length_of_array * sizeof(int));
        for(i=tmp;i<n1;i++)
        {
            result[i-tmp]=A[i];
        }
    }
    return result;
}


/*
 
Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.
 
Example:
If the vector has [1, 2, 3]
the returned vector should be [1, 2, 4]
as 123 + 1 = 124.
 
NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
 
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
 
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.
 
*/
