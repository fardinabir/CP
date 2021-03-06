#include <bits/stdc++.h>
#define newl "\n"
#define ll long long
const int mod = 100000007;

using namespace std;

int prefix_table[1000005];

void failure_function(string pattern)
{
    int i,j,k,sz=pattern.size();
    j=0;
    for(i=1;i<sz;)
    {
        while(j && pattern[j]!=pattern[i])
            j=prefix_table[j-1];
        if(pattern[j]==pattern[i])
            j++;
        prefix_table[i]=j,i++;
    }
}
bool kmp(string st,string pattern)
{
    failure_function(pattern);
    int i=0,j=0,n=st.size(),m=pattern.size();
    while(1)
    {
        if(i==n)
            return false;
        if(st[i]==pattern[j])
            i++,j++;
        else if(j!=0)
            j=prefix_table[j-1];
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
    cin>>t;
    while(t--)
    {
        cin>>st;
        cin>>n;
        while(n--)
        {
            cin>>pattern;
            failure_function(pattern);
            if(kmp(st,pattern))
                printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
/*
2
abcdefghABCDEFGH
2
abc
abAB
xyz
1
xyz
*/

