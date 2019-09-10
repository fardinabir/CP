#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,i,j,k,flag;
ll arr[100005];

struct st{
    int sum,square_sum,propagte,same_val,prev_propagate;
    bool same;

}node[400005];

void build(int nn,int i,int j)
{
    if(i==j)
    {
        node[nn].sum=arr[i];
        node[nn].square_sum=arr[i]*arr[i];
        node[nn].same=false;
        node[nn].propagte=0;
        node[nn].prev_propagate=0;
        return;
    }
    int mid=(i+j)/2;

    build(2*nn,i,mid);
    build(2*nn+1,mid+1,j);

    node[nn].sum=node[2*nn].sum+node[2*nn+1].sum;
    node[nn].square_sum=node[2*nn].square_sum+node[2*nn+1].square_sum;
}

void update(int nn,int i,int j,int s,int e,int x,int pp=0)
{
    if(i>e || j<s)
        return;
    if(i>=s && j<=e)
    {
        if(flag==0)
        {
            node[nn].same=true;
            node[nn].prev_propagate=pp;
            node[nn].propagte=0;
            node[nn].same_val=x;
            node[nn].sum=(j-i+1)*x;
            node[nn].square_sum=(j-i+1)*x*x;
            return;
        }

        node[nn].propagte=x;

        node[nn].sum+=(j-i+1)*x;
        node[nn].square_sum+=(2*x*node[nn].sum+((j-i+1)*x*x));// prof it: (a+x)^2+(b+x)^2 =?
        return;
    }
    int mid=(i+j)/2;

    update(2*nn,i,mid,s,e,x,pp+node[nn].propagte);
    update(2*nn+1,mid+1,j,s,e,x,pp+node[nn].propagte);
}

ll query(int nn,int i,int j,int s,int e,int pp=0)
{
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {
        if(node[nn].same)
        {
            int x=pp-node[nn].prev_propagate+node[nn].propagte;
            int temp=(2*x*node[nn].sum+((j-i+1)*x*x));
            return node[nn].square_sum + x;
        }
        return node[nn].square_sum;
    }
    int mid=(i+j)/2;
    query(2*nn,i,mid,s,e,pp+node[nn].propagte);
    query(2*nn+1,mid+1,j,s,e,pp+node[nn].propagte);
}


int main()
{
    ll k,s,e,f,c=0,t,q,x;
    cin>>t;
    while(c<t)
    {
        printf("Case %d:\n",++c);
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build(1,1,n);
        for(i=0;i<q;i++)
        {
            scanf("%d",&f);
            if(f==2)
            {
                scanf("%d %d",&s,&e);
                printf("%d\n",query(1,1,n,s,e));
            }
            else if(f==1)
            {
                flag=1;
                scanf("%d %d %d",&s,&e,&x);
                update(1,1,n,s,e,x);
            }
            else
            {
                flag=2;
                scanf("%d %d %d",&s,&e,&x);
                update(1,1,n,s,e,x);
            }


        }


    }

}
/*

2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1

*/
