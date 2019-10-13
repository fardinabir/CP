#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main ()
{
    ll tc,idd=0,b,n,temp,r,i,p,q,c,ans;
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
            {
                ans=mid;
                break;
            }
            if(cnt<n)
                lo=mid+1;
            else
                hi=mid-1;
        }
        if(ans)
            printf("%lld\n",ans-ans%5);
        else
            printf("impossible\n");
    }
    return 0;
}
