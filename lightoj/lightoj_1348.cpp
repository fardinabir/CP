#include <bits/stdc++.h>
#define mx 30005
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

int gin[mx+1],t,par[mx+1],level[mx+1],start[mx+1],endd[mx+1];
int sparse_table[21][mx+1],n;
ll tree[2*mx+5];
vector <int> g[mx+1];

void dfs(int from,int node,int lvl)
{
    start[node]=++t;
    par[node]=from;
    level[node]=lvl;
    for(int i=0;i<g[node].size();i++)
    {
        if(g[node][i]!=from)
            dfs(node,g[node][i],lvl+1);
    }
    endd[node]=++t;
}

int find_par(int p,int pw)
{
    if(pw==0)
        return par[p];
    if(sparse_table[pw][p]!=-1)
        return sparse_table[pw][p];
    int x=find_par(p,pw-1);
    return sparse_table[pw][p]=find_par(x,pw-1);
}

int lca_find(int p,int q)
{
    if(level[p]<level[q])
        swap(p,q);
    for(int i=20;i>=0;i--)
    {
        if(level[p]-(1<<i)>=level[q])
            p=find_par(p,i);
    }
    if(p==q)
        return q;
    for(int i=20;i>=0;i--)
    {
        if(find_par(p,i)!=find_par(q,i))
            p=find_par(p,i),q=find_par(q,i);
    }
    return par[p];
}

void update(int idx,ll val)
{
    while (idx <= 2*n) {
        tree[idx] = (tree[idx]+val);
        idx += (idx & -idx);
    }
}

ll query(int idx)
{
    ll sum = 0;
    while (idx > 0) {
        sum = (sum + tree[idx]) ;
        idx -= (idx & -idx);
    }
    return sum;
}

void clear_all()
{
    memset(sparse_table,-1,sizeof sparse_table);
    memset(tree,0,sizeof tree);
    for(int i=1;i<=n;i++)
        g[i].clear();
    t=0;
}

int main()
{
    int t,i,j,k,l,a,b,c=0,p,d=0,e,u,v,q,sum,id=1,x,y;
    scanf("%d",&t);
    while(t--)
    {
        clear_all();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&gin[i]);
        for(i=0;i<n-1;i++)
        {
            scanf("%d %d",&u,&v);
            u++,v++;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,1,1);
        for(i=1;i<=n;i++)
        {
            update(start[i],gin[i]);
            update(endd[i],-gin[i]);
        }
        scanf("%d", &q);
        test_case;
        while(q--)
        {
            scanf("%d",&k);
            if(k==0)
            {
                ll dis;
                scanf("%d %d",&u,&v);
                u++,v++;
                p=lca_find(u,v);
                dis=query(start[u])+query(start[v]);
                dis=dis-(2*query(start[p]))+gin[p];
                printf("%lld\n",dis);
            }
            else
            {
                ll tv;
                scanf("%d %d",&u,&v);
                u++;
                update(start[u],-gin[u]);
                update(endd[u],gin[u]);
                update(start[u],v);
                update(endd[u],-v);
                gin[u]=v;
            }
        }
    }
    return 0;
}

/*
2



4

10 20 30 40

0 1

1 2

1 3

3

0 2 3

1 1 100

0 2 3

4

10 20 30 40

0 1

1 2

1 3

3

0 2 3

1 1 100

0 2 3

*/
