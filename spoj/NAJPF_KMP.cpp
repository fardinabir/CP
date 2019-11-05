#include <bits/stdc++.h>

using namespace std;

int prefix_table[1000005];

void failure_function(string st)
{
    int i,j,k,n,c,sz=st.size();
    j=0;
    for(i=1;i<sz;)
    {
        if(st[i]==st[j])
            prefix_table[i]=j+1,j++,i++;
        else if(j)
            j=prefix_table[j-1];
        else
            prefix_table[i]=0,i++;
    }
}

void kmp(string st,string pattern)
{
    int i,j,flag=0,szst=st.size(),szpt=pattern.size();
    vector <int> vc;
    i=j=0;
    while(1)
    {
        if(i==szst)
            break;

        if(st[i]==pattern[j])
            i++,j++;
        else if(j)
            j=prefix_table[j-1];
        else
            i++;

        if(j==szpt)
        {
            vc.push_back(i-j+1);
        }
    }
    if(vc.empty())
        printf("Not Found\n");
    else
    {
        printf("%d\n",vc.size());
        for(i=0;i<vc.size();i++)
            printf("%d ",vc[i]);
        printf("\n");
    }
}

int main()
{
    int t,n,id=1,k,m;
    string st,pattern;
    cin>>t;
    while(t--)
    {
        if(id!=1)
            printf("\n");

        cin>>st>>pattern;
        //printf("Test case #%d\n",id++);
        failure_function(pattern);
        kmp(st,pattern);
        id++;
    }
    return 0;
}
