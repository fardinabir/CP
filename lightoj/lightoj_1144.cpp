#include <bits/stdc++.h>
#define ll  long long int
#define mx 1000000

using namespace std;

ll nm[mx+5],cnt[mx+5];

void mobius()
{
    ll i,j,k,l;
    for(i=2;i<=mx;i++)
    {
        if(nm[i]==0)
        {
            for(j=i;j<=mx;j+=i)
            {
                nm[j]= nm[j]==0? i : (nm[j]*i);
                cnt[j]++;
            }
        }
    }
    for(i=2;i<=mx;i++)
    {
        if(i!=nm[i])
            cnt[i]=0;
        else if(cnt[i]%2)
            cnt[i]=-1;
        else
            cnt[i]=1;
    }
}

int main()
{
    ll i,j,k,d,n,idd=0,m,ans,t;
    cin>>t;
    mobius();
    while(t--)
    {
        cin>>n>>m;
        if(n>m)
            swap(n,m);

        ans=n*m;
        for(i=2;i<=n;i++)
        {
           ans+=cnt[i]*(n/i)*(m/i);
        }
        if(n) ans++;
        if(m) ans++;
        printf("Case %lld: %lld\n",++idd,ans);
    }
    return 0;
}
