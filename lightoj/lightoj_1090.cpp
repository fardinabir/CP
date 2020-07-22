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
    ll tc,idd=0,b,n,temp,r,i,p,q,c;
    seive();
    //cout<<prime[prime.size()-1]<<endl;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
        printf("Case %lld: ",++idd);

        ll cnt2=0,cnt5=0,ct;

        temp=n;
        while(temp/2)
        {
            cnt2+=temp/2;
            temp/=2;

        }
        temp=n;
        while(temp/5)
        {
            cnt5+=temp/5;
            temp/=5;

        }

        temp=n-r;
        while(temp/2)
        {
            cnt2-=temp/2;
            temp/=2;
        }
        temp=n-r;
        while(temp/5)
        {
            cnt5-=temp/5;
            temp/=5;
        }

        temp=r;
        while(temp/2)
        {
            cnt2-=temp/2;
            temp/=2;
        }
        temp=r;
        while(temp/5)
        {
            cnt5-=temp/5;
            temp/=5;
        }

        temp=p,ct=0;
        while(temp%2==0)
        {
            ct++;
            temp/=2;
        }
        cnt2+=(q*ct),temp=p,ct=0;
        while(temp%5==0)
        {
            ct++;
            temp/=5;
        }
        cnt5+=(q*ct);

        ct=min(cnt2,cnt5);


        printf("%lld\n",ct);
    }
    return 0;
}
