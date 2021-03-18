#include <bits/stdc++.h>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

ll arr[1000000],n,m;
vector <int> adj[101];
bool vis[101];
vector <int> ans;

void dfs(int node)
{
    if(!vis[node])
    {
        vis[node]=true;
        for(int i=0;i<adj[node].size();i++)
            dfs(adj[node][i]);
        ans.push_back(node);
    }

}

int main()
{
    ll t,i,j,k,r,c,cc,mn,g,a,b,l=1,li,id=1;
    while(1)
    {
        cin>>n>>m;
        if(n+m==0)
            return 0;
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
        }
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
                dfs(i);
        }
        reverse(ans.begin(),ans.end());
        cout<<ans[0];
        for(i=1;i<n;i++)
            cout<<" "<<ans[i];
        cout<<endl;

        for(i=0;i<101;i++)
            adj[i].clear();
        memset(vis,false,sizeof vis);
        ans.clear();
    }
    return 0;
}
/*
5 4
1 2
2 3
1 3
1 5

5 4
1 2
2 3
1 3
1 5

11 10
3 8
3 9
3 2
3 4
9 10
9 11
2 1
2 5
5 7
5 6
0 0
*/
