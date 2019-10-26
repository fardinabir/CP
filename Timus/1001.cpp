#include<bits/stdc++.h>

using namespace std;

#define ll long long

double arr[1000005];

int main()
{
    ll n,m,i=0,t,j=0,ck=0,a=0,b=0;

    while(scanf("%lld",&n)!=EOF)
    {
        arr[i++] =  (double)sqrt(n);
    }

    for( ; --i>=0 ; )
    {
        printf("%.4lf\n", arr[i]);
    }

}
