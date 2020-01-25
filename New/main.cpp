#include <bits/stdc++.h>
#define ll long long
using namespace std;

map <ll,ll> mpl,mpr;

int arr[1000005];

int main()
{
    ll i,j,k,l,n,m,x,y,c,cc,t;
    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        mpr[arr[i]]++;
    }
    mpl[arr[0]]++;
    mpr[arr[0]]--;

    cc=0;
    for(i=1;i<n;i++)
    {
        mpr[arr[i]]--;

        if(arr[i]%m==0)
        {
            x=mpr[arr[i]*m];
            y=mpl[arr[i]/m];
            cc+=(x*y);
        }

        mpl[arr[i]]++;
    }
    cout<<cc<<endl;
    return 0;
}

/*

500 4
100 2
100 3
200 3
400 4


*/
