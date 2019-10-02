#include<bits/stdc++.h>

using namespace std;

#define ll long long

int prime[100005],pcheck[100005],ind;

void seive(ll n)
{
    ll i,j,k;
    prime[ind++]=2;
    for(i=4;i<100000;i+=2)
    {
        pcheck[i]=1;
    }
    for(i=3;i<=100000;i+=2)
    {
        if(!pcheck[i])
        {
            prime[ind++]=i;
            if(i*i>100000)
            continue;
            for(j=i*i;j<=100000;j+=2*i)
            {
                pcheck[j]=1;
            }
        }
    }
}

int main ()
{
    long long int tc,idd=0,p,n,a,b,c,c1,c2,c3,t,id,d,l,r,num=1,k,x,i;
    seive(100000);
    scanf("%lld",&tc);
    while(idd<tc){
        num=1;
        scanf("%lld %lld %lld",&a,&b,&l);
        printf("Case %lld: ",++idd);
        if(l%a!=0 || l%b!=0)
        {
            printf("impossible\n");
            continue;
        }
        d=(a/__gcd(a,b))*b;
        for(i=0;i<ind;i++)
        {
            c1=0,c2=0,c3=0;
            while(l%prime[i]==0)
            {
                l/=prime[i];
                c1++;
            }
            while(d%prime[i]==0)
            {
                d/=prime[i];
                c2++;
            }
            if(c2==c1)
            {
                c3=0;
            }
            else
            {
                c3=c1;
                while(c3--)
                {
                    num*=prime[i];
                }
            }
        }
        printf("%lld\n",num);
    }
    return 0;
}
