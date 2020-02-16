
#include<bits/stdc++.h>
#define ll long long int
#define mx 10000000

using namespace std;

bool chk[mx+5];

vector <int> primes;

void seive()
{
    primes.push_back(2);
    for(ll i=3;i<=mx;i+=2)
    {
        if(!chk[i])
        {
            primes.push_back(i);
            for(ll j=i*i;j<=mx;j+=(i+i))
                chk[j]=true;
        }
    }
}

int main ()
{
    ll t,i,j,k,n,ans,sz,cnt,id=1;
    cin>>t;
    seive();
    sz=primes.size();
    while(t--)
    {
        cin>>n;

        k=n;

        ll s=1;
        for(i=0;i<sz && primes[i]*primes[i]<=k;i++)
        {
            cnt=1;
            while(k%primes[i]==0)
            {
                k/=primes[i];
                cnt++;
            }
            if(i)
                s*=cnt;
        }
        if(k>2)
            s*=2;
        printf("Case %lld: %lld\n",id++,s-1);
    }
    return 0;
}

