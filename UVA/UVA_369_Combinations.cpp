#include <bits/stdc++.h>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

int arr[1000000];
int chk[2000];

int main()
{
    ll m,t,i,j,k,r,c,n,mn,a,b,l=1,li,id=1;
    while(1)
    {
        cin>>a>>b;
        if(a==0 && b==0)
            return 0;
        k=max(b,a-b),r=min(b,a-b),l=1,j=1;
        for(i=a;i>k;i--)
        {
            l*=i;
            l/=j;
            j++;
        }
        printf("%lld things taken %lld at a time is %lld exactly.\n",a,b,l);
    }
    return 0;
}
/*
100  6
20  5
18  6
0  0
*/
