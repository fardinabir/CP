


/// uva 10819 un submitted......................



#include <bits/stdc++.h>
#define LL long long
using namespace std;

int val[10001],wt[10001];

int kp[101][10001],cap,n,m;

int knapsack(int i,int w)
{
    if(w>cap && w-200>cap)
        return -INT_MAX;
    if(w>cap && cap<1800)
        return -INT_MAX;
    if(i==m)
    {
        if(w>cap && w<=2000)
            return -INT_MAX;
        return 0;
    }

    if(kp[i][w]!=-1)
        return kp[i][w];

    kp[i][w]=max(knapsack(i+1,w),val[i]+knapsack(i+1,w+wt[i]));
    return kp[i][w];
}

int main()
{
    LL i,j,k,a,b,c,cnt=0,id=1,l,t,x,y,mx=0;

    while(cin>>cap>>m)
    {
        memset(kp,-1,sizeof kp);
        for(i=0;i<m;i++)
        {
            cin>>wt[i]>>val[i];
        }

        cout<<knapsack(0,0)<<endl;

    }
    return 0;
}

/*

500 4
100 2
100 3
200 3
400 4


*/
