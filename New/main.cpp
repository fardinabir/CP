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
        node[nn].same=false;
        node[nn].propagte=0;
        node[nn].prev_propagate=0;

        cout<<i<<" - "<<j<<" node : "<<nn<<"  sum : "<<node[nn].sum<<"    sq_sum : "<<node[nn].square_sum<<endl;
        return;
    }
    int mid=(i+j)/2;

    build(2*nn,i,mid);
    build(2*nn+1,mid+1,j);

    ll xx=node[2*nn].sum+node[2*nn+1].sum;
    ll yy=node[2*nn].square_sum+node[2*nn+1].square_sum;

    cout<<i<<" - "<<j<<" node : "<<nn<<"  sum : "<<xx<<"    sq_sum : "<<yy<<endl;

    node[nn].sum=xx;
    node[nn].square_sum=yy;
}

void update(int nn,int i,int j,int s,int e,ll x,int pp)
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
            cout<<i<<" - "<<j<<" node : "<<nn<<"  sum : "<<node[nn].sum<<"    sq_sum : "<<node[nn].square_sum<<endl;
            return;
        }

        node[nn].propagte=x;

        node[nn].square_sum+=(2*x*node[nn].sum+((j-i+1)*x*x));// prof it: (a+x)^2+(b+x)^2 =?
        node[nn].sum+=(j-i+1)*x;


        cout<<i<<" - "<<j<<" node : "<<nn<<"  sum : "<<node[nn].sum<<"    sq_sum : "<<node[nn].square_sum<<endl;
        return;
    }
    int mid=(i+j)/2;

    update(2*nn,i,mid,s,e,x,pp+node[nn].propagte);
    update(2*nn+1,mid+1,j,s,e,x,pp+node[nn].propagte);

    ll xx=node[2*nn].sum+node[2*nn+1].sum;
    ll yy=node[2*nn].square_sum+node[2*nn+1].square_sum;

    cout<<i<<" - "<<j<<" node : "<<nn<<"  sum : "<<xx<<"    sq_sum : "<<yy<<endl;

    node[nn].sum=xx;
    node[nn].square_sum=yy;
}

ll query(int nn,int i,int j,int s,int e,int pp=0)
{
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {
        if(node[nn].same)
        {
            ll x=pp-node[nn].prev_propagate+node[nn].propagte;
            ll temp=(2*x*node[nn].sum+((j-i+1)*x*x));
            return node[nn].square_sum + x;
        }
        return node[nn].square_sum+(pp*(j-i+1));
    }
    int mid=(i+j)/2;
    return query(2*nn,i,mid,s,e,pp+node[nn].propagte)+query(2*nn+1,mid+1,j,s,e,pp+node[nn].propagte);
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
                update(1,1,n,s,e,x,0);
            }
            else
            {
                flag=0;
                scanf("%lld %lld %lld",&s,&e,&x);
                update(1,1,n,s,e,x,0);
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
