#include<bits/stdc++.h>


using namespace std;

int arr[10000][2];

int main()
{
    int i,j,k,l,n,m,cnt=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    for(i=0;i<n;i++)
    {
        int a=0,b=0,c=0,d=0;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(arr[j][0]<arr[i][0] && arr[j][1]==arr[i][1])
                    a=1;
                else if(arr[j][0]>arr[i][0] && arr[j][1]==arr[i][1])
                    b=1;
                else if(arr[j][0]==arr[i][0] && arr[j][1]<arr[i][1])
                    c=1;
                else if(arr[j][0]==arr[i][0] && arr[j][1]>arr[i][1])
                    d=1;
            }
        }
        if(a*b*c*d==1)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
