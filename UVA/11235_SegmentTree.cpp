#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct node
{
    int mxF,mxFl,mxVl,mxFr,mxVr;
}node[300005];

int arr[100005],freq[100005],ep[100005];

void init(int n,int i,int j)
{
    if(i==j)
    {
        node[n].mxVl=node[n].mxVr=arr[i];
        node[n].mxFl=node[n].mxFr=node[n].mxF=1;
        return;
    }
    int mid=(i+j)/2,l,r,mx,mx1,mx2;
    l=2*n;
    r=l+1;
    init(l,i,mid);
    init(r,mid+1,j);

    node[n].mxVl=node[l].mxVl;
    node[n].mxVr=node[r].mxVr;
    node[n].mxFl=node[l].mxFl;
    node[n].mxFr=node[r].mxFr;
    node[n].mxF=max(node[l].mxF,node[r].mxF);
    if(node[l].mxVr==node[r].mxVl)
    {
        node[n].mxF=max(node[n].mxF,node[l].mxFr+node[r].mxFl);
        if(node[l].mxVl==node[l].mxVr)
            node[n].mxFl+=node[r].mxFl;
        if(node[r].mxVl==node[r].mxVr)
            node[n].mxFr+=node[l].mxFr;
    }
}

int query(int n,int b,int e,int l,int r)
{
    if(r<b || e<l)
        return -1;
    if(b>=l && e<=r)
    {
        return node[n].mxF;
    }
    int m=(b+e)/2;
    int L=n*2;
    int R=L+1;
    int ql=query(L,b,m,l,r);
    int qr=query(R,m+1,e,l,r);
    int ans=max(ql,qr);
    if(node[L].mxVr==node[R].mxVl)
    {
        int lc,rc;
        lc=min(m-l+1,node[L].mxFr);
        rc=min(r-m,node[R].mxFl);
        ans=max(ans,lc+rc);
    }
    return ans;
}

int main() {
    int i,j,k,l,m,n,t,c=1;
    while(cin>>n,n)
    {
        scanf("%d",&t);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        init(1,1,n);
        while(t--)
        {
            int l,r;
            scanf("%d %d ",&l,&r);
            int ans=query(1,1,n,l,r);
            printf("%d\n",ans);
        }
    }
    return 0;
}
