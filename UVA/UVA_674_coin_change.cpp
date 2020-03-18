/// uva 674, coin change

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[5][7490];
int coin[5]={1,5,10,25,50};

int main()
{
    int i,j,k,m,s,n,e=INT_MAX,v=0,key,x=0,t,c=1;
    ll l;

    for(i=0;i<5;i++)
    {
        dp[i][0]=1;
        for(j=1;j<7490;j++)
        {
            if(i)
            {
                if(j>=coin[i])
                    dp[i][j]=dp[i-1][j]+dp[i][j-coin[i]];
                else
                    dp[i][j]=dp[i-1][j];
            }
            else
            {
                if(j>=coin[i])
                    dp[i][j]=dp[i][j-coin[i]];
            }
        }
    }

    while(cin>>n)
    {
        cout<<dp[4][n]<<endl;
    }
    return 0;
}
