#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;
using namespace __gnu_pbds;

ll arr[100005],fq[100000],node[100005],ind[26],ind1[26],n,m;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;  // find_by_order() .. order_of_key()

int main()
{
    ll t,i,j,k,r,c,cc,mn,mx=-1,g,s,a,d,b,l=1,li,id=1;
    string st,st1,st2;
    cin>>n>>m;
    ordered_set sett;
    for(a=0;a<m;a++)
    {
        c=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            c+=sett.size()-sett.order_of_key(arr[i]);
            sett.insert(arr[i]);
        }
        sett.clear();
        if(c>mx)
            mx=c,mn=a+1;
    }
    cout<<mn<<endl;
    return 0;
}
