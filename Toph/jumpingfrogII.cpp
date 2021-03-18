#include <bits/stdc++.h>

using namespace std;

struct nn
{
    int lazy,cnt;
    nn()
    {
        lazy=0;
        cnt=0;
    }
};

int arr[100005],n,m;
nn node[400005];

void propagate(int ind)
{
    if(node[ind].lazy)
    {
        node[ind*2].cnt+=node[ind].lazy;
        node[ind*2+1].cnt+=node[ind].lazy;
        node[ind*2].lazy+=node[ind].lazy;
        node[ind*2+1].lazy+=node[ind].lazy;
        node[ind].lazy=0;
    }
}

void update(int ind,int i,int j,int l,int r,int val)
{
    if(i>r || j<l)
        return;
    if(i>=l && j<=r)
    {
        node[ind].cnt+=val;
        node[ind].lazy+=val;
        return;
    }
    propagate(ind);
    int mid=(i+j)>>1;
    update(ind*2,i,mid,l,r,val);
    update(ind*2+1,mid+1,j,l,r,val);
    node[ind].cnt=min(node[ind*2].cnt,node[ind*2+1].cnt);
}

int query(int ind,int i,int j) // searching the rightmost node with cnt=0 
{
    if(i==j)
        return i;
    propagate(ind);
    int mid=(i+j)>>1;
    if(node[ind*2+1].cnt>0)
        return query(ind*2,i,mid);
    else
        return query(ind*2+1,mid+1,j);
}

void clear_all()
{
    for(int i=0;i<=n+1;i++)
        arr[i]=0;
    for(int i=0;i<=(4*n+1);i++)
        node[i].lazy=0,node[i].cnt=0;
}

int main()
{
    int t,k,a,b,i,q,j,l,s,c,mx=-1,mn=INT_MAX,ts=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            update(1,1,n+1,i+1,min(i+arr[i],n+1),1);
        }
        printf("Case %d:\n", ++ts);
        while(q--)
        {
            cin>>a;
            if(a==1)
            {
                cin>>b>>c;
                update(1,1,n+1,b+1,min(b+arr[b],n+1),-1);
                arr[b]=c;
                update(1,1,n+1,b+1,min(b+arr[b],n+1),1);
            }
            else
            {
                cin>>b;
                if(b>=query(1,1,n+1))
                    cout<<"yes\n";
                else
                    cout<<"no\n";
            }
        }
        clear_all();
    }
    return 0;
}
/*
1
5 11
0 0 1 5 3
2 1
2 2
2 3
2 4
2 5
1 4 0
2 1
2 5
2 3
1 1 4
2 1

*/
