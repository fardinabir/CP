#include <bits/stdc++.h>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

ll arr[1000000],n,m;
map <string,int> us;
int par[200001];
ll ans[200001];

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
    cout<<ans[b]<<endl;
}

int main()
{
    ll t,i,j,k,r,c,cc,mn,g,a,b,l=1,li,id=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string st,s1,s2;
        if(n+m==0)
            return 0;
        c=0;
        for(i=0;i<=2*n;i++)
        {
            ans[i]=1;
            par[i]=i;
        }
        for(i=0;i<n;i++)
        {
            cin>>s1>>s2;
            if(us.find(s1)==us.end())
                us[s1]=++c;
            if(us.find(s2)==us.end())
                us[s2]=++c;

            join(us[s1],us[s2]);
        }
        us.clear();
    }
    return 0;
}
/*
2
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Barney Betty
Betty Wilma
*/
