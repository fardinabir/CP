#include <bits/stdc++.h>
#define ll  long long int

using namespace std;

#define mx 46341
bool check[100000];
vector <ll> prime;

void seive()
{
    prime.push_back(2);
    for(ll i=3;i<=mx;i+=2)
    {
        if(!check[i])
        {
            prime.push_back(i);
            for(ll j=i*i;j<mx;j+=(i+i))
                check[j]=true;
        }

    }
}

ll solve(ll n,ll d)
{
    ll cnt,cnt2,i,temp,ans=1;
    for(i=0;prime[i]<=n;i++)
    {
        temp=n;
        cnt=cnt2=0;
        while(temp/prime[i]>0)
        {
            cnt+=(temp/prime[i]);
            temp/=prime[i];
        }
        cnt++;

        while(d%prime[i]==0)
        {
            d/=prime[i];
            cnt2++;
        }
        if(cnt2>cnt)
            return 0;
        ans*=(cnt-cnt2);
    }
    if(d>1)
        return 0;

    return ans;
}

int main()
{
    seive();
    ll i,j,k,d,n;
    while(1)
    {
        cin>>n>>d;
        d=abs(d);
        if(n+d==0)
            return 0;

        cout<<solve(n,d)<<endl;
    }
}
