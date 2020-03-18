#include <bits/stdc++.h>
#define mx 200005

using namespace std;

int arr[mx+1],node[4*mx+1],x;

void build(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind]= arr[i]? 1 : 0;
        return;
    }
    int mid=(i+j)>>1;
    build(ind<<1,i,mid);
    build(ind<<1|1,mid+1,j);
    node[ind]=node[ind<<1]+node[ind<<1|1];
}

int query(int ind,int i,int j,int k)
{
    if(i==j)
    {
        x=arr[i];
        arr[i]=node[ind]=0;
        return x;
    }
    int mid=(i+j)>>1,xx=0;
    if(node[ind<<1]>=k)
        xx=query(ind<<1,i,mid,k);
    else
        xx=query(ind<<1|1,mid+1,j,k-node[ind<<1]);
    node[ind]=node[ind<<1]+node[ind<<1|1];
    return xx;
}

void update(int ind,int i,int j,int e,int val)
{
    if(i==j && i==e)
    {
        arr[i]=val;
        node[ind]=1;
        return;
    }
    int mid=(i+j)>>1;

    if(mid>=e)
        update(ind<<1,i,mid,e,val);
    else
        update(ind<<1|1,mid+1,j,e,val);
    node[ind]=node[ind<<1]+node[ind<<1|1];
}


int main()
{
    int n,q,i,j,k,l,id=1,m,c=0,t;
    scanf("%d",&t);
    char ch;
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        build(1,1,mx);
        printf("Case %d:\n",id++);
        while(q--)
        {
            scanf(" %c %d",&ch,&k);
            if(ch=='c')
            {
                if(node[1]<k)
                    printf("none\n");
                else
                    printf("%d\n",query(1,1,mx,k));
            }
            else
                update(1,1,mx,n+1,k),n++;
        }
        memset(arr,0,sizeof arr);
    }
}

/*

2



5 5

6 5 3 2 1

c 1

c 1

a 20

c 4

c 4



2 1

18811 1991

c 1
*/
