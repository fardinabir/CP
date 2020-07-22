#include <bits/stdc++.h>
#define ll  long long int
#define mx 100000

using namespace std;

ll arr[10005],cnt[100005],res[100005];
ll ncr[100005][8];

void F()
{
    ncr[0][0] = 1;
    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j <= 4; j++) {
            if (j > i) ncr[i][j] = 0;
            else if (j == i || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
        }
    }
}

int main()
{
    ll i,j,a,b,k,d,n,idd=0,m=0,ans=0,t;

    F();
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=0;
        for(i=0;i<n;i++)
        {
            cin>>k;
            cnt[k]++;
        }
        for(i=10000;i>=1;i--)
        {
            ll tt=cnt[i],sub=0;
            for(j=i+i;j<=10000;j+=i)
            {
                tt+=cnt[j];
                sub+=res[j];
            }
            res[i]=ncr[tt][4]-sub;
        }
        printf("Case %lld: %lld\n",++idd,res[1]);
        memset(cnt,0,sizeof(cnt));
        memset(res,0,sizeof(res));
    }
    return 0;
}

