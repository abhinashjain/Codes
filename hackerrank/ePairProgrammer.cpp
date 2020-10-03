#include "iostream"
#include "map"
#include "vector"
#include "algorithm"
using namespace std;

int match_making(vector < string > match1, vector < string > match2)
{
    int i,j,min,val,len=match1.size();
    vector<string>::iterator iter;
    map<string,vector<string> > back;
    map<string,vector<string> >::iterator mapit;
    map<string,int> front;

    for(i=0;i<len;i++)
    {
        mapit = back.find(match1[i]);
        if(mapit == back.end())
            back.insert(make_pair(match1[i],vector<string>()));
        back[match1[i]].push_back(match2[i]);
    }
    
    for(iter=match2.begin();iter!=match2.end();iter++)
    {
        if(front.find((*iter)) != front.end())
            front[(*iter)]++;
        else
            front.insert(make_pair((*iter),1));
    }

    i=j=0;
    len=back.size();
    do
    {
        i++;
        string str;
        min=10000000;
        
        vector<pair<int,string> > tmp;
        vector<pair<int,string> >::iterator tmpiter;
        for(mapit=back.begin();mapit!=back.end();mapit++)
        {
            tmp.push_back(make_pair((mapit->second).size(),mapit->first));
        }
        sort(tmp.begin(),tmp.end());
        
        tmpiter=tmp.begin();
        mapit = back.find((*tmpiter).second);
        for(iter=(mapit->second).begin();iter!=(mapit->second).end();iter++)
        {
            val=front[(*iter)];
            if(val!=0 && val<=min)
            {
                min=val;
                str=(*iter);
            }
        }
        back.erase(mapit);
        
        if(min!=10000000)
        {
            front[str]=0;
            j++;
            for(mapit=back.begin();mapit!=back.end();mapit++)
            {
                for(iter=(mapit->second).begin();iter!=(mapit->second).end();iter++)
                {
                    if((*iter).compare(str)==0)
                    {
                        (mapit->second).erase(iter);
                        break;
                    }
                }
            }
        }
    } while(i<len);
    return j;
}

int main()
{
    int res, _matches1_size = 0;
    cin >> _matches1_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> _matches1;
    string _matches1_item;
    for(int _matches1_i=0; _matches1_i<_matches1_size; _matches1_i++)
    {
        getline(cin, _matches1_item);
        _matches1.push_back(_matches1_item);
    }
    
    
    int _matches2_size = 0;
    cin >> _matches2_size;
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    vector<string> _matches2;
    string _matches2_item;
    for(int _matches2_i=0; _matches2_i<_matches2_size; _matches2_i++)
    {
        getline(cin, _matches2_item);
        _matches2.push_back(_matches2_item);
    }
    
    res = match_making(_matches1, _matches2);
    cout << res << "\n";
    
    return 0;
}


/*

Input #1:
2
Jordan
Chris
2
Sandy
Pat

Output #1:
2

Input #2:
3
Jordan
Jordan
Jordan
3
Sandy
Chris
Pat

Output #2:
1

Input #3:
3
Jordan
Jordan
Chris
3
Sandy
Pat
Sandy

Output #3:
2

*/
