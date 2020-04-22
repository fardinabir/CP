#include <bits/stdc++.h>
#define mx 1000005
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

ll arr[mx],pre_sum[mx],n;
vector <ll> node[4*mx];

int main()
{
    ll t,i,j,k,l,a,b,c=0,p,d=0,e,u,v,q,sum,id=1,x,y;
    cin>>t;
    while(t--)
    {
        c=0;
        scanf("%lld",&n);
        map <ll,ll> mp;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            pre_sum[i]+=(pre_sum[i-1]+a);
            mp[pre_sum[i]]++;
        }
        for(i=1;i<=n;i++)
        {
            c+=mp[pre_sum[i-1]];
            mp[pre_sum[i]]--;
        }
        cout<<c<<endl;
        memset(pre_sum,0,sizeof pre_sum);
    }
    return 0;
}
