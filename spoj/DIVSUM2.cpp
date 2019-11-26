#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll prime[100000005],ind;
bool pcheck[100000005];



void seive()
{
    ll i,j,k;
    prime[ind++]=2;
    for(i=3;i<=100000005;i+=2)
    {
        if(!pcheck[i])
        {
            prime[ind++]=i;
            if(i*i>100000005)
                continue;
            for(j=i*i;j<=100000005;j+=2*i)
            {
                pcheck[j]=1;
            }
        }
    }
}

int main ()
{
    ll tc,idd=0,p,n,a,s,b,c,cnt,num=1,k,x,i;
    seive();
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&a);
        //printf("Case %lld: ",++idd);
        ll sod=1;
        x=a;
        for(i=0;i<ind && (prime[i]*prime[i])<=a;i++)
        {
            cnt=0,b=prime[i],s=prime[i];
            while(a%b==0)
            {
                a/=b;
                s*=b;
            }
            sod*=((s-1)/(b-1));

        }
        if(a!=1)
            sod*=(a+1);
        printf("%lld\n",sod-x);
    }
    return 0;
}
