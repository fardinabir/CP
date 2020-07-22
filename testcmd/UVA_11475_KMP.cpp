#include <bits/stdc++.h>

using namespace std;

int prefix_table[1000005];

void failure(string pattern)
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

int kmp_pal(string st,string stt)
{
    int i,j,k,sz_st=st.size();
    i=0,j=0;
    while(1)
    {
        if(i==sz_st)
            break;
        if(st[i]==stt[j])
            i++,j++;
        else if(j)
            j=prefix_table[j-1];
        else
            i++;
    }
    return j;
}

int main()
{
    int t,n,id=1,k,m;
    string st,stt;
    //cin>>t;
    while(cin>>st)
    {
        string stt=st;
        reverse(stt.begin(),stt.end());
        failure(stt);
        k=kmp_pal(st,stt);

        stt=st.substr(0,st.size()-k);
        reverse(stt.begin(),stt.end());
        st+=stt;
        cout<<st<<endl;
    }
    return 0;
}
/*

aaaabaabaaabaa

*/
