#include<bits/stdc++.h>
#define mx 200005
#define ll long long int
#define test_case printf("Case %d:",id++)

using namespace std;

ll arr[mx+1],node[mx+1],n;

vector <pair <ll,ll> > vc;

void update(ll ind,ll val)
{
    for(ll i=ind;i<=n;i+=(i&-i))
        node[i]+=val;
}

ll query(ll ind)
{
    ll ret=0;
    for(ll i=ind;i>0;i-=(i&-i))
        ret+=node[i];
    return ret;
}


int main()
{
    ll i,j,a,b,k=0,l,c=0,t,x,y,q,id=1,z,MX=-1;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        a+=b;
        n=a;
        while(a--)
        {
            scanf("%lld %lld",&x,&y);
            vc.push_back({x,y});
        }
        sort(vc.begin(),vc.end());
        c=0;
        for(i=vc.size()-1;i>=0;i--)
        {
            k=vc[i].second;
            c+=query(k);
            update(k,1);
        }
        test_case;
        printf(" %lld\n",c);
        memset(node,0,sizeof node);
        vc.clear();
    }
    return 0;
}

/*
1

4 5

1 3

2 5

5 3

3 1

4 2

6 7
7 6

8 10
9 9


*/
