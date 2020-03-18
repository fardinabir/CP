#include<bits/stdc++.h>
#define ll unsigned long long int
#define mx 10005

using namespace std;

vector <int> G[mx];
int level[mx],parent[mx];
int sparse_table[30][mx];

void dfs(int val,int from,int lvl)
{
    level[val]=lvl;
    parent[val]=from;

    for(int i=0;i<G[val].size();i++)
    {
        if(G[val][i]!=val)
            dfs(G[val][i],val,lvl+1);
    }
}

int find_par(int p,int pw)
{
    if(pw==0)
        return sparse_table[pw][p]=parent[p];
    if(sparse_table[pw][p]!=-1)
        return sparse_table[pw][p];

    int x;
    x=find_par(p,pw-1);
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
        return p;

    for(int i=20;i>=0;i--)
    {
        if(find_par(p,i)!=find_par(q,i))
            p=find_par(p,i),q=find_par(q,i);
    }
    return parent[p];
}

int main()
{
    G[0].push_back(1);
    G[1].push_back(2);
    G[1].push_back(8);
    G[2].push_back(3);
    G[3].push_back(4);
    G[4].push_back(5);
    G[5].push_back(6);
    G[6].push_back(14);
    G[6].push_back(7);
    G[8].push_back(9);
    G[9].push_back(10);
    G[10].push_back(11);
    G[11].push_back(12);
    G[11].push_back(15);
    G[12].push_back(13);
    G[12].push_back(16);

    memset(sparse_table,-1,sizeof sparse_table);

    dfs(0,0,0);
    cout<<lca_find(13,7);
    return 0;
}
