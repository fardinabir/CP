#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int prefix_table[1000005];

void make_table(string pattern)
{
    int i,j,n,sz=pattern.size();
    j=0;
    for(i=1;i<sz;)
    {
        if(pattern[i]==pattern[j])
        {
            prefix_table[i]=j+1;
            i++,j++;
        }
        else if(j!=0)
            j=prefix_table[j-1];
        else
        {
            prefix_table[i]=0;
            i++;
        }
    }
}

int kmp(string st,string pattern)
{
    make_table(pattern);
    int szst,szpt,cnt=0;
    szst=st.size();
    szpt=pattern.size();
    int i=0,j=0;
    while(true)
    {
        if(i==szst)
            return cnt;
        if(st[i]==pattern[j])
        {
            i++,j++;
        }
        else if(j!=0)
            j=prefix_table[j-1];
        else
            i++;

        if(j==szpt)
            cnt++,j=prefix_table[j-1];
    }
    return cnt;
}

int main()
{
    string st,pattern;
    int t,id=0;
    cin>>t;
    while(t--)
    {
        cin>>st>>pattern;
        printf("Case %d: %d\n",++id,kmp(st,pattern));
    }
    return 0;
}
/*

axbyczd

abc

abcabcabcabc

abc

aabacbaabbaaz

aab

aaaaaa

aa

*/
