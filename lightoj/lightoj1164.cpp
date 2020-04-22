#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct NODE
{
    ll pop,sum;
}node[400005];

ll arr[100005];
int cc=0;

void init(ll n,ll i,ll j)
{

    if(i==j)
    {
        node[n].sum=arr[i];
        node[n].pop=0;
        return;
    }
    ll mid=(i+j)/2;
    init(2*n,i,mid);
    init(2*n+1,mid+1,j);
    node[n].sum=node[2*n].sum+node[2*n+1].sum;
    node[n].pop=0;
}

void update(ll n,ll i,ll j,ll s,ll e,ll val)
{

    if(i>e || j<s)
        return;
    if(i>=s && j<=e)
    {
        node[n].sum+=(val*(j-i+1));
        node[n].pop+=val;
        return;
    }
    ll mid,l,r;
    mid=(i+j)/2;
    update(2*n,i,mid,s,e,val);
    update(2*n+1,mid+1,j,s,e,val);

    l=node[2*n].sum;
    r=node[2*n+1].sum;
    node[n].sum=l+r+(node[n].pop*(j-i+1));
}

ll query(ll n,ll i,ll j,ll s,ll e,ll carr=0)
{

    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {
        return node[n].sum+(j-i+1)*carr;
    }
    ll mid,l,r;
    mid=(i+j)/2;
    l=query(2*n,i,mid,s,e,carr+node[n].pop);
    r=query(2*n+1,mid+1,j,s,e,carr+node[n].pop);
    return l+r;
}

int main() {
    ll i,j,k,l,m,n,s,e,v,key,x,t,c=1;
    cin>>t;
    while(c<=t)
    {
        printf("Case %lld:\n",c++);
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
        {
            arr[i]=0;
        }
        init(1,1,n);
        while(m--)
        {
            scanf("%lld",&key);
            if(key==0)
            {
                scanf("%lld %lld %lld",&s,&e,&v);
                update(1,1,n,s+1,e+1,v);
            }
            else if(key==1)
            {
                scanf("%lld %lld",&s,&e);
                printf("%lld\n",query(1,1,n,s+1,e+1));
            }
        }
    }
    return 0;
}
