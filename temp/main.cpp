///
///
///     "Every Code has a solution which is best, fast and wrong !" - Rule of OJ
///
///

#include <bits/stdc++.h>

using namespace std;

map <string,vector < pair <int,int> > > mp;
vector <string> vstr[105];

int main()
{
    int t,doc_id=0,line=0,i,n,m,j;
    string st,stt,stx;
    scanf("%d",&t);
    while(t--)
    {
        line=0;
        while(getline(cin,st))
        {
            if(st=="**********")
                break;
            vstr[doc_id].push_back(st);
            stringstream ss(st);
            while(ss>>stx)
            {
                transform(stx.begin(),stx.end(),stx.begin(),::tolower);
                mp[stx].push_back({doc_id,line});
            }
            line++;
        }
        doc_id++;
    }
    scanf("%d",&t);
    while(t--)
    {
        getline(cin,st);
        stringstream ss(st);
    }
    return 0;
}
/*

1


.46......

.3.1.....

.2..6..85

...87....

6...3...4

....14...

79..5..3.

.....2.4.

..2...61.

*/
