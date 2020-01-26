#include <bits/stdc++.h>
#define ll long long
#define mx 100000
using namespace std;

ll arr[mx+5],tx;
vector <ll> node[4*mx+5];

void build(int ind,int i,int j)
{
    if(i==j)
    {
        scanf("%lld",&arr[i]);
        node[ind].push_back(arr[i]);
        return;
    }

    int mid=(i+j)>>1;

    build(ind<<1,i,mid);
    build(ind<<1|1,mid+1,j);

    merge(node[2*ind].begin(),node[2*ind].end(),node[2*ind+1].begin(),node[2*ind+1].end(),back_inserter(node[ind]));
}

int query(int ind,int i,int j,int s,int e,int k)
{
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {
        int x=node[ind].end()-upper_bound(node[ind].begin(),node[ind].end(),k);
        return x;
    }

    int mid=(i+j)>>1;

    return query(2*ind,i,mid,s,e,k) + query(2*ind+1,mid+1,j,s,e,k);
}

int main()
{
    ll i,j,k,l,n,m,x,y,c,cc,t;
    cin>>n;
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        scanf("%lld %lld %lld",&x,&y,&k);
        printf("%d\n",query(1,1,n,x,y,k));
    }
    return 0;
}
