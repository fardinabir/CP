#include<bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

ll arr[1000],x[70000],y[70000],l,j,maxmul,mul_limit,cnt;

void cal1(ll i,ll n,ll mul,ll result[])
{
    if(i==n)
    {
        result[l++]=mul;
        return;
    }
    cal1(i+1,n,mul,result);
    maxmul=1e19/mul;
    if(arr[i]<=maxmul)
        cal1(i+1,n,mul*arr[i],result);
    else
        cal1(i+1,n,1e19,result);
}

int main()
{
    int i, sum,s=0,n,m,f1,f2;
    cin>>n>>mul_limit;
    for(i=0;i<n;i++)
        scanf("%llu",&arr[i]);

    cal1(0,n/2,1,x);
    f1=l,l=0;
    cal1(n/2,n,1,y);
    f2=l;
    cnt=0;
    sort(x,x+f1);

    for(i=0;i<f2;i++)
    {
        if(y[i]<=mul_limit)
        {
            cnt=upper_bound(x,x+f1,mul_limit/y[i])-x;
            s+=cnt;
            if(i==0)
                s--;
        }
    }
    cout<<s<<endl;
    return 0;
}

/*

4 100
1 2 3 4


3 1000000000000000000
1000000000000000000 1000000000000000000 1000000000000000000

*/

