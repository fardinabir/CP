#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(void)
{
    int T;
    ll n;
    scanf("%d",&T);
    int id = 1;
    while(T--)
    {
        scanf("%lld",&n);
        ll ans = n - (int)sqrt(n) - (int)sqrt(n/2);
        printf("Case %d: %lld\n",id++,ans);
    }

    return 0;
}
