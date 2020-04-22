#include <bits/stdc++.h>
#define mx 200000
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

int arr[mx],a[mx],b[mx],n,m;
vector <int> tree[4*mx];

void build(int ind,int b,int e)
{
    if(b==e)
    {
        tree[ind].push_back(a[b]);
        return;
    }
    int mid=(b+e)>>1;
    build(ind<<1,b,mid);
    build(ind<<1|1,mid+1,e);
    merge(tree[ind<<1].begin(),tree[ind<<1].end(),tree[ind<<1|1].begin(),tree[ind<<1|1].end(),back_inserter(tree[ind]));
}

int query(int ind,int b,int e,int l,int r,int k)
{
    if(b>r || e<l)
        return 0;
    if(b>=l && e<=r)
    {
        int x= lower_bound(tree[ind].begin(),tree[ind].end(),k)-tree[ind].begin();
        return x;
    }
    int mid=(b+e)>>1;
    return query(ind<<1,b,mid,l,r,k)+query(ind<<1|1,mid+1,e,l,r,k);
}

int main()
{
    ll t,i,j,k,l,r,c=0,s,d,p,e,u,v,q,sum,id=1,x,y,sz;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&u);
        a[i]=u-a[i];
    }
    build(1,1,n);
    for(i=1;i<=n;i++)
    {
        c+=query(1,1,n,i+1,n,-a[i]);
    }
    cout<<c<<endl;
    return 0;
}

/*

2

5 3

10 2 3 12 7

0 2

0 4

2 4

2 1

1 2

0 1

**/

