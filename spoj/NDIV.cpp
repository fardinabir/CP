#include <bits/stdc++.h>
#define ll  long long int
#define mx 100000

using namespace std;
vector <ll> prime;
ll chk[mx+5];

void seive()
{
    ll i,j,k;
    prime.push_back(2);
    for(i=3;i<=mx;i+=2)
    {
        if(!chk[i])
        {
            prime.push_back(i);
            for(j=i*i;j<=mx;j+=(2*i))
                chk[j]=1;
        }
    }
}

int main()
{
    ll i,j,a,b,k,d,n,cnt,idd=0,m=0,ans=0,t;
    seive();
    cin>>a>>b>>n;

    for(i=a;i<=b;i++)
    {
        t=i,ans=1;
        for(j=0;j<prime.size() && prime[j]*prime[j]<=t;j++)
        {
            if(t%prime[j]==0)
            {
                cnt=0;
                while(t%prime[j]==0)
                {
                    t/=prime[j];
                    cnt++;
                }
                ans*=(cnt+1);
            }
        }
        if(t>1)
            ans*=2;
        if(ans==n)
            m++;
    }
    cout<<m<<endl;
    return 0;
}
