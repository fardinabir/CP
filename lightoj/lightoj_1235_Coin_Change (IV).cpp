#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[2000],x[20000],n,m,k,wt,p,y;

void cal(int i,int s)
{
    if(s>wt)
        return;
    if(i==m)
    {
        if(s<=wt)
            x[k++]=s;
        return;
    }

    cal(i+1,s);
    cal(i+1,s+arr[i]);
    cal(i+1,s+arr[i]+arr[i]);
}

bool cal1(int i,int s)
{
    if(i==n)
    {
        if(binary_search(x,x+k,s))
            return true;
        else
            return false;
    }

    if(cal1(i+1,s))
        return true;
    else if(cal1(i+1,s-arr[i]))
        return true;
    return cal1(i+1,s-arr[i]-arr[i]);
}

int main()
{
    ll id=1,l,i,j,s,e=INT_MAX,v=0,key,t,cnt;

    cin>>t;
    while(t--)
    {
        k=0,y=0,
        cin>>n>>wt;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        m=n/2+n%2;
        cal(0,0);
        sort(x,x+k);
        if(cal1(m,wt))
            printf("Case %lld: Yes\n",id++);
        else
            printf("Case %lld: No\n",id++);
        memset(x,0,sizeof x);
    }
    return 0;
}
