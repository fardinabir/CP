#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set sett;
string st;

bool valid(char a,char b,char c)
{
    for(int i=0;i<st.size();i++)
    {
        if(st[i]=='A')
            st[i]=a;
        else if(st[i]=='B')
            st[i]=b;
        else
            st[i]=c;
    }
    int sum=0,j=0;
    while(j<st.size())
    {
        if(st[j]=='(')
            sum++;
        else
        {
            sum--;
            if(sum<0)
                break;
        }
    }
    if(j==st.size() && sum==0)
        return true;
    return false;
}

int find_val(int ind)
{
    int i,j,k,n,m;
    cin>>n;
    while(n--)
    {
        cin>>st;
        if(valid('(',')',')'))
            cout<<"YES\n";
        else if(valid('(','(',')'))
            cout<<"YES\n";
        else if(valid('(',')','('))
            cout<<"YES\n";
        else if(valid(')','(',')'))
            cout<<"YES\n";
        else if(valid(')',')',')'))
            cout<<"YES\n";
        else if(valid(')','(','('))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
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
