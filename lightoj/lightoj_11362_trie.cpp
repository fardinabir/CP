#include <bits/stdc++.h>

using namespace std;

struct node
{
    bool end_mark;
    int cnt;
    node *next[20];
    node()
    {
        cnt=0;
        end_mark=false;
        for(int i=0;i<20;i++)
            next[i]=NULL;
    }
} *root;

bool build(string st)
{
    node *cur=root;
    int sz=st.size(),v;
    for(int i=0;i<sz;i++)
    {
        v=st[i]-'0';
        if(cur->next[v]==NULL)
            cur->next[v]=new node();
        cur=cur->next[v];
        if(cur->end_mark==true)
            return false;
        cur->cnt++;
    }
    cur->end_mark=true;
    if(cur->cnt > 1)
        return false;
    return true;
}

void del(node *cur=root)
{
    for(int i=0;i<20;i++)
    {
        if(cur->next[i]!=NULL)
        {
            del(cur->next[i]);
        }
    }
    delete(cur);
}

int main()
{
    int t,id,n,i,k;
    bool flag;
    string st;
    cin>>t;
    while(t--)
    {
        root=new node();
        flag=true;
        cin>>n;
        while(n--)
        {
            cin>>st;
            if(flag)
                flag=build(st);
        }
        if(!flag)
            cout<<"NO\n";
        else
            cout<<"YES\n";
        del();
    }
}
/*

2
3
911
97625999
91125426
5
113
12340
123440
12345
98346

*/
