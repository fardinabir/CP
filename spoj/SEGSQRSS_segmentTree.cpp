/// spoj SEGSQRSS, unsolved

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,i,j,k,flag;
ll arr[100005];

struct st{
    ll sum,square_sum,propagte,same_val,prev_propagate;
    bool same;
}node[400005];

void build(int nn,int i,int j)
{
    if(i==j)
    {
        node[nn].sum=arr[i];
        node[nn].square_sum=arr[i]*arr[i];
        return;
    }
    int mid=(i+j)/2;
    build(2*nn,i,mid);
    build(2*nn+1,mid+1,j);

    node[nn].sum=node[2*nn].sum+node[2*nn+1].sum;
    node[nn].square_sum=node[2*nn].square_sum+node[2*nn+1].square_sum;
}

void update(int nn,int i,int j,int s,int e,ll x)
{
    if(j<s || i>e)
        return;
    if(i>=s && j<=e)
    {
        if(!flag)
        {
            node[nn].sum=(j-i+1)*x;
            node[nn].square_sum=(j-i+1)*x*x;
            return;
        }
        node[nn].square_sum+=(2*x*node[nn].sum+((j-i+1)*x*x));// prof it: (a+x)^2+(b+x)^2 =?
        node[nn].sum+=(j-i+1)*x;
        return;
    }
    int mid=(i+j)/2;
    update(2*nn,i,mid,s,e,x);
    update(2*nn+1,mid+1,j,s,e,x);

    node[nn].sum=node[2*nn].sum+node[2*nn+1].sum;
    node[nn].square_sum=node[2*nn].square_sum+node[2*nn+1].square_sum;
}

ll query(int nn,int i,int j,int s,int e)
{
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {
        return node[nn].square_sum;
    }
    int mid=(i+j)/2;
    return query(2*nn,i,mid,s,e)+query(2*nn+1,mid+1,j,s,e);
}

int main()
{
    ll k,s,e,f,c=0,t,q,x;
    cin>>t;
    while(c<t)
    {
        printf("Case %lld:\n",++c);
        scanf("%lld %lld",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        build(1,1,n);
        for(i=0;i<q;i++)
        {
            scanf("%lld",&f);
            if(f==2)
            {
                scanf("%lld %lld",&s,&e);
                printf("%lld\n",query(1,1,n,s,e));
            }
            else if(f==1)
            {
                flag=1;
                scanf("%lld %lld %lld",&s,&e,&x);
                update(1,1,n,s,e,x);
            }
            else
            {
                flag=0;
                scanf("%lld %lld %lld",&s,&e,&x);
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


1
3 6
1 2 3
2 1 3
0 1 3 1
2 1 1
2 2 2
2 3 3
2 1 3
1 2 2 1
2 1 1
2 2 2
2 3 3
2 1 3
1 1 3 1
2 1 3

*/
