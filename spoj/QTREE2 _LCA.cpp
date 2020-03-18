#include<bits/stdc++.h>
#define ll unsigned long long int
#define mx 10005

using namespace std;

vector <pair<int,int> > G[mx];
ll cost[mx];
int level[mx],parent[mx],v;
int sparse_table[30][mx],vis[mx];

void dfs(int val,int from)
{
    parent[val]=from;
    vis[val]=1;

    for(int i=0;i<G[val].size();i++)
    {
        v=G[val][i].first;
        if(v!=val && !vis[v])
        {
            level[v]=level[val]+1;
            cost[v]=cost[val]+G[val][i].second;
            dfs(v,val);
        }
    }
    return ;
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

int find_kth(int node,int k)
{
    int lg=0,j=k;
    while(j)
    {
        lg++;
        j/=2;
    }
    for(int i=lg;i>=0;i--)
    {
        if(k>=(1<<i))
        {
            k-=(1<<i);
            node=find_par(node,i);
        }
    }
    return node;
}

int main()
{
    int a,b,c,i,n,j,k,t,l,m,id=1,xx,yy;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    string st;
    cin>>t;
    while(t--)
    {
        memset(sparse_table,-1,sizeof sparse_table);
        cin>>n;
        for(i=1;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&l);
            G[a].push_back({b,l});
            G[b].push_back({a,l});
        }
        parent[1]=1;

        dfs(1,1);

        while(1)
        {
            cin>>st;
            if(st=="DONE")
                break;
            else if(st=="DIST")
            {
                cin>>a>>b;
                c=lca_find(a,b);
                printf("%lld\n",cost[a]+cost[b]-2*cost[c]);
            }
            else if(st=="KTH")
            {
                cin>>a>>b>>k;
                k--;
                c=lca_find(a,b);
                if(level[a]-k<level[c])
                {
                    xx=level[b]-level[c]-(level[c]-(level[a]-k));
                    cout<<find_kth(b,xx)<<endl;
                }
                else
                {
                    cout<<find_kth(a,k)<<endl;
                }
            }
        }
        for(i=0;i<mx;i++)
            G[i].clear();
        memset(vis,0,sizeof vis);
        memset(level,0,sizeof level);
        memset(cost,0,sizeof level);
        memset(parent,0,sizeof level);
        cout<<"\n";
    }


    return 0;
}
