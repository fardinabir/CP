#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000];

int main()
{
    int i,j,k,l,s=0,cnt,id,n,t,cum[1000]={0};
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        int mx=-1;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                s=0;
                for(k=0;k<n;k++)
                {
                    cum[k]+=arr[k][j];
                    s+=cum[k];
                    if(s<0)
                        s=0;
                    mx=max(mx,s);
                }
            }
            for(k=0;k<n;k++)
            {
                cum[k]=0;
            }
        }
        printf("%d\n",mx);
    }
}
