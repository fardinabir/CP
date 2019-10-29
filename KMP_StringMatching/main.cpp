#include <bits/stdc++.h>
#define newl "\n"
#define ll long long
const int mod = 100000007;

using namespace std;

int table[1000];

void make_table(string pattern)
{
    int sz,i,ind;
    sz=pattern.size();
    ind=0;
    for(i=1;i<sz;)
    {
        if(pattern[i]==pattern[ind])
        {
            table[i]=ind+1;
            ind++,i++;
        }
        else if(ind!=0)
        {
            ind=table[ind-1];
        }
        else
            table[i]=0,i++;
    }
}

bool kmp(string st,string pattern)
{
    make_table(pattern);
    int i=0,j=0,n=st.size(),m=pattern.size();
    while(1)
    {
        if(i==n)
            return false;
        if(st[i]==pattern[j])
        {
            i++,j++;
        }
        else if(j!=0)
            j=table[j-1];
        else
            i++;

        if(j==m)
            return true;
    }
}

int main()
{
    int t,idd=0,line=0,i,cnt=0,n,m,j,k,x;
    string st,pattern;
    cin>>st>>pattern;
    cout<<kmp(st,pattern)<<endl;
    return 0;
}
/*
aabaaaabaabaaababaabaaa aabaabaaa

ababcdababcxxababcdf abcdf

abababac ababac

abababac ababacx
*/

