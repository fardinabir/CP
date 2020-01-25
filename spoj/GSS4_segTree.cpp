#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL node[400005];

void push_up(int ind)
{
    if(node[ind<<1]==node[ind<<1|1])
        node[ind]=node[ind<<1];
    else
        node[ind]=-1;
}

void push_down(int ind)
{
    if(node[ind]!=-1)
    {
        node[ind<<1]=node[ind<<1|1]=node[ind];
        node[ind]=-1;
    }
}
void build(int ind,int i,int j)
{
    if(i==j)
    {
        scanf("%lld",&node[ind]);
        return;
    }
    int mid=(i+j)>>1;

    build(ind<<1,i,mid);
    build(ind<<1|1,mid+1,j);

    push_up(ind);
}

LL query(int ind,int i,int j,int s,int e)
{
    if(node[ind]!=-1)
        return node[ind]*(e-s+1);
    if(i>=s && j<=e)
    {
        if(node[ind]!=-1)
            return node[ind]*(j-i+1);
    }
    int mid=(i+j)>>1;
    push_down(ind);

    if(e<=mid)
        return query(ind<<1,i,mid,s,e);
    else if(s>mid)
        return query(ind<<1|1,mid+1,j,s,e);
    return query(ind<<1,i,mid,s,mid) + query(ind<<1|1,mid+1,j,mid+1,e);
}

void update(int ind,int i,int j,int s,int e)
{
    if(i>=s && j<=e)
    {
        if(node[ind]!=-1)
        {
            node[ind]=(LL)sqrt(node[ind]*1.0);
            //cout<<i<<" "<<j<<"   "<<node[ind]<<endl;
            return;
        }
    }
    int mid=(i+j)>>1;
    push_down(ind);

    if(s<=mid)
        update(ind<<1,i,mid,s,e);
    if(e>mid)
        update(ind<<1|1,mid+1,j,s,e);

    push_up(ind);

    //cout<<i<<" "<<j<<"   "<<node[ind]<<endl;
}

int main()
{
    int i,j,k,a,b,c,cnt=0,id=1,l,n,t,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        build(1,1,n);

        scanf("%d",&t);
        printf("Case #%d:\n",id++);
        while(t--)
        {
            scanf("%d %d %d",&k,&x,&y);
            if(x>y)
                swap(x,y);
            if(k)
            {
                printf("%lld\n",query(1,1,n,x,y));
            }
            else
                update(1,1,n,x,y);
        }
        printf("\n");
    }

    return 0;
}
