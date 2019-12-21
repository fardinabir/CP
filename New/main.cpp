#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main()
{
    int i,j,k,p,n;
    cin>>n;
    cin>>p;
    for(i=0;i<p;i++)
    {
        cin>>k;
        arr[k]=1;
    }
    cin>>p;
    for(i=0;i<p;i++)
    {
        cin>>k;
        arr[k]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(arr[i]!=1)
        {
            cout<<"Oh, my keyboard!";
            return 0;
        }
    }
    cout<<"I become the guy.";
    return 0;
}
