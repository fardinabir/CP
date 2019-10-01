#include <bits/stdc++.h>

using namespace std;

int arr[10000005],n,xx;

int main()
{
    int i,t,nn,j=0,k=0,l,n=0,s,m,e;
    cin>>t;
    while(t--)
    {
        n=0,nn=INT_MAX;
        scanf("%d",&m);
        for(k=0;k<m;k++)
        {
            scanf("%d %d",&s,&e);
            nn=min(nn,s);
            n=max(n,e);
            arr[s]++;
            arr[e+1]--;
        }
        k=0,j=0;
        for(i=nn;i<=n;i++)
        {
            j+=arr[i];
            k=max(k,j);

        }
        printf("%d\n",k);
        k=0;
        memset(arr,0,sizeof(arr));
    }

}
/*
8 10
0 2 5
0 4 7
1 2 7
0 1 6
0 3 5
1 3 4
1 4 5
1 5 6
*/
