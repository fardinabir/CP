#include<bits/stdc++.h>

using namespace std;

int arr[200005],ans[200005],ansf[200005],node[800005],x;

void build(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind]=1;
        return;
    }
    int mid=(i+j)>>1;
    build(ind<<1,i,mid);
    build((ind<<1)+1,mid+1,j);

    node[ind]=node[ind<<1]+node[(ind<<1)+1];
}


void query_up(int ind,int i,int j,int th)
{
    if(i==j && node[ind])
    {
        ans[i]=x;
        node[ind]=0;
        return;
    }
    if(th<=node[ind<<1])
    {
        query_up(ind<<1,i,(i+j)/2,th);
    }
    else if(th<=(node[ind<<1]+node[(ind<<1)+1]))
    {
        query_up((ind<<1)+1,(i+j)/2+1,j,th-node[ind<<1]);
    }
    node[ind]=node[(ind<<1)]+node[(ind<<1)+1];
}


int main()
{
    int i,k,t,l,m,n,s=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        build(1,1,n);
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        for(x=n;x>0;x--)
        {
            k=max(x-arr[x],1);
            query_up(1,1,n,k);
        }
        for(i=1;i<=n;i++)
        {
            ansf[ans[i]]=i;
        }
        for(i=1;i<=n;i++)
        {
            printf("%d ",ansf[i]);
        }
        cout<<endl;
    }

}
