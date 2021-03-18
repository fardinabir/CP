#include <bits/stdc++.h>
#define mxs 100005
#define ll  long long int
using namespace std;

int arr[100005],n,m;
ll node[100005];
pair <int,int> pi[100005];

ll query(int ind)
{
    ll mx=0;
    for(int i=ind;i>0;i-=(i&-i))
        mx=max(mx,node[i]);
    return mx;
}

void update(int ind,ll cnt)
{
    for(int i=ind;i<100005;i+=(i&-i))
        node[i]=max(node[i],cnt);
}

int main()
{
    ll t,k,a,b,i,q,j,l,s,c,mx=-1,mn=INT_MAX,ts=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>k;
        pi[i]={k,-i};
    }
    sort(pi+1,pi+n+1);
    for(i=1;i<=n;i++)
    {
        s=query(-pi[i].second-1);
        s+=pi[i].first;
        update(-pi[i].second,s);
    }
    cout<<query(mxs-1)<<endl;
    return 0;
}
/*
6
33 77 45 51 32 79
*/
