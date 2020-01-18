/// Ki vai?? coding kamon chole?

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

ll node[400005];


ll query(int ind,int i,int j,int endd)
{
    if(i>endd)
        return 0;
    if(j<=endd)
    {
        return node[ind];
    }
    int mid=(i+j)/2;

    return max(query(2*ind,i,mid,endd),query(2*ind+1,mid+1,j,endd));
}

void update(int ind,int i,int j,int endd,ll val)
{
    if(i>endd || j<endd)
        return;
    if(i==j && j==endd)
    {
        node[ind]=val;
        return;
    }

    int mid=(i+j)/2;

    update(2*ind,i,mid,endd,val);
    update(2*ind+1,mid+1,j,endd,val);

    node[ind]=max(node[2*ind],node[2*ind+1]);
}

bool cmp(pair <int,int> a, pair <int,int> b)
{
    if(a.first != b.first)
        return a.first<b.first;
    return a.second>b.second;
}

int main() {
    ll i,j,k=0,n,l,cnt=0,x,s=0,t;

    vector <pair <int,int> > vc;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&j);
        vc.push_back({j,i+1});
    }

    sort(vc.begin(),vc.end(),cmp);
    memset(node,0,sizeof(node));

    for(i=0;i<n;i++)
    {
        x=vc[i].second;
        cnt=query(1,1,n,x-1);

        update(1,1,n,x,cnt+vc[i].first);
    }
    cnt=query(1,1,n,n);
    cout<<cnt<<endl;
    vc.clear();


    return 0;
}
/*

what's here? man? look up...!

3

3

1 1 2

5

1 2 1000 1000 1001

3

1 10 11
*/
