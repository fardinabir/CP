#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000003

bool chk[1000005];

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
            //cout<<i<<endl;
            prime.push_back(i);

            if(i<=lim)
            {
                for(j=i*i;j<=MAX;j+=2*i)
                    chk[j]=1;
            }
        }
    }
}

ll cal(ll a,ll b)
{
    ll i,j,k,ans=0;
    for(i=0;i<prime.size()&&prime[i]*prime[i]<=b;i++)
    {
        k=prime[i]*prime[i];
        while(k<=b)
        {
            if(k>=a)
                ans++;
            k*=prime[i];
        }
    }
    return ans;
}


int main()
{
    ll tc,idd=0,b,s,n,m,temp,r,i,j,p,k,q,c,sod,lob,hor;
    seive();
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&n,&m);
        cout<<cal(n,m)<<endl;
    }
    return 0;
}
/*


2

5 7

0110110

0000010

1000001

0100001

1100010

3 3

001

100

101

*/
