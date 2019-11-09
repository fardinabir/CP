#include<bits/stdc++.h>

#define N 1000000

using namespace std;

struct st
{
    int zero,one,two,cnt;
    st()
    {
        zero=one=two=cnt=0;
    }
}node[3*N+5];

int arr[N+5],temp;

void build(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind].zero=1;
        node[ind].cnt=node[ind].one=node[ind].two=0;
        //printf("%d--%d zero=%d one=%d two=%d\n",i,j,node[ind].zero,node[ind].one,node[ind].two);
        return;
    }
    int mid=(i+j)/2,l=2*ind,r=l+1;

    build(l,i,mid);
    build(r,mid+1,j);

    node[ind].zero=node[l].zero+node[r].zero;
    node[ind].one=node[l].one+node[r].one;
    node[ind].two=node[l].two+node[r].two;
    node[ind].cnt=0;
    //printf("%d--%d zero=%d one=%d two=%d\n",i,j,node[ind].zero,node[ind].one,node[ind].two);
}

int query(int ind,int i,int j,int s,int e,int c=0)
{
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {

        if(c%3==0)
            return node[ind].zero;
        if(c%3==1)
            return node[ind].two;
        if(c%3==2)
            return node[ind].one;
    }
    int mid=(i+j)/2,l=2*ind,r=l+1;

    return query(l,i,mid,s,e,c+node[ind].cnt)+query(r,mid+1,j,s,e,c+node[ind].cnt);
}

void update(int ind,int i,int j,int s,int e)
{
    if(i>e || j<s)
        return ;
    if(i>=s && j<=e)
    {
        temp=node[ind].two;
        node[ind].two=node[ind].one;
        node[ind].one=node[ind].zero;
        node[ind].zero=temp;
        node[ind].cnt++;
        //printf("%d--%d zero=%d one=%d two=%d\n",i,j,node[ind].zero,node[ind].one,node[ind].two);
        return;
    }
    int mid=(i+j)/2,l=2*ind,r=l+1;

    update(l,i,mid,s,e);
    update(r,mid+1,j,s,e);

    node[ind].zero=node[l].zero+node[r].zero;
    node[ind].one=node[l].one+node[r].one;
    node[ind].two=node[l].two+node[r].two;

    int xx=node[ind].cnt%3;
    while(xx--)
    {
        int x=node[ind].zero;
        node[ind].zero=node[ind].two;
        node[ind].two=node[ind].one;
        node[ind].one=x;
    }
    //printf("%d--%d zero=%d one=%d two=%d\n",i,j,node[ind].zero,node[ind].one,node[ind].two);
}

int main()
{
    string st;
    int t,id=1,sz,m,n,i,j,a;
    scanf ("%d", &t);
    while (t--) {
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",id++);
        build(1,1,n);
        while(m--)
        {
            scanf("%d %d %d",&a,&i,&j);
            if(a==0)
                update(1,1,n,i+1,j+1);
            else
                printf("%d\n",query(1,1,n,i+1,j+1));
        }
    }
    return 0;
}
/*



    2

    10 9

    0 0 9

    0 3 7

    0 1 4

    1 1 7

    0 2 2

    1 2 4

    1 8 8

    0 5 8

    1 6 9




    10 9

    0 0 9

    0 3 7

    0 1 4

    1 1 7

    0 2 2

    1 2 4

    1 8 8

    0 5 8

    1 6 9

    */
