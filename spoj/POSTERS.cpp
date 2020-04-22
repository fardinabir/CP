#include<bits/stdc++.h>
#define mx 10000000
using namespace std;

int node[4*mx+1],pos[mx+1],ans[mx+1];
unordered_set <int> sett;

void build()
{
    memset(node,-1,sizeof node);
}

void update(int ind,int i,int j,int s,int e,int val)
{
    if(i>e || j<s)
        return;
    if(i>=s && j<=e)
    {
        node[ind]=val;
        return;
    }
    int mid=(i+j)>>1;
    if(node[ind]!=-1)
        node[ind<<1]=node[ind<<1|1]=node[ind];
    node[ind]=-1;
    update(ind<<1,i,mid,s,e,val);
    update(ind<<1|1,mid+1,j,s,e,val);
    if(node[ind<<1]==node[ind<<1|1])
        node[ind]=node[ind<<1];
}

void query(int ind,int i,int j)
{
    if(node[ind]!=-1)
    {
        sett.insert(node[ind]);
        return;
    }
    if(i==j)
        return;
    int mid=(i+j)>>1;
    query(ind<<1,i,mid);
    query(ind<<1|1,mid+1,j);
}

int main()
{
    int i,j,a,b,k=0,l,c=0,t,n,id=1;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        build();
        c=n;
        while(c--)
        {
            scanf("%d %d",&a,&b);
            update(1,1,mx,a,b,k++);
        }
        query(1,1,mx);
        printf("%d\n",sett.size());
        memset(node,0,sizeof node);
        memset(pos,0,sizeof pos);
        sett.clear();
    }
    return 0;
}
