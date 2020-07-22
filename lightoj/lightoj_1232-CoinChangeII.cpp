#include <bits/stdc++.h>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

int arr[305];
int table[10005];

int main()
{
    ll t,i,j,k,n,l,m,r,c=0,d,p,e,u,v,q,cumsum,x,y,id=1,sz,a=0,b=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<n;i++)
            cin>>arr[i];
        memset(table,0,sizeof table);
        table[0]=1;
        for(i=0;i<n;i++)
        {
            for(j=arr[i];j<=k;j++)
            {
                table[j]+=(table[j-arr[i]]);
                table[j]=table[j]%100000007;
            }
        }
        printf("Case %lld: %d\n",id++,table[k]);
    }
    return 0;
}
