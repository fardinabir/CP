#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000003



int solve(string st)
{
    int prefix_table[1000005];
    int i,j,k,sz=st.size();
    j=0;
    for(i=1;i<sz;)
    {
        if(st[i]==st[j])
            prefix_table[i]=j+1,i++,j++;
        else if(j)
            j=prefix_table[j-1];
        else
            prefix_table[i]=0,i++;
    }
    return (sz-prefix_table[i-1]);
}

int main()
{
    ll k;
    string st;
    while(cin>>st)
    {
        if(st==".")
            return 0;
        k=solve(st);
        if(st.size()%k==0)
            cout<<st.size()/k<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}
/*


*/
