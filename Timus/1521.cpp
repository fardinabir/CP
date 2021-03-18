#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;
using namespace __gnu_pbds;

ll arr[1000000],fq[1000000],dp[1000000],ind[26],ind1[26],n,m;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main()
{
    ll t,i,j,k,r,c,cc,mn,mx=-1,g,s,a,d,b,l=1,li,id=1;
    string st,st1,st2;
    ordered_set sett;
    cin>>a>>b;
    for(i=1;i<=a;i++)
        sett.insert(i);
    c=0;
    ordered_set :: iterator it;
    while(a)
    {
        c=(c+b-1)%a;
        it=sett.find_by_order(c);
        cout<<*it<<" ";
        sett.erase(it);
        a--;
    }
    return 0;
}