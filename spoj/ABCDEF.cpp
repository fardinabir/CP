#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int a[4000];

int x[2000000];

int main()
{
    int id=1,l,i,j,n,k,m,s,e=INT_MAX,v=0,key,t,cnt;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    int f1,f2;
    cnt=0,k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(l=0;l<n;l++)
            {
                x[k++]=(a[i]*a[j])+a[l];
            }
        }
    }
    sort(x,x+k);
    cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(l=0;l<n;l++)
            {
                if(a[l]!=0)
                {
                    v=(a[i]+a[j])*a[l];
                    t=(upper_bound(x,x+k,v)-lower_bound(x,x+k,v));
                    t=max(0,t);
                    cnt+=t;
                }
            }
        }
    }



    printf("%d\n",cnt);
    return 0;
}
