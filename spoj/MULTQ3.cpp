#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct NODE
{
    int one,two,three,zero,cnt;
    NODE()
    {
        one=0;
        two=0;
        three=1;
        cnt=0;
    }
}node[400005];

int arr[100005];
int cc=0;

void init(ll n,ll i,ll j)
{
    cc++;
    //cout<<i<<"-"<<j<<endl;
    if(i==j)
    {
        node[n].one=0;
        node[n].two=0;
        node[n].three=1;
        return;
    }
    ll mid=(i+j)/2;
    init(2*n,i,mid);
    init(2*n+1,mid+1,j);
    node[n].three=node[2*n].three+node[2*n+1].three;
}

void update(ll n,ll i,ll j,ll s,ll e)
{
    if(e<i || s>j)
        return;
    if(i>=s && j<=e)
    {
        int x=node[n].three;
        node[n].three=node[n].two;
        node[n].two=node[n].one;
        node[n].one=x;
        node[n].cnt++;
        //cout<<i<<" -- "<<j<<" "<<node[n].one<<" "<<node[n].two<<" "<<node[n].three<<" "<<endl;
        return;
    }
    ll mid=(i+j)/2;
    update(2*n,i,mid,s,e);
    update(2*n+1,mid+1,j,s,e);
    node[n].one=node[2*n].one+node[2*n+1].one;
    node[n].two=node[2*n].two+node[2*n+1].two;
    node[n].three=node[2*n].three+node[2*n+1].three;
    int xx=node[n].cnt%3;
    while(xx--)
    {
        int x=node[n].three;
        node[n].three=node[n].two;
        node[n].two=node[n].one;
        node[n].one=x;
    }
    //cout<<i<<" -- "<<j<<" "<<node[n].one<<" "<<node[n].two<<" "<<node[n].three<<" "<<endl;
}


int query(ll n,ll i,ll j,ll s,ll e,ll carr=0)
{
    if(s>j || e<i)
        return 0;
    if(s<=i && e>=j)
    {
        if(carr%3==0)
        {
            return node[n].three;
        }
        if(carr%3==1)
            return node[n].two;
        if(carr%3==2)
            return node[n].one;
    }
    ll mid=(i+j)/2;
    ll l=query(2*n,i,mid,s,e,carr+node[n].cnt);
    ll r=query(2*n+1,mid+1,j,s,e,carr+node[n].cnt);
    return l+r;
}

int main() {
    ll i,j,k,l,m,n,t=1,c=1,x,y,z;
    while(c<=t)
    {
        scanf("%lld %lld",&n,&k);
        init(1,1,n);
        for(i=0;i<k;i++)
        {
            scanf("%lld %lld %lld",&x,&y,&z);
            if(x==0)
            {
                update(1,1,n,++y,++z);
            }
            else
            {
                printf("%d\n",query(1,1,n,++y,++z));
            }
        }
        c++;
    }
    return 0;
}
