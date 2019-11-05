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
        {
            prefix_table[i]=j+1;
            j++;
            i++;
        }
        else if(j)
            j=prefix_table[j-1];
        else
        {
            prefix_table[i]=0;
            i++;
        }
    }
}

int main()
{
    int t,n,id=1,k,m;
    string st;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>st;
        printf("Test case #%d\n",id++);
        failure_function(st);
        for(int i=1;i<st.size();i++)
        {
            k=prefix_table[i];
            m=i+1;
            if(k!=0 && m%(m-k)==0)
                cout<<m<<" "<<m/(m-k)<<"\n";
        }
        printf("\n");
    }
    return 0;
}
