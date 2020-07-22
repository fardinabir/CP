#include <bits/stdc++.h>

using namespace std;

struct nn
{
    int sum,prop;
    nn()
    {
        sum=0;
        prop=0;
    }
};

int arr[100005],n,k;
nn node[300000];

void propagate(int ind,int i,int j)
{
    if(node[ind].prop==-1)
        return;
    node[ind].sum=node[ind].prop*(j-i+1);

    if(j>i)
    {
        node[2*ind].prop=node[ind].prop;
        node[2*ind+1].prop=node[ind].prop;
    }
    node[ind].prop=-1;
}

void update(int ind,int i,int j,int s,int e,int val)
{
    propagate(ind,i,j);
    if(i>e || j<s)
        return;
    if(i>=s && j<=e)
    {
        node[ind].prop=val;
        propagate(ind,i,j);
        //cout<<i<<" -- "<<j<<" "<<node[ind].sum<<endl;
        return;
    }
    int mid=(i+j)/2;
    update(2*ind,i,mid,s,e,val);
    update(2*ind+1,mid+1,j,s,e,val);

    node[ind].sum=node[2*ind].sum+node[2*ind+1].sum;
    //cout<<i<<" -- "<<j<<" "<<node[ind].sum<<endl;
}

int query(int ind,int i,int j,int s,int e)
{
    int a,b;
    propagate(ind,i,j);
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {
        //cout<<i<<" -- "<<j<<" "<<node[ind].sum<<endl;
        return node[ind].sum;
    }
    int mid=(i+j)/2;
    //cout<<i<<" -- "<<j<<" "<<node[ind].sum<<endl;

    a=query(2*ind,i,mid,s,e);
    b=query(2*ind+1,mid+1,j,s,e);

    return a + b;
}

void clear_node(int sz)
{
    for(int i=0;i<=sz;i++)
        node[i].sum=node[i].prop=0;
}

int main()
{
    int i,j,l,s,m,q,e,val,id=1,a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",id++);
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&q);
            if(q==1)
            {
                scanf("%d %d %d",&s,&e,&val);
                update(1,1,n,s+1,e+1,val);
            }
            else
            {
                scanf("%d %d",&s,&e);
                l=(e-s+1);
                a=query(1,1,n,s+1,e+1);
                b=__gcd(a,l);
                a/=b,l/=b;

                if(l==1)
                {
                    printf("%d\n",a);
                }
                else
                {
                    printf("%d/%d\n",a,l);
                }
            }
        }
        clear_node(3*n);
    }
}
/*
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
*/
