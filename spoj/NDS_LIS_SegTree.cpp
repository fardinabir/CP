#include<bits/stdc++.h>

using namespace std;

pair <int,int> arr[1000005];
int node[4000005],n,length;

bool cmp(pair <int,int> a,pair <int,int> b)
{
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

int query(int ind,int i,int j,int s,int e)
{
    if(s>j || i>e)
        return 0;
    if(i>=s && j<=e)
    {
        return node[ind];
    }

    int mid=(i+j)>>1;

    return max(query(ind<<1,i,mid,s,e),query(ind<<1|1,mid+1,j,s,e));
}

void update(int ind,int i,int j,int e,int val)
{
    if(j<e || i>e)
        return;
    if(i==j && i==e)
    {
        node[ind]=val;
        return;
    }

    int mid=(i+j)>>1;

    update(ind<<1,i,mid,e,val);
    update(ind<<1|1,mid+1,j,e,val);

    node[ind]=max(node[ind<<1],node[ind<<1|1]);
}

int main ()
{
    int t,i,y,k,ind=0,s=0,c=0,mn;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>k;
            arr[i]={k,i+1};
        }
        sort(arr,arr+n,cmp);
        cin>>length;
        if(length==0)
        {
            cout<<-1<<endl;
            continue;
        }
        c=0,mn=INT_MAX;
        for(i=0;i<n;i++)
        {
            s=query(1,1,n,1,arr[i].second-1);  // To check the length of IS before that range
            s++; // new length of IS
            if(s>=length)
            {
                mn=min(mn,arr[i].first);
            }
            update(1,1,n,arr[i].second,s);
        }
        if(mn==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<mn<<endl;

        memset(node,0,16*n);
    }
    return 0;
}
