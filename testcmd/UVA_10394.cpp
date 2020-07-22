#include <bits/stdc++.h>
#define LL long long
using namespace std;

bool chk[20000005];

LL pp[200000];

LL n;

void seive()
{
    for(LL i=4;i<=20000000;i+=2)
        chk[i]=true;
    for(LL i=3;i<=20000000;i+=2)
    {
        if(!chk[i])
        {
            for(LL j=i*i;j<=20000000;j+=2*i)
                chk[j]=true;
        }
    }
}

int main()
{
    LL i,j,k,a,b,c,cnt=0,id=1,l,t,x,y,mx=0;

    seive();
    k=0;
    for(i=5;i<=20000000;i++)
    {
        if(!chk[i] && !chk[i-2])
        {
            pp[k++]=i;
        }

    }

    while(scanf("%lld",&n)!=EOF)
    {
        n--;
        printf("(%lld, %lld)\n",pp[n]-2,pp[n]);

    }
    return 0;
}
