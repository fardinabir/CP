/// uva 417

#include <bits/stdc++.h>
#define mxs 100005
#define ll  long long int
#define print_case printf("Case %lld: ",ts++)
using namespace std;

ll arr[100005],n,m,cnt;

int main()
{
    ll t,k,a,b,d,x,y,i,q,j,l,s,c,ans,mx=-1,mn=INT_MAX,ts=1;
    string st="",stt;
    unordered_map <string,int> mps;
    queue <string> qs;
    c=1;
    for(i=0;i<26;i++)
    {
        string x(1,i+'a');
        qs.push(x);
        mps[x]=c++;
    }
    while(1)
    {
        st=qs.front();
        qs.pop();
        if(st.size()==5)break;
        for(i=st[st.size()-1]+1;i<='z';i++)
        {
            stt=st+string(1,i);
            qs.push(stt);
            mps[stt]=c++;
        }
    }
    while(cin>>st)
    {
        cout<<mps[st]<<endl;
    }
    return 0;
}
/*
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
*/
