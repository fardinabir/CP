#include<bits/stdc++.h>

using namespace std;

long long arr[100005];

int main()
{
    long long int i,k,t,l=0,m,n,s=1;
    for(i=0;i<100000;i++)
    {
        s+=i;
        arr[l++]=s;
    }
    cin>>t;
    while(t--)
    {
        cin>>k;
        if(binary_search(arr,arr+100000,k))
            cout<<1<<" ";
        else
            cout<<0<<" ";
    }
    return 0;
}
