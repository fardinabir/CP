#include <bits/stdc++.h>
#define LL long long
using namespace std;

int val[10001],wt[10001];

LL n;

LL phi(LL n) {
    LL ans = n;
    for (LL i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            ans -= ans / i;
        }
    }
    if(n > 1)
        ans -= ans / n;
    return ans;
}

int main()
{
    LL i,j,k,a,b,c,cnt=0,id=1,l,t,x,y,mx=0;
    while(cin>>n)
    {
        if(!n)
            return 0;
        cout<<phi(n)<<endl;

    }
    return 0;
}
