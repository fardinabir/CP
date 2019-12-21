#include <bits/stdc++.h>

using namespace std;

pair <int,int> arr[100005];
int inp[100005];
vector <int> node[400005];

void build(int ind,int i,int j)
{
    if(i==j)
    {
        node[ind].push_back(arr[i].second);
        return;
    }

    int mid=(i+j)/2;
    build(2*ind,i,mid);
    build(2*ind+1,mid+1,j);

    merge(node[2*ind].begin(),node[2*ind].end(),node[2*ind+1].begin(),node[2*ind+1].end(),back_inserter(node[ind]));
}

int query(int ind,int i,int j,int s,int e,int k)
{
    if(i==j)
        return node[ind][0];
    int mid=(i+j)/2,r;

    r=upper_bound(node[2*ind].begin(),node[2*ind].end(),e)-lower_bound(node[2*ind].begin(),node[2*ind].end(),s);

    if(r>=k)
        return query(2*ind,i,mid,s,e,k);
    else
        return query(2*ind+1,mid+1,j,s,e,k-r);
}

int main()
{
    int i,j,k,n,m,l,r;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i].first;
        arr[i].second=i;
        inp[i]=arr[i].first;
    }

    sort(arr+1,arr+n+1);

    build(1,1,n);

    while(m--)
    {
        cin>>l>>r>>k;
        j=query(1,1,n,l,r,k);
        cout<<inp[j]<<endl;
    }

}
