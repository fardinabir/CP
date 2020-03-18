#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[100][1005];
int coin[100],n,lim[100];

int cal(int i,int s)
{
    if(s==0)
        return 1;
    if(i==n || s<0)
        return 0;

    if(dp[i][s]!=-1)
        return dp[i][s]%100000007;

    int x=0;
    for(int j=0;j<=lim[i];j++)
    {
        x+=cal(i+1,s-(j*coin[i]));
        x%=100000007;
    }
    return dp[i][s]=x%100000007;
}


int main()
{
    int id=1,i,j,k,m,s,e=INT_MAX,v=0,key,x=0,t,c=1;
    ll l;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&coin[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&lim[i]);
        }

        printf("Case %d: %d\n",id++,cal(0,k)%100000007);

    }
    return 0;
}
