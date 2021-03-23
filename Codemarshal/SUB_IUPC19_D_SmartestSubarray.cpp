#include <bits/stdc++.h>
#define mxs 100005
#define ll  long long int
using namespace std;

int arr[1000005],n,m;
int node[4000005];

void init(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind]=arr[j];
        return;
    }
    int mid=(i+j)>>1;
    init(ind*2,i,mid);
    init(ind*2+1,mid+1,j);
    node[ind]=max(node[ind*2],node[ind*2+1]);
}

int queryl(int ind,int i,int j,int r,int val)
{
    if(i>r || node[ind]<val)
        return 0;
    if(i==j)
        return i;
    int mid=(i+j)>>1,x,y;
    x=queryl(ind*2+1,mid+1,j,r,val);
    if(x==0)
        return queryl(ind*2,i,mid,r,val);
    return x;
}

int queryr(int ind,int i,int j,int l,int val)
{
    if(j<l || node[ind]<val)
        return n+1;
    if(i==j)
        return i;
    int mid=(i+j)>>1,x,y;
    x=queryr(ind*2,i,mid,l,val);
    if(x==n+1)
        return queryr(ind*2+1,mid+1,j,l,val);
    return x;
}


int main()
{
    ll t,k,a,b,d,x,y,i,q,j,l,s,c,ans,mx=-1,mn=INT_MAX,ts=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        init(1,1,n);
        mx=-1;
        for(i=1;i<=n;i++)
        {
            ll left_1st,right_1st,left_2nd,right_2nd,ld,rd;
            left_1st=queryl(1,1,n,i-1,arr[i]+1);
            if(left_1st>=1)
            {
                if(left_1st>1)
                    left_2nd=queryl(1,1,n,left_1st-1,arr[i]+1);
                else
                    left_2nd=0;
                ld=arr[left_1st]-arr[i],left_1st=i-left_1st-1,left_2nd=i-left_2nd;
            }
            else
                ld=0,left_1st=i-left_1st-1,left_2nd=0;

            right_1st=queryr(1,1,n,i+1,arr[i]+1);
            if(right_1st<=n)
            {
                if(right_1st<n)
                    right_2nd=queryr(1,1,n,right_1st+1,arr[i]+1);
                else
                    right_2nd=n+1;
                rd=arr[right_1st]-arr[i],right_1st=right_1st-i-1,right_2nd=right_2nd-i;
            }
            else
                rd=0,right_1st=right_1st-i-1,right_2nd=0;

            x=(left_2nd+right_1st)*ld;
            y=(right_2nd+left_1st)*rd;
            mx=max(x,max(mx,y));
        }
        printf("Case %lld: %lld\n",ts++,mx);
    }
    return 0;
}
/*
3
16
9 1 1 1 1 1 1 7 1 1 7 1 1 1 1 13
6
6 4 3 2 7 7
6
6 7 3 2 7 2

2
6
6 4 3 2 7 7
6
6 7 3 2 7 2
*/
