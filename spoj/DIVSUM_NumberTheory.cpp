#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll>prime;
ll ind;

ll num[500005];

void sod()
{
    for(int i=1;i<=500005;i++)
    {
        for(int j=i;j<=500005;j+=i)
        {
            num[j]+=i;
        }
    }
}

int main ()
{
    ll tc,idd=0,p,n,a,s,b,c,cnt,k,x,i;
    sod();
    //cout<<prime[prime.size()-1]<<endl;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&a);
        //printf("Case %lld: ",++idd);
        printf("%lld\n",num[a]-a);
    }
    return 0;
}
