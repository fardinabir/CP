/// spoj dquery using segment tree

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define sz 100005

using namespace std;

int arr[sz],node[4*sz],last[sz*10];

int query(int ind,int i,int j,int s,int e)
{
    if(i>e || j<s)
        return 0;
    if(i>=s && j<=e)
    {
        return node[ind];
    }
    int mid=(i+j)/2,l,r;
    l=query(2*ind,i,mid,s,e);
    r=query(2*ind+1,mid+1,j,s,e);
    return l+r;
}

void update(int ind,int i,int j,int s)
{
    if(s>j || i>s)
        return;
    if(i==j && j==s)
    {
        node[ind]= !node[ind];
        return;
    }
    int mid=(i+j)/2;

    update(2*ind,i,mid,s);
    update(2*ind+1,mid+1,j,s);

    node[ind]=node[2*ind]+node[2*ind+1];
}



bool cmp(pair < pair <int,int> ,pair <int,int>>  a,pair < pair <int,int> , pair <int,int> >  b)
{
    return a.first.second<b.first.second;
}

bool cmp_ind(pair < pair <int,int> ,pair <int,int>>  a,pair < pair <int,int> , pair <int,int> >  b)
{
    return a.second.first<b.second.first;
}

int main() {
    int i,j,l,r,x,s,k,n,cnt=0,t=0,cs=1;
    vector <pair < pair <int,int> , pair <int,int> > > vcp;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    cin>>k;
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&l,&r);
        vcp.push_back({{l,r},{i,0}});
    }
    sort(vcp.begin(),vcp.end(),cmp);

    j=0;
    for(i=1;i<=n;i++)
    {
        if(last[arr[i]])
        {
            s=last[arr[i]];
            update(1,1,n,s);
        }

        last[arr[i]]=i;
        update(1,1,n,i);

        while(i==vcp[j].first.second)
        {
            l=vcp[j].first.first,r=vcp[j].first.second;
            k=query(1,1,n,l,r);
            vcp[j].second.second=k;
            j++;
        }
    }

    sort(vcp.begin(),vcp.end(),cmp_ind);

    for(i=0;i<vcp.size();i++)
    {
        printf("%d\n",vcp[i].second.second);
    }
    vcp.clear();
    memset(node,0,sizeof node);
    memset(last,0,sizeof last);

    return 0;
}
/*

what's here? man? look up...!

2


8 5

1 1 1 2 3 5 1 2

1 8

2 3

3 6

4 5

4 8



8 5

1 1 1 2 3 5 1 2

1 8

2 3

3 6

4 5

4 8
*/
