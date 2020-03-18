#include <bits/stdc++.h>
#define ll  long long int

using namespace std;

#define mx 31622777
bool check[31622778];
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

void factorise(ll n)
{
    ll cnt,cnt2,i,temp,ans=1;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            cout<<prime[i]<<"^"<<cnt<<" ";
        }
    }
    if(n>1)
        cout<<n<<"^"<<1<<" ";
}

int main()
{
    seive();
    ll i,j,k,d,n;
    while(1)
    {
        cin>>n;
        if(n==0)
            return 0;

        factorise(n);
    }
}
