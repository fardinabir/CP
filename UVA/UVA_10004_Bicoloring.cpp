#include <bits/stdc++.h>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

int arr[305];
int vis[305];
int lvlarr[305];
vector <int> G[300];

int dfs(int node,int lvl)
{
    if(vis[node])
    {
        if(lvlarr[node]!=lvl)
            return 0;
    }
    if(!vis[node])
    {
        vis[node]=1;
        lvlarr[node]=lvl;
        for(int i=0;i<G[node].size();i++)
        {
            if(!dfs(G[node][i],!lvl))
                return 0;
        }
    }
    return 1;
}

int main()
{
    ll t,i,j,k,n,l,m,r,c=0,d,p,e,u,v,q,cumsum,x,y,id=1,sz,a=0,b=0;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        cin>>l;
        for(i=0;i<l;i++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(dfs(0,0))
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";
        for(i=0;i<300;i++)
            G[i].clear();
        memset(vis,0,sizeof vis);
        memset(lvlarr,0,sizeof lvlarr);
    }
    return 0;
}
/*
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0
**/
