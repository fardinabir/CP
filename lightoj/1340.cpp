#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000005

ll ans[MAX + 5];

bool chk[MAX + 5];

vector <ll> prime;

void seive()
{
    ll i,j,lim;
    prime.push_back(2);

    lim=sqrt(MAX);
    for(i=4;i<MAX;i+=2)
        chk[i]=i;
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

int main()
{
    ll tc,idd=0,b,s,n,nn,temp,r,i,j,p,k,q,c,sod,lob,hor;
    seive();
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&n,&k);
//        if(!n)
//            return 0;
        s=1;
        for(i=0;prime[i]<=n;i++)
        {
            b=prime[i],c=0;
            while(n/b)
            {
                c+=n/b;
                b*=prime[i];
            }

            if(c>=k)
            {
                while(c-k>=0)
                {
                    c-=k;
                    s=(s*prime[i])%10000019;
                }
            }
            else
            {
                break;
            }
        }
        printf("Case %lld: ",++idd);
        if(s==1)
            printf("-1\n");
        else
            printf("%lld\n",s);
    }
    return 0;
}
