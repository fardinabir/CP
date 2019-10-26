#include<bits/stdc++.h>

using namespace std;

long long arr[100005],k,t;

long long solve(int i,long long s)
{
    if(s>k || i==t)
    {
        return s>k? s-arr[i-1] : s;
    }
    long long a,b;
    a=solve(i+1,s+arr[i]);
    b=solve(i+1,s);
    return max(a,b);
}

int main()
{
    long long int i,l=0,m,n,s=0,x,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    k=s/2;
    j=s-k;
    x=solve(0,0);
    cout<<max(x,s-x)-min(x,s-x);
    return 0;
}
/*
5
8 13 14 5 27

*/

