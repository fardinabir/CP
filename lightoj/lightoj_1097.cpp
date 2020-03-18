#include<bits/stdc++.h>
#define mx 1429432
#define ll long long int
#define test_case printf("Case %d:",id++)

using namespace std;

int arr[mx+5],node[4*mx+5],n;

void build(int ind,int b,int e)
{
    if(b==e)
    {
        node[ind]= b%2? 1 : 0;
        return;
    }
    int mid=(b+e)>>1;
    build(ind<<1,b,mid);
    build(ind<<1|1,mid+1,e);
    node[ind]=node[ind<<1]+node[ind<<1|1];
}

int query(int ind,int b,int e,int k)
{
    if(b==e && k==1)
        return b;
    int mid=(b+e)>>1;
    if(node[ind<<1]>=k)
        return query(ind<<1,b,mid,k);
    return query(ind<<1|1,mid+1,e,k-node[ind<<1]);
}

void update(int ind,int b,int e,int k)
{
    if(b==e && k==1)
    {
        node[ind]=0;
        return;
    }
    int mid=(b+e)>>1;
    if(node[ind<<1]>=k)
        update(ind<<1,b,mid,k);
    else
        update(ind<<1|1,mid+1,e,k-node[ind<<1]);
    node[ind]=node[ind<<1]+node[ind<<1|1];
}

int main()
{
    int i,j,a,b,k=2,l=0,c=0,t,x,y,q,id=1,z,MX=-1;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    build(1,1,mx);
    while(k<=100000)
    {
        c=query(1,1,mx,k++);
        x=c;
        while(x<=node[1])
        {
            update(1,1,mx,x);
            x+=c;
            x--;
        }
    }
    cin>>t;
    while(t--)
    {
        test_case;
        scanf("%d",&a);
        printf(" %d\n",query(1,1,mx,a));
    }
    return 0;
}

/*
1

4 5

1 3

2 5

5 3

3 1

4 2

6 7
7 6

8 10
9 9


*/
