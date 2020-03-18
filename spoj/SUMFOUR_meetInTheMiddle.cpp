#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int a[4000],b[4000],c[4000],d[4000];

int x[7000000],y[7000000];

int main()
{
    int id=1,i,j,n,k,m,s,e=INT_MAX,v=0,key,t,cnt;
    ll l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);

    int f1,f2;
    cnt=0,k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x[k]=a[i]+b[j];
            y[k]=c[i]+d[j];
            k++;
        }
    }
    sort(x,x+k);
    sort(y,y+k);

    i=0,j=k-1;

    while(i<k && j>=0)
    {
        f1=f2=1;
        if(x[i]+y[j]==0)
        {
            while(x[i]==x[i+1] && i<k-1)
                i++,f1++;
            while(y[j]==y[j-1] && j>0)
                j--,f2++;

            cnt+=f1*f2;
            i++,j--;
        }
        else if(x[i]+y[j]>0)
            j--;
        else
            i++;
    }
    printf("%d\n",cnt);
    return 0;
}
