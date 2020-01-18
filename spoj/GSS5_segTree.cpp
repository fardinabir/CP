#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct st
{
    ll Left,Right,Best,Total;
    st()
    {
        Left=Right=Best=Total=0;
    }
}node[400005],xval,tl,tc,tr;

ll arr[100005],n,tm_L,tm_R,tm_U;

st merge_two_node(st &left,st &right)
{
    st temp_node;
    temp_node.Total=left.Total+right.Total;

    tm_L=max(left.Total,left.Total+right.Left);
    tm_R=max(right.Total,right.Total+left.Right);
    tm_U=max(temp_node.Total,left.Right+right.Left);

    temp_node.Left=max(left.Left,tm_L);
    temp_node.Right=max(right.Right,tm_R);
    temp_node.Best=max(tm_U,max(tm_L,max(tm_R,max(left.Best,right.Best))));


    return temp_node;
}

void build(ll ind,ll i,ll j)
{
    if(i==j)
    {
        node[ind].Left=node[ind].Right=node[ind].Best=node[ind].Total=arr[i];
        return;
    }
    ll mid=(i+j)/2,tm_L,tm_R,tm_U;
    build(2*ind,i,mid);
    build(2*ind+1,mid+1,j);

    node[ind]=merge_two_node(node[2*ind],node[2*ind+1]);
}

ll query_sum(ll ind,ll i,ll j,ll s,ll e)
{
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
        return node[ind].Total;

    ll mid=(i+j)/2;
    return query_sum(2*ind,i,mid,s,e)+query_sum(2*ind+1,mid+1,j,s,e);
}


st query(ll ind,ll i,ll j,ll s,ll e)
{
    ll f1=0,f2=0;
    st tempval1,tempval2,tempval3;
    if(j<s || i>e)
        return xval;
    if(i>=s && j<=e)
        return node[ind];
    ll mid=(i+j)/2;
    tempval1=query(2*ind,i,mid,s,e);
    f1=1;

    tempval2=query(2*ind+1,mid+1,j,s,e);
    f2=1;

    if(tempval1.Total!=-INT_MAX && tempval2.Total!=-INT_MAX)
    {
        tempval3=merge_two_node(tempval1,tempval2);
        return tempval3;
    }
    if(tempval1.Total!=-INT_MAX)
        return tempval1;
    return tempval2;
}

int main()
{
    ll i,j,k,a,b,c,cnt=0,l,t,x1,x2,y1,y2;
    cin>>t;
    while(t--)
    {
        xval.Left=xval.Right=xval.Best=xval.Total=-INT_MAX;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        build(1,1,n);

        scanf("%lld",&k);
        while(k--)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);

            ll mx=-INT_MAX,md=0;
            if(x2<=y1)
            {
                tl=query(1,1,n,x1,x2-1);
                tc=query(1,1,n,x2,y1);
                tr=query(1,1,n,y1+1,y2);

                if(x1==x2)
                    tl.Right=0;
                if(y1==y2)
                    tr.Left=0;
                mx=max(mx,tl.Right+tc.Total+tr.Left);
                mx=max(mx,tl.Right+tc.Left);
                mx=max(mx,tc.Right+tr.Left);
                mx=max(mx,tc.Best);
            }

            else
            {
                tl=query(1,1,n,x1,y1);
                tr=query(1,1,n,x2,y2);

                if(y1+2<=x2)
                    md=query_sum(1,1,n,y1+1,x2-1);

                mx=tl.Right+tr.Left+md;
            }

            printf("%lld\n",mx);
        }
    }

    return 0;
}
