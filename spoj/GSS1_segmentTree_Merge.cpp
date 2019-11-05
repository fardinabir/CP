#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct st
{
    int Left,Right,Best,Total;
    st()
    {
        Left=Right=Best=Total=0;
    }
}node[400005],xval,z;

int arr[100005],n,tm_L,tm_R,tm_U;

st merge_two_node(st &left,st &right)
{
    st temp_node;temp_node.Total=left.Total+right.Total;

    tm_L=max(left.Total,left.Total+right.Left);
    tm_R=max(right.Total,right.Total+left.Right);
    tm_U=max(temp_node.Total,left.Right+right.Left);

    temp_node.Left=max(left.Left,tm_L);
    temp_node.Right=max(right.Right,tm_R);
    temp_node.Best=max(tm_U,max(tm_L,max(tm_R,max(left.Best,right.Best))));

    return temp_node;
}

void build(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind].Left=node[ind].Right=node[ind].Best=node[ind].Total=arr[i];
        return;
    }
    int mid=(i+j)/2,tm_L,tm_R,tm_U;
    build(2*ind,i,mid);
    build(2*ind+1,mid+1,j);

    node[ind]=merge_two_node(node[2*ind],node[2*ind+1]);
}



st query(int ind,int i,int j,int s,int e)
{
    int f1=0,f2=0;
    st tempval1,tempval2,tempval3;
    if(j<s || i>e)
        return xval;
    if(i>=s && j<=e)
        return node[ind];
    int mid=(i+j)/2;
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
    int i,j,k,t,a,b,c,cnt=0,l;
    xval.Left=xval.Right=xval.Best=xval.Total=-INT_MAX;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,1,n);

    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d",&a,&b);
        z=query(1,1,n,a,b);
        cout<<max(z.Best,max(z.Total,max(z.Left,z.Right)))<<endl;
    }
    return 0;
}
/*
10
10 -1 -1 -1 -1 10 10 10 10 10
1
1 6

10
10 -1 -1 3 -1 10 10 10 10 10
1
1 6

*/
