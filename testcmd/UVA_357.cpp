/// uva 357

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[5][40000];
int coin[5]={1,5,10,25,50};


ll cal(int i,int s)
{
    if(s==0)
        return 1;
    if(i==5 || s<0)
        return 0;
    if(dp[i][s]!=-1)
        return dp[i][s];
    return dp[i][s]=cal(i,s-coin[i])+cal(i+1,s);
}

int main()
{
    int i,j,k,m,s,n,e=INT_MAX,v=0,key,x=0,t,c=1;
    ll l;
    memset(dp,-1,sizeof dp);
    while(cin>>n)
    {
        l=cal(0,n);
        if(l==1)
        {
            printf("There is only 1 way to produce %d cents change.\n",n);
        }
        else
        {
            printf("There are %lld ways to produce %d cents change.\n",l,n);
        }
    }
    return 0;
}
