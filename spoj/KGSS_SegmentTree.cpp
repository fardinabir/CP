#include <bits/stdc++.h>

using namespace std;

struct nn{
    int max1,max2;
    nn()
    {
        max1=max2=0;
    }
};

int arr[100005],n,xx;

nn node[400000],zero,c;

void update(int ind,int i,int j,int s,int val)
{
    if(i>s || j<s)
        return;
    if(i==j && i==s)
    {
        node[ind].max1=val;
        //cout<<i<<" -- "<<j<<" "<<node[ind].max1<<" "<<node[ind].max2<<endl;
        return;
    }
    int mid=(i+j)/2;
    update(2*ind,i,mid,s,val);
    update(2*ind+1,mid+1,j,s,val);

    int mnn=min(node[2*ind].max1,node[2*ind+1].max1);
    node[ind].max1=max(node[2*ind].max1,node[2*ind+1].max1);

    node[ind].max2=max(mnn,max(node[2*ind].max2,node[2*ind+1].max2));
    if(node[ind].max2==0)
        node[ind].max2=mnn;
    //cout<<i<<" -- "<<j<<" "<<node[ind].max1<<" "<<node[ind].max2<<endl;
}

nn query(int ind,int i,int j,int s,int e)
{
    nn a,b;
    if(i>e || j<s)
        return zero;
    if(i>=s && j<=e)
    {
        //cout<<i<<" -- "<<j<<" "<<node[ind].max1<<" "<<node[ind].max2<<endl;
        return node[ind];
    }
    int mid=(i+j)/2;
    a=query(2*ind,i,mid,s,e);
    b=query(2*ind+1,mid+1,j,s,e);

    int mnn=min(a.max1,b.max1);
    c.max1=max(a.max1,b.max1);
    c.max2=max(mnn,max(a.max2,b.max2));
    //cout<<i<<" -- "<<j<<" a: "<<a.max1<<" "<<a.max2<<" b: "<<b.max1<<" "<<b.max2<<" c: "<<c.max1<<" "<<c.max2<<endl;
    return c;
}

int main()
{
    int i,j,k,l,s,m,e;
    char ty;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        update(1,1,n,i,arr[i]); // build()
    }
    scanf("%d",&m);
    getchar();
    for(i=0;i<m;i++)
    {
        scanf("%c %d %d",&ty,&s,&e);
        getchar();
        if(ty=='U')
        {
            update(1,1,n,s,e);
        }
        else
        {
            c=query(1,1,n,s,e);
            printf("%d\n",c.max1+c.max2);
        }

    }
}
/*
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
*/
