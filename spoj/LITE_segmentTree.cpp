#include <bits/stdc++.h>

using namespace std;

struct nn{
    int sum;
    bool toggle;
};

int arr[100005],n,xx;

nn node[400000];

void update(int ind,int i,int j,int s,int e)
{
    if(i>e || j<s)
        return;
    if(i>=s && j<=e)
    {
        node[ind].sum=(j-i+1)-node[ind].sum;
        node[ind].toggle=!node[ind].toggle;
        //cout<<i<<" -- "<<j<<" "<<node[ind].sum<<" "<<node[ind].toggle<<endl;
        return;
    }
    int mid=(i+j)/2;
    update(2*ind,i,mid,s,e);
    update(2*ind+1,mid+1,j,s,e);

    if(node[ind].toggle)
        node[ind].sum=(j-i+1)-(node[2*ind].sum+node[2*ind+1].sum);
    else
        node[ind].sum=node[2*ind].sum+node[2*ind+1].sum;

    //cout<<i<<" -- "<<j<<" "<<node[ind].sum<<" "<<node[ind].toggle<<endl;
}

int query(int ind,int i,int j,int s,int e,int prop=0)
{
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {
        //cout<<i<<" -- "<<j<<" "<<node[ind].sum<<" "<<node[ind].toggle<<" "<<prop+node[ind].toggle<<endl;
        return (prop)%2? (j-i+1)-node[ind].sum:node[ind].sum;
    }
    if(node[ind].toggle)
        prop++;
    int mid=(i+j)/2,a,b;
    a=query(2*ind,i,mid,s,e,prop);
    b=query(2*ind+1,mid+1,j,s,e,prop);
    return a+b;
}

int main()
{
    int i,j,k,l,s,m,e;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&k,&s,&e);
        if(!k)
        {
            update(1,1,n,s,e);
        }
        else
            printf("%d\n",(query(1,1,n,s,e)));
    }
}
/*
8 10
0 2 5
0 4 7
1 2 7
0 1 6
0 3 5
1 3 4
1 4 5
1 5 6
*/
