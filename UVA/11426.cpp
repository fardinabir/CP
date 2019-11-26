#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 4000001

ll phi[4000001],res[4000001];

void totient()
{
    ll i,j,k;
    phi[1]=1;
    for(i=2;i<MAX;i++)
    {
        if(!phi[i])
        {
            phi[i]=i-1;
            for(j=2*i;j<MAX;j+=i)
            {
                phi[j]= phi[j]==0? j: phi[j];
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}


void pre_cal()
{
    ll i,j,k;
    for(i=1;i<MAX;i++)
    {
        for(j=2;j*i<MAX;j++)
        {
            res[i*j]+=(i*phi[j]);
        }
    }
    for(i=2;i<MAX;i++)
    {
        res[i]+=res[i-1];
    }
}

int main()
{
    ll tc,idd=0,b,s,n,nn,temp,r,i,p,k,q,c,ans,sod,lob,hor;
    //scanf("%lld",&tc);
    totient();
    pre_cal();
    while(1)
    {
        scanf("%lld",&n);
        if(!n)
            return 0;
        //printf("Case %lld: ",++idd);


        printf("%lld\n",res[n]);
    }
    return 0;
}
