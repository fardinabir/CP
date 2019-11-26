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
        scanf("%lld",&n);
//        if(!n)
//            return 0;

        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ans[i]);
        }
        for(i=0;i<n;i++)
        {
            nn=ans[i];
            for(j=nn+1; ;j++)
            {
                if(!chk[j])
                {
                    s+=j;
                    break;
                }

            }
        }
        printf("Case %lld: ",++idd);
        printf("%lld Xukha\n",s);
    }
    return 0;
}
