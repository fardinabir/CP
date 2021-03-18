#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;
using namespace __gnu_pbds;

ll arr[100005],fq[100000],node[400005],ind[26],ind1[26],n,m;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

void update(int ind)
{
    while(ind<=32005)
    {
        node[ind]++;
        ind+=(ind&(-ind));
    }
}

ll query(int ind)
{
    ll sum=0;
    while(ind>0)
    {
        sum+=node[ind];
        ind-=(ind&(-ind));
    }
    return sum;
}

int main()
{
    ll t,i,j,k,r,c,cc,mn,mx=-1,g,s,a,d,b,l=1,li,id=1;
    string st,st1,st2;
    cin>>n;
    n++;
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        a++;
        c=query(a);
        fq[c]++;
        update(a);
    }
    for(i=0;i<n-1;i++)
        cout<<fq[i]<<endl;
    return 0;
}
