#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll>prime;

ll sz=1000005;
bool chk[1000005];

void seive()
{
    ll i,j,k;
    prime.push_back(2);
    for(i=3;i*i<=sz;i+=2)
    {
        if(!chk[i])
        {
            for(j=i*i;j<=sz;j+=(2*i))
                chk[j]=1;
        }
    }
    for(i=3;i<sz;i+=2)
        if(!chk[i]) prime.push_back(i);
}

int main ()
{
    ll tc,idd=0,b,n,temp,r,i,p,q,c,ans;
    //seive();
    //cout<<prime[prime.size()-1]<<endl;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&n);
        printf("Case %lld: ",++idd);
        ans=0;
        ll lo=1,hi=5000000000,mid;

        while(lo<hi)
        {
            mid=(lo+hi)/2;

            ll cnt=0,tmp=mid;
            while(tmp/5)
            {
                cnt+=tmp/5;
                tmp/=5;
            }
            if(cnt==n)
                ans=mid,hi=hi-1;
            if(cnt<n)
                lo=mid+1;
            else if(cnt>n)
                hi=mid-1;
        }
        if(ans)
            printf("%lld\n",ans);
        else
            printf("impossible\n");
    }
    return 0;
}
