#include<bits/stdc++.h>

#define N 1000000
#define pb push_back
#define pp pop_back

typedef long long ll;

using namespace std;


int main()
{
    int n,m,t,q,id=0;
    ll a,mx=0;
    scanf("%d %d",&n,&q);
    vector<ll>ar;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        ar.pb(a);
        mx=max(mx,a);
    }
    sort(ar.begin(),ar.end());
    int ty,k;
    ll sm=0,val,l,r;
    while(q--){
        scanf("%d",&ty);
        if(ty==1){
            scanf("%lld",&val);
            sm+=val;
        }
        else{
            scanf("%lld %lld %d",&l,&r,&k);
            l+=sm,r+=sm;
            int idx=lower_bound(ar.begin(),ar.end(),l)-ar.begin();
            if(idx==ar.size())
                printf("-1\n");
            else if(idx+k>n || (ar[idx-1+k]-sm)>r){
                printf("-1\n");
            }
            else{
                printf("%lld\n",ar[idx-1+k]-sm);
            }
        }
    }
    return 0;
}
