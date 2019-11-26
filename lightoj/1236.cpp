#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 10000000

bool chk[10000005];

vector <ll> prime;

void seive()
{
    ll i,j,lim;
    prime.push_back(2);

    lim=sqrt(MAX);
    for(i=3;i<MAX;i+=2)
    {
        if(!chk[i])
        {
            prime.push_back(i);
            if(i<=lim)
            {
                for(j=i*i;j<=MAX;j+=2*i)
                    chk[j]=1;
            }
        }
    }
}

ll check(ll n)
{
    ll i,ans=1,c;
    for(i=0;i<prime.size() && prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            c=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                c++;
            }
            ans*=(2*c+1);
        }
    }
    if(n>1)
        ans*=3;
    return ans;
}
int main()
{
    ll tc,idd=0,b,s,n,nn,temp,r,i,p,k,q,c,ans,sod,lob,hor;
    scanf("%lld",&tc);
    seive();
    while(tc--)
    {
        scanf("%lld",&n);
        printf("Case %lld: ",++idd);

        ans=check(n);

        printf("%lld\n",ans/2+1);
    }
    return 0;
}
