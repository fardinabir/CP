#include <bits/stdc++.h>
#define newl "\n"
#define ll long long
const int mod = 100000007;

using namespace std;

int main()
{
    int t,idd=0,line=0,i,cnt=0,n,m,j,k,x;
    while(cin>>n>>m>>t)
    {
        ll ans1=1,ans2=1;
        if(n+m+t==0)
            return 0;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                cnt=0;
                while(n%i==0)
                {
                    n/=i;
                    cnt++;
                }
                cnt*=m;
                ans1=ans1*(cnt/t+1)%mod;
                ans2=ans2*(cnt/(t+1)+1)%mod;
            }
        }
        if(n!=1)
        {
            cnt=m;
            ans1=ans1*(cnt/t+1)%mod;
            ans2=ans2*(cnt/(t+1)+1)%mod;
        }
        printf("Case %d: %d\n",++idd,(ans1-ans2+mod)%mod);
        //cout<<(ans1-ans2+100000007)%100000007<<endl;
    }

    return 0;
}
/*
24 1 1
100 200 10
23 18 2
0 0 0
*/

