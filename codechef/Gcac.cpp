#include "string.h"
#include "iostream"
#include "algorithm"
#define FOR(i,begin,end) for(i=begin;i<end;i++)
#define dontsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    dontsync()
    long long t,n,m,i,j,k,maxc,cnt,maxm,amt;
    cin >> t;
    FOR(i,0,t)
	{
        cin >> n >> m;
        char qual[m+5];
        long long minSalary[n], offeredSalary[m], maxJobOffers[m], company[m];
        amt=cnt=0;
        FOR(j,0,n)
        {
            cin >> minSalary[j];
        }
        FOR(j,0,m)
        {
            cin >> offeredSalary[j] >> maxJobOffers[j];
            company[j]=0;
        }
        FOR(j,0,n)
        {
            cin >> qual;
            maxc=-1;
            maxm=0;
            FOR(k,0,strlen(qual))
            {
                if(qual[k]=='1')
                {
                    if(minSalary[j]<=offeredSalary[k] && maxJobOffers[k]>0 && maxm<offeredSalary[k])
                    {
                        maxm=offeredSalary[k];
                        maxc=k;
                    }
                }
            }
            if(maxc!=-1)
            {
                cnt++;
                amt+=maxm;
                company[maxc]=1;
                maxJobOffers[maxc]--;
            }
        }
        cout << cnt << " " << amt << " " << count(company,company+m,0) << "\n";
	}
    return 0;
}


/*

The placements/recruitment season is going on in various colleges. The interviews are over, and each company has selected some students. But since each student can end up finally in
at most one company, a student might have to reject a company which selected him. The companies know this, and hence, the companies usually select more students than it can
actually employ. So now, the exact pairings should be done. We talk about one such session in a famous college.

There are a total of N candidates (numbered from 1 to N) and M companies (numbered from 1 to M) taking part in it. Each candidate has a certain minimum expectation of salary, which
is given by the array minSalary (All the arrays are 1-indexed). For each candidate, you are also given the information regarding the companies which have selected him. This
information is given by an array qual of size N * M, where qual[i][j] = 1 if and only if the i-th candidate has qualified for a job in the j-th company. A company will provide a
fixed salary to the candidates it employs, which is given by the array offeredSalary. Also, a company has an upper bound on the number of candidates it can employ and finally
give an offer to. This information is provided by array maxJobOffers.

The D-day has come. Each candidate from 1, 2, .. N (in this order) will go to the placements coordinator. When the i-th student goes, among the companies which have selected him, and
which still haven't reached their maxJobOffers limit, he picks the company which provides the maximum offeredSalary, provided that it is at least his minSalary.

You have to find the number of the candidates that will end up with a job, the total amount of salaries that the candidates will get, and the number of companies that won't be able
to employ even a single candidate. This information is very crucial for the placement coordinator, so as to analyze whether it makes sense to invite a company to come to the
placements session next year or not. Please help the coordinator!

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows
First line of each test case contains two space separated integer N, M.
The next line contains N space separated integers denoting the array minSalary.
Each of the next M lines contains two space separated integers denoting offeredSalary[i] and maxJobOffers[i].
The next N lines will contain the description of the 2-D array qual. Each of the N lines will contain M binary integers (without any space): j-th integer in the i-th line will denote
qual[i][j].

Output
For each test case, output three integers in a new line, denoting the number of the candidates that will get a job, the total amount of salaries that the candidates will get, and the
number of companies that won't be able to hire even a single candidate.

Constraints
1 ≤ T ≤ 10
1 ≤ N, M ≤ 10^3
0 ≤ minSalary[i] ≤ 10^9
0 ≤ qual[i][j] ≤ 1
1 ≤ offeredSalary[i] ≤ 10^9
1 ≤ maxJobOffers[i] ≤ 10^6
All elements of the array offeredSalary are distinct

Subtasks
Subtask 1 (30 points): 1 ≤ N, M ≤ 200
Subtask 2 (70 points): Original Constraints

Example
Input:
1
5 6
5000 10000 3000 20 100
10000 2
800 2
600 1
10 8
1000 9
2000 10
111111
100000
000000
000001
100100

Output:
3 22000 4

Explanation
There are 5 candidates and 6 companies.

The first candidate wants a job that pays at least 5000 Rs. He has qualified in all the companies, so he will choose the 1st company that provides him the maximum money, 10000 Rs.

The second candidate will get a job offer of 10000 Rs from 1st company.

The third candidate has not qualified in any company, so he won't get any job.

The fourth candidate has qualified only in 6-th company which provides a salary of 2000 Rs which is greater than or equal to 20, the minimum salary expected by the fourth candidate.

The fifth candidate wants minimum salary 100 Rs. He has qualified in company 1st and 4th. The 1st company won't hire him as it has already filled the quota of hiring two people. 4th
company is providing the candidate less than 100 Rs, so he won't join that too.

So, overall there are three candidates that got the job (first, second and fourth). Total amount of salary is 10000 + 10000 + 2000 = 22000. Only first and 6-th companies are able to
select some candidates, so there are 4 companies that are not able to hire any candidate. Hence, the answer will be 3 22000 4.

*/
