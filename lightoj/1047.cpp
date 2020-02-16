#include<bits/stdc++.h>


using namespace std;

int arr[10000][3],n;

int dp[100][3];

int cal(int i,int p)
{
    if(dp[i][p])
        return dp[i][p];
    if(i==n-1)
    {
        //cout<<min(min(arr[i][0],arr[i][1]),arr[i][2]);
        if(p==0)
            return dp[i][p]= min(arr[i][2],arr[i][1]);
        if(p==1)
            return dp[i][p]= min(arr[i][0],arr[i][2]);
        if(p==2)
            return dp[i][p]= min(arr[i][0],arr[i][1]);
    }
    if(i==0)
    {
        return dp[i][p]= min(min(arr[i][0]+cal(i+1,0),arr[0][1]+cal(i+1,1)),arr[0][2]+cal(i+1,2));
    }
    if(p==0)
    {
        return dp[i][p]= min(arr[i][1]+cal(i+1,1),arr[i][2]+cal(i+1,2));
    }
    else if(p==1)
    {
        return dp[i][p]= min(arr[i][0]+cal(i+1,0),arr[i][2]+cal(i+1,2));
    }
    else
        return dp[i][p]= min(arr[i][0]+cal(i+1,0),arr[i][1]+cal(i+1,1));
}

int main()
{
    int i,j,t,k,l,m,cnt=0,mn=0;
    cin>>t;
    while(t--)
    {
        mn=0;
        cin>>n;

        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
        }

        printf("Case %d: %d\n",++cnt,cal(0,0));

        memset(dp,0,sizeof dp);
    }
    return 0;
}
