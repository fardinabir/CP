#include<bits/stdc++.h>


using namespace std;

int arr[550][550];

int main()
{
    long long int n,m,t=0,i,j,q=0,s=0,id=0;
    cin>>n>>m;
    if(n==1 && m==1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(m>=n)
    {
        for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            arr[i][j]=i+1;
        }
    }
    s=n+1;
        for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[j][i]*=(s);
        }
        s++;
    }


    }
    else
    {
        for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[j][i]=i+1;
        }
    }
        s=m+1;
        for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            arr[i][j]*=(s);
        }
        s++;
    }

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
