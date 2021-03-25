/// uva 417

#include <bits/stdc++.h>
#define mxs 100005
#define ll  long long int
#define print_case printf("Case %lld: ",ts++)
using namespace std;

ll arr[100005],n,m,cnt;

int main()
{
    int t,k,a,b,d,x,y,i,q,j,l,s,c,ans,mx=-1,mn=INT_MAX,ts=1;
    string st="",stt;
    map<vector<int>,int> mp;
    vector<int> vc;
    while(cin>>n,n)
    {
        while(n--)
        {
            for(i=0;i<5;i++)
            {
                cin>>x;
                vc.push_back(x);
            }
            sort(vc.begin(),vc.end());
            mp[vc]++;
            vc.clear();
        }
        mx=-1,c=0;
        map <vector<int>,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++)
            mx=max(mx,it->second);
        for(it=mp.begin();it!=mp.end();it++)
            c+=mx==it->second?1:0;
        cout<<mx*c<<endl;
        mp.clear();
    }
    return 0;
}
/*
3
100 101 102 103 488
100 200 300 101 102
103 102 101 488 100
3
200 202 204 206 208
123 234 345 456 321
100 200 300 400 444
0
*/
