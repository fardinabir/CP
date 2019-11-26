#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll>prime;

ll sz=10000005;
bool chk[10000005];

void seive()
{
    ll i,j,k;
    prime.push_back(2);
    chk[1]=1;
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

int main()
{
    ll tc,idd=0,b,n,temp,r,i,p,q,c,ev,od,ans;
    seive();
    //cout<<prime[prime.size()-1]<<endl;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&n);
        ev=0,od=0;
        //printf("Case %lld: ",++idd);
        for(i=0;prime[i]*prime[i]<=n;i++)
        {
            c=0;
            while(n%prime[i]==0)
            {
                c++;
                n/=prime[i];
            }
            if(c%2)
                od++;
            else if(c)
                ev++;
        }
        if(n>1)
            od++;
        if(ev>od)
            printf("Psycho Number\n");
        else
            printf("Ordinary Number\n");
    }
    return 0;
}
