#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int prefix_table[1000005];

void make_table(string pattern)
{
    int sz,i,ind;
    sz=pattern.size();
    ind=0;
    for(i=1;i<sz;)
    {
        if(pattern[i]==pattern[ind])
        {
            prefix_table[i]=ind+1;
            ind++,i++;
        }
        else if(ind!=0)
            ind=prefix_table[ind-1];
        else
            prefix_table[i]=0,i++;
    }
}

int KMP(string st,string pattern)
{
    make_table(pattern);
    int i=0,j=0,n=st.size(),m=pattern.size();
    while(1)
    {
        if(i==n)
            return j;
        if(st[i]==pattern[j])
            i++,j++;
        else if(j!=0)
            j=prefix_table[j-1];
        else
            i++;
    }
    return j;
}

int main()
{
    string st,pattern;
    int t,id=0,sz,i,j,ans,fg=0;
    cin>>t;
    while(t--)
    {
        cin>>st;
        pattern=st;
        reverse(pattern.begin(),pattern.end());
        fg=2*st.size()-KMP(st,pattern);
        printf("Case %d: %d\n",++id,fg);
    }
    return 0;
}
/*

7
aaaaaaaaaaaaaz
abbbbaaaa
abababccbaba
xxxyxyyxyxxxxxxxyyxxxxxxxyxxxxxxyxxxyxxxxxxxyxxxxx
vpltefcfetlpvv
fjbibjeralarejbibjff
ecbgcefecgddbdbbbdbddgcefecgbcee
*/
