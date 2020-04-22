#include <bits/stdc++.h>

using namespace std;

int arr[100005],node[400005];
void init(int i,int j,int n)
{
    if(i==j)
    {
        node[n]=arr[i];
        return;
    }
    int mid=(i+j)/2;
    init(i,mid,2*n);
    init(mid+1,j,2*n+1);
    node[n]=min(node[2*n],node[2*n+1]);
}

int query(int i,int j,int s,int e,int n)
{
    if(i>e || j<s)
        return INT_MAX;
    if(i>=s && j<=e)
        return node[n];
    int mid = (i+j)/2;
    int re= min(query(i,mid,s,e,2*n),query(mid+1,j,s,e,2*n+1));
    return re;
}

int main() {
    int i,j,n,k,l,t,c=1;
    scanf("%d",&t);
    while(c<=t)
    {
        printf("Case %d:\n",c++);
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        init(1,n,1);
        for(i=0;i<k;i++)
        {
            scanf("%d %d",&j,&l);
            printf("%d\n",query(1,n,j,l,1));
            //cout<<query(1,n,j,l,1)<<endl;
        }
        memset(arr,0,sizeof(arr));
        memset(node,0,sizeof(node));
    }
    return 0;
}
