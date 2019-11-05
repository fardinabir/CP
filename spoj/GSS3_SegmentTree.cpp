#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int Left,Right,Best,Total;
    Node()
    {
        Left=Right=Best=Total=0;
    }
}node[400005],xval,z;

int arr[100005],n,tm_L,tm_R,tm_U;

Node merge_two_node(Node &left,Node &right)
{
    Node temp_node;
    temp_node.Total=left.Total+right.Total;

    tm_L=max(left.Total, left.Total + right.Left); // If we make prefix extended to right node
    tm_R=max(right.Total, right.Total + left.Right); // If we make suffix extended to left node
    tm_U=max(temp_node.Total, left.Right + right.Left); // The Best can be a middle part of two merged range

    temp_node.Left=max(left.Left, tm_L); // best prefix of root node can be the prefix of the left node
    temp_node.Right=max(right.Right, tm_R); // same for suffix
    temp_node.Best=max(tm_U, max(tm_L, max(tm_R, max(left.Best, right.Best)))); // Best among all

    return temp_node;
}

void build(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind].Left=node[ind].Right=node[ind].Best=node[ind].Total=arr[i];
        return;
    }
    int mid=(i+j)/2,l=2*ind,r=l+1;
    build(l,i,mid);
    build(r,mid+1,j);

    node[ind]=merge_two_node(node[l],node[r]);
}

void update(int ind,int i,int j,int s,int val)
{
    if(i>s || j<s)
        return;
    if(i==j && i==s)
    {
        node[ind].Left=node[ind].Right=node[ind].Best=node[ind].Total=val;
        return;
    }
    int mid=(i+j)/2,l=2*ind,r=l+1;
    update(l,i,mid,s,val);
    update(r,mid+1,j,s,val);

    node[ind]=merge_two_node(node[l],node[r]);
}

Node query(int ind,int i,int j,int s,int e)
{
    int f1=0,f2=0;
    Node tempval1,tempval2,tempval3;
    if(j<s || i>e)
        return xval;  // returning a garbage Node data for invalid range
    if(i>=s && j<=e)
        return node[ind];
    int mid=(i+j)/2,l=2*ind,r=l+1;

    tempval1=query(l,i,mid,s,e);
    tempval2=query(r,mid+1,j,s,e);

    if(tempval1.Total!=-INT_MAX && tempval2.Total!=-INT_MAX) // If we get valid return from both left and right
    {
        tempval3=merge_two_node(tempval1,tempval2);
        return tempval3;
    }
    if(tempval1.Total!=-INT_MAX) // If we get return form left node
        return tempval1;
    return tempval2;
}

int main()
{
    int i,j,k,t,a,b,c,cnt=0,l;
    xval.Left=xval.Right=xval.Best=xval.Total=-INT_MAX; // making a garbage node
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build(1,1,n);

    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d %d",&j,&a,&b);
        if(!j)
            update(1,1,n,a,b);
        else
        {
            z=query(1,1,n,a,b);
            cout<<max(z.Best,max(z.Total,max(z.Left,z.Right)))<<endl;
        }

    }
    return 0;
}
/*
Inputs for testing

10
10 -1 -1 -1 -1 10 10 10 10 10
1
1 6

10
10 -1 -1 3 -1 10 10 10 10 10
1
1 6

*/
