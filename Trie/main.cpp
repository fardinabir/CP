#include <bits/stdc++.h>

using namespace std;

struct node
{
    bool endd;
    int cnt;
    node* next_chart[27];
    node()
    {
        endd=false;
        cnt=0;
        for(int i=0;i<27;i++)
        {
            next_chart[i]=NULL;
        }
    }
} *root;

void build(string st)
{
    node *cur=root;
    int sz=st.size(),ind;
    for(int i=0;i<sz;i++)
    {
        ind=st[i]-'a';
        cur->cnt++;
        if(cur->next_chart[ind]==NULL)
            cur->next_chart[ind]=new node();
        cur=cur->next_chart[ind];
    }
    cur->endd=true;
}

bool find_st(string st)
{
    node *cur=root;
    int sz=st.size(),ind;
    for(int i=0;i<sz;i++)
    {
        ind=st[i]-'a';
        if(cur->next_chart[ind]!=NULL)
            cur=cur->next_chart[ind];
        else
            return false;
    }
    return cur->endd;
}

bool delete_word(string st,node* cur=root,int ind=0)
{
    if(ind==st.size())
    {
        if(cur->endd==false)
            return false;
        cur->endd=false;
        return true;
    }
    int v=st[ind]-'a';
    if(cur->next_chart[v]!=NULL)
    {
        if(delete_word(st,cur->next_chart[v],ind+1))
        {
            if(cur->cnt==1)
                delete(cur);
            return true;
        }
    }
    return false;
}

void delete_trie(node *cur)
{
    for(int i=0;i<27;i++)
    {
        if(cur->next_chart[i]!=NULL)
            delete_trie(cur->next_chart[i]);
    }
    delete(cur);
}

int main()
{
    int n,t,q;
    string st;
    root=new node();

    cout<<"Enter the number of query:"<<endl;
    cin>>q;
    cout<<"Submit each query: 'query_type' 'word' (query type: 0 for add,1 for search,2 for delete):"<<endl;
    while(q--)
    {
        cin>>t>>st;
        if(t==0)
            build(st);
        else if(t==1)
        {
            if(find_st(st))
                cout<<"Found..."<<endl;
            else
                cout<<"Not Found !!!"<<endl;
        }
        else if(t==2)
        {
            if(!delete_word(st))
                cout<<"Not Found !!!"<<endl;
            else
                cout<<"Deleted Successfully !!!"<<endl;
        }
    }

    delete_trie(root);
    return 0;
}
