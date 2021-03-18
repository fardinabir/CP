#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set sett;

int find_val(int ind)
{
    int l=0,r=1e9+1,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(mid < ind + sett.order_of_key(mid+1))
            l=mid+1;
        else
            r=mid;
    }
    return l;
}

main()
{
    int n,m,k,ind;
    cin>>n>>m;
    char ch;
    for(int i=0;i<m;i++)
    {
        cin>>ch>>k;
        ind=find_val(k);
        if(ch=='L')
            cout<<ind<<endl;
        else
            sett.insert(ind);
    }
 }
/*
12 7
D 5
D 5
D 7
D 7
D 4
D 4
L 5
*/
