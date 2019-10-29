#include<bits/stdc++.h>
#define ll long long

using namespace std;

int last[100],n,x,y;

int solve(int i)
{
    int j;
    for(j=0;j<n;j++)
    {
        x=sqrt(last[j]+i);
        if(!last[j] || (x*x==last[j]+i))
        {
            last[j]=i;
            return solve(i+1);
        }
    }
    if(j==n)
        return i-1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<solve(0)<<endl;
        memset(last,0,sizeof last);
    }
    return 0;
}

