#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll>prime;

ll sz=100000;
bool chk[1000005];
ll m=1000000007;
vector <ll> divisors,val;


void seive()
{
    ll i,j,k;
    prime.push_back(2);
    chk[1]=1;
    k=sqrt(sz)+0.0001;
    for(i=3;i<=k;i+=2)
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

ll phi(ll n)
{
    ll i,j,k,l,ans=n;
    k=sqrt(n)+0.0001;
    for(i=0;i<prime.size() && prime[i]<=k;i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
                n/=prime[i];

            ans*=(prime[i]-1);
            ans/=prime[i];
        }
    }
    if(n!=1)
    {
        ans*=n-1;
        ans/=n;
    }
    return ans;
}

ll bigmod(ll n,ll p)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll x=bigmod(n,p/2)%m;
        return (x*x)%m;
    }
    return ((n%m)*bigmod(n,p-1)%m)%m;
}

ll mod_inverse(ll n)
{
    return bigmod(n,m-2);
}

int main()
{
    ll tc,idd=0,b,s,n,nn,temp,r,i,p,k,q,c,ans,sod,lob,hor;
    seive();
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&n,&q);
        printf("Case %lld: ",++idd);

        sod=1;
        for(i=0;prime[i]*prime[i]<=n;i++)
        {
            if(n%prime[i]==0)
            {
                c=0;
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    c++;
                }
                lob=m+(bigmod(prime[i],c*q+1)%m)-1;
                hor=m+(mod_inverse(prime[i]-1)%m);
                s=((lob%m)*(hor%m))%m;
                sod=((sod%m)*(s%m))%m;
            }
        }
        if(n>1)
        {

            lob=m+(bigmod(n,q+1)%m)-1;
            hor=m+(mod_inverse(n-1)%m);
            s=((lob%m)*(hor%m))%m;
            sod=((sod%m)*(s%m))%m;
        }
        printf("%lld\n",sod);
    }
    return 0;
}
