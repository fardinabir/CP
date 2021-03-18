#include <bits/stdc++.h>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

ll arr[1000000],n,m;
unordered_map <string,int> us;
int par[10000];
ll ans[10000];

int find_par(int node)
{
    return par[node]= par[node]==node? node : find_par(par[node]);
}

void join(int parr,int child)
{
    int a,b;
    a=find_par(child),b=find_par(parr);
    if(a!=b)
    {
        par[a]=b;
        ans[b]+=ans[a];
    }
}

int main()
{
    ll t,i,j,k,r,c,cc,mn,g,a,b,l=1,li,id=1;
    while(1)
    {
        cin>>n>>m;
        string st,s1,s2;
        if(n+m==0)
            return 0;
        for(i=0;i<n;i++)
        {
            cin>>st;
            us[st]=i;
            ans[i]=1;
            par[i]=i;
        }
        for(i=0;i<m;i++)
        {
            cin>>s1>>s2;
            join(us[s1],us[s2]);
        }
        mn=0;
        for(i=0;i<n;i++)
            mn=max(mn,ans[i]);
        cout<<mn<<endl;
    }
    return 0;
}
/*
5 2
caterpillar
bird
horse
elefant
herb
herb caterpillar
caterpillar bird

5 2
caterpillar
bird
horse
elefant
herb
herb caterpillar
caterpillar bird

0 0
*/
