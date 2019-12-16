#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n,i,j,k,s,e,l=0;
    cin>>n>>s>>e;
    int arr[n+5],temp[n+5],tempp[n+5];
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    k=s;
    while(l<=n)
    {
        if(k==e)
        {
            cout<<l<<endl;
            return 0;
        }
        k=arr[k];
        l++;
    }
    cout<<-1<<endl;
    return 0;
}
