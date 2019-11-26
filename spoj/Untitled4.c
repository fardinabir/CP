#include <bits/stdc++.h>
#define ll  unsigned

using namespace std;

const int MAX = 100000000;  // 10^8
const int LMT =     10000;  // sqrt(MAX)

int _c[(MAX>>6)+1];

int  primes[5761482];

#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))

#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
ll mnt=0;
void sieve()
{
    int x=0;

    for (int i = 3; i <= LMT; i += 2)
        if (!IsComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                SetComp(j);

    primes[x++]=2;
    mnt++;
    for (int i=3; i <= MAX; i += 2)
        if (!IsComp(i))
        {
            primes[x++]=i;
            mnt++;
        }
}

ll store[5761482];

void precal()
{
    store[0]=2;

    for(ll i=1; i<mnt; i++)
    {
        store[i]=store[i-1]*primes[i];
    }
}
ll cal(ll n)
{
    ll temp,ret=1;

    for(ll i=0; primes[i]*primes[i]<=n; i++)
    {
        temp=n;
        temp=temp/primes[i];
        while(temp>=primes[i])
        {
            temp=temp/primes[i];
            ret=ret*primes[i];
        }
    }
    return ret;

}

int main()
{
    ll  n,val,sq,q,rs,cnt,ans,t,ca=1;
    sieve();
    precal();
    scanf("%u",&t);

    while(t--)
    {
        scanf("%u",&n);

        ans=cal(n);

        val=upper_bound(primes,primes+mnt,n)-primes;
        val--;
        ans=ans*store[val];

        printf("Case %u: %u\n",ca,ans);
        ca++;
    }
}
