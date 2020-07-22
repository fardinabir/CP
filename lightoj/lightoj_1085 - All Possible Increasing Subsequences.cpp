/// Ki vai?? coding kamon chole?

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int arr[100005];
ll node[400005];

void update(int nn,int i,int j,int ss,int val)
{
    if(i>ss || j<ss)
        return;
    if(i==j && i==ss)
    {
        node[nn]=val;
        //cout<<i<<" -- "<<j<<" "<<node[nn]<<endl;
        return;
    }
    int mid=(i+j)/2;

    update(2*nn,i,mid,ss,val);
    update(2*nn+1,mid+1,j,ss,val);

    node[nn]=(node[2*nn]+node[2*nn+1])%mod;

    //cout<<i<<" -- "<<j<<" "<<node[nn]<<endl;
}

ll query(int nn,int i,int j,int s,int e)
{
    if(j<s || i>e)
        return 0;
    if(s<=i && j<=e)
    {
        //cout<<i<<" -- "<<j<<" "<<node[nn]<<endl;
        return node[nn];
    }


    int mid=(i+j)/2;

    ll q1,q2;
    q1=query(2*nn,i,mid,s,e);
    q2=query(2*nn+1,mid+1,j,s,e);

    //cout<<i<<" -- "<<j<<" "<<(q1+q2)%mod<<endl;
    return (q1+q2)%mod;
}

bool cmp(pair <int,int> a, pair <int,int> b)
{
    if(a.first != b.first)
        return a.first<b.first;
    return a.second>b.second;
}

int main() {
    ll i,j,k=0,n,l,cnt=0,x,s=0,t;

    cin>>t;
    vector <pair <int,int> > vc;
    while(k<t)
    {
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
            cnt=query(1,0,n,0,x-1);

            update(1,0,n,x,cnt+1);
        }
        cnt=query(1,0,n,0,n);
        printf("Case %lld: %lld\n",++k,cnt);
        vc.clear();
    }

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
