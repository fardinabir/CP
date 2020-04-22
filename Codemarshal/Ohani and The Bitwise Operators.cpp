/// https://algo.codemarshal.org/contests/baps-sel-16/problems/G

#include <bits/stdc++.h>
#define mx 100005
#define ll long long int

using namespace std;

struct st
{
    int cnt,lazy;
    st()
    {
        cnt=lazy=0;
    }
};

int arr[mx+1];
st node[4][4*mx];

void build(int ind,int b,int e,int no)
{
    if(b==e)
    {
        int xx=arr[b]&(1 << no)? 1 : 0;
        node[no][ind].cnt=xx;
        return;
    }
    int mid=(b+e)>>1;
    build(ind<<1,b,mid,no);
    build(ind<<1|1,mid+1,e,no);
    node[no][ind].cnt=node[no][ind<<1].cnt+node[no][ind<<1|1].cnt;
}

void propagate(int ind,int b,int e,int mid,int no)
{
    if(node[no][ind].lazy)
    {
        node[no][ind].lazy=0;
        if(b!=e)
        {
            node[no][ind<<1].lazy^=1;
            node[no][ind<<1].cnt=(mid-b+1)-node[no][ind<<1].cnt;

            node[no][ind<<1|1].lazy^=1;
            node[no][ind<<1|1].cnt=(e-mid)-node[no][ind<<1|1].cnt;
        }
    }
}

void update(int ind,int b,int e,int l,int r,int no,int x)
{
    if(b>r || e<l)
        return;
    if(b>=l && e<=r)
    {
        node[no][ind].cnt=(e-b+1)-node[no][ind].cnt;
        node[no][ind].lazy^=1;
        return;
    }
    int mid=(b+e)>>1;
    propagate(ind,b,e,mid,no);
    update(ind<<1,b,mid,l,r,no,x);
    update(ind<<1|1,mid+1,e,l,r,no,x);
    node[no][ind].cnt=node[no][ind<<1].cnt+node[no][ind<<1|1].cnt;
}

int query(int ind,int b,int e,int l,int r,int no)
{
    if(b>r || e<l)
        return 0;
    if(b>=l && e<=r)
        return node[no][ind].cnt;
    int mid=(b+e)>>1;
    propagate(ind,b,e,mid,no);
    return query(ind<<1,b,mid,l,r,no) + query(ind<<1|1,mid+1,e,l,r,no);
}

int main()
{
    int i,j,k,l,m,n,r,e,t,id=1,x,y;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",id++);
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<3;i++)
            build(1,1,n,i);
        while(m--)
        {
            scanf("%d",&k);
            if(k==2)
            {
                scanf("%d %d",&l,&r);
                ll tq=0,tand=0,tor=0,txor=0;
                for(i=0;i<3;i++)
                {
                    tq=0;
                    tq=query(1,1,n,l,r,i);
                    if(tq==(r-l+1))
                        tand|=1<<i;
                    if(tq)
                        tor|=1<<i;
                    if(tq&1)
                        txor|=1<<i;
                }
                printf("%lld %lld %lld\n",tand,tor,txor);
            }
            else
            {
                scanf("%d %d %d",&l,&r,&x);
                for(i=0;i<3;i++)
                {
                    if(x&1<<i)
                        update(1,1,n,l,r,i,x);
                }
            }
        }
        memset(node,0,sizeof node);
    }
}

/*
2
5 5
1 2 3 4 5
2 1 2
2 1 3
1 2 2 3
2 3 5
2 1 5

5 5
1 2 3 4 5
2 1 2
2 1 3
1 2 2 3
2 3 5
2 1 5



*/
