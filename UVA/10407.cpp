#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[10000];

int main()
{
    ll i,j,k,n,t,id=0,dif=0,g=0;
    while(cin>>k)
    {
        id=0;
        if(!k)
            return 0;
        g=0;
        arr[id++]=k;
        while(cin>>k)
        {
            if(!k)
                break;
            dif=(k-arr[id-1]);
            arr[id++]=k;
            g=__gcd(g,dif);
        }
        g=g<0?g*-1:g;
        printf("%lld\n",g);
    }
    return 0;
}
/*

701 1059 1417 2312 0
14 23 17 32 122 0
14 -22 17 -31 -124 0
0

*/
