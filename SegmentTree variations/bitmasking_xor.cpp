#include <bits/stdc++.h>
#define mx 100005
#define ll long long int

using namespace std;

struct st
{
    int sum,lazy;
    st()
    {
        sum=lazy=0;
    }
};

int arr[mx+1];
st node[21][4*mx];

void build(int ind,int b,int e,int no)
{
    if(b==e)
    {
        int xx=arr[b]&(1 << no)? 1 : 0;
        node[no][ind].sum=xx;
        return;
    }
    int mid=(b+e)>>1;
    build(ind<<1,b,mid,no);
    build(ind<<1|1,mid+1,e,no);
    node[no][ind].sum=node[no][ind<<1].sum+node[no][ind<<1|1].sum;
}

void propagate(int ind,int b,int e,int mid,int no)
{
    if(node[no][ind].lazy)
    {
        node[no][ind].lazy=0;
        if(b!=e)
        {
            node[no][ind<<1].lazy^=1;
            node[no][ind<<1].sum=(mid-b+1)-node[no][ind<<1].sum;

            node[no][ind<<1|1].lazy^=1;
            node[no][ind<<1|1].sum=(e-mid)-node[no][ind<<1|1].sum;
        }
    }
}

void update(int ind,int b,int e,int l,int r,int no,int x)
{
    if(b>r || e<l)
        return;
    if(b>=l && e<=r)
    {
        node[no][ind].sum=(e-b+1)-node[no][ind].sum;
        node[no][ind].lazy^=1;
        return;
    }
    int mid=(b+e)>>1;
    propagate(ind,b,e,mid,no);
    update(ind<<1,b,mid,l,r,no,x);
    update(ind<<1|1,mid+1,e,l,r,no,x);
    node[no][ind].sum=node[no][ind<<1].sum+node[no][ind<<1|1].sum;
}

int query(int ind,int b,int e,int l,int r,int no)
{
    if(b>r || e<l)
        return 0;
    if(b>=l && e<=r)
        return node[no][ind].sum;
    int mid=(b+e)>>1;
    propagate(ind,b,e,mid,no);
    return query(ind<<1,b,mid,l,r,no) + query(ind<<1|1,mid+1,e,l,r,no);
}

int main()
{
    int i,j,k,l,m,n,r,e,t,id=1,x;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<20;i++)
        build(1,1,n,i);
    cin>>m;
    while(m--)
    {
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%d %d",&l,&r);
            ll sum=0;
            for(i=0;i<20;i++)
            {
                sum+=(query(1,1,n,l,r,i))*(1ll<<i);
            }
            printf("%I64d\n",sum);
        }
        else
        {
            scanf("%d %d %d",&l,&r,&x);
            for(i=0;i<20;i++)
            {
                if(x&1<<i)
                    update(1,1,n,l,r,i,x);
            }
        }
    }
}

/*
10

10 2 10 7 9 6 7 1 10 3

10

2 2 4 8

2 1 9 2

2 7 10 10

1 7 7

2 1 5 5

2 7 9 7

1 2 3

2 6 9 10

2 2 4 4

1 4 8



*/
