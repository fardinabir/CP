#include<bits/stdc++.h>

using namespace std;

struct st
{
    int zero,one,best;
};

st node_org[400000],node_tog[400000];

bool toggled[400000];
char ch;


void merge_node(int ind)
{
    node_org[ind].zero=node_org[ind<<1].zero+node_org[ind<<1|1 ].zero;
    node_org[ind].one=node_org[ind<<1].one+node_org[ind<<1|1].one;
    node_org[ind].best=max(node_org[ind<<1|1].best + node_org[ind<<1].zero, node_org[ind<<1].best + node_org[ind<<1|1].one);

    node_tog[ind].zero=node_tog[ind<<1].zero+node_tog[ind<<1|1].zero;
    node_tog[ind].one=node_tog[ind<<1].one+node_tog[ind<<1|1].one;
    node_tog[ind].best=max(node_tog[ind<<1|1].best + node_tog[ind<<1].zero, node_tog[ind<<1].best + node_tog[ind<<1|1].one);
}



void build(int ind,int i,int j)
{
    if(i==j)
    {
        scanf("%c",&ch);
        node_org[ind].best=1;
        if(ch=='1')
        {
            node_org[ind].zero=0;
            node_org[ind].one=1;
        }
        else
        {
            node_org[ind].zero=1;
            node_org[ind].one=0;
        }

        node_tog[ind].best=1;
        node_tog[ind].zero=!(node_org[ind].zero);
        node_tog[ind].one=!(node_org[ind].one);

        return;
    }

    int mid=(i+j)>>1;

    build(ind<<1,i,mid);
    build(ind<<1|1,mid+1,j);

    merge_node(ind);
}


void toggle(int ind,int i,int j,int s,int e)
{
    if(i>e || j<s)
        return;
    if(i>=s && j<=e)
    {
        swap(node_org[ind],node_tog[ind]);
        toggled[ind]=!toggled[ind];
        return;
    }

    int mid=(i+j)>>1;

    if(toggled[ind])
    {
        swap(node_org[ind<<1],node_tog[ind<<1]);
        toggled[ind<<1]=!toggled[ind<<1];

        swap(node_org[ind<<1|1],node_tog[ind<<1|1]);
        toggled[ind<<1|1]=!toggled[ind<<1|1];

        toggled[ind]=!toggled[ind];
    }

    toggle(ind<<1,i,mid,s,e);
    toggle(ind<<1|1,mid+1,j,s,e);

    merge_node(ind);
}

int main ()
{
    int t,i,y,k,ind=0,s=0,x,c=0,mn,n,m;
    scanf("%d %d",&n,&k);
    getchar();
    build(1,1,n);

    while(k--)
    {
        scanf("%d",&t);
        if(t)
        {
            printf("%d\n",node_org[1].best);
        }
        else
        {
            scanf("%d %d",&x,&y);
            toggle(1,1,n,x,y);
        }
    }

    return 0;
}

/*

5 5
10111
1
0 3 5
1
0 2 3
1


8 10
10100111
1


27 13
111001010110001111001111111
1
0 3 17
1
0 4 25
1
0 1 27
1
0 3 6
1
0 4 13
1
0 3 19
1


*/
