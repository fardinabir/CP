#include<bits/stdc++.h>
#define mx 100005
using namespace std;

int arr[mx+1],node[4*mx+1],pos[mx+1],ans[mx+1];

void build(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind]=1;
        return;
    }
    int mid=(i+j)>>1;
    build(ind<<1,i,mid);
    build(ind<<1|1,mid+1,j);
    node[ind]=node[ind<<1]+node[ind<<1|1];
}

int query(int ind,int i,int j,int kth)
{
    if(i==j && kth==1)
    {
        node[ind]=0;
        return i;
    }

    int mid=(i+j)>>1,ret;

    if(node[ind<<1|1]<kth)
        ret=query(ind<<1,i,mid,kth-node[ind<<1|1]);
    else
        ret=query(ind<<1|1,mid+1,j,kth);
    node[ind]=node[ind<<1]+node[ind<<1|1];
    return ret;
}

int main()
{
    int i,j,k,l,c=0,t,n,id=1;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        build(1,1,n);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        for(i=n;i>0;i--)
        {
            k=query(1,1,n,arr[i]+1);
            pos[k]=i;
        }
        for(i=1;i<=n;i++)
            ans[pos[i]]=i;
        printf("Case %d: %d\n",id++,ans[1]);
        memset(node,0,sizeof node);
        memset(pos,0,sizeof pos);
    }
    return 0;
}
