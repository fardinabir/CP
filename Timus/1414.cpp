#include <bits/stdc++.h>
#define mxs 100005
#define ll  long long int
#define print_case printf("Case %lld: ",ts++)
using namespace std;

ll arr[100005],n,m,cnt;
vector <string> svc;
string str;

struct node
{
    bool endd;
    node *next[36];
    node()
    {
        endd=false;
        for(int i=0;i<36;i++) next[i]=NULL;
    }
} *root;

void build(string st)
{
    node *cur=root;
    for(int i=0;i<st.size();i++)
    {
        int ind=(st[i]>='0' && st[i]<='9')?st[i]-'0'+26:st[i]-'a';
        if(cur->next[ind]==NULL) cur->next[ind]=new node();
        cur=cur->next[ind];
    }
    cur->endd=true;
}

void get(node *cur,string scur)
{
    if(cur->endd && cnt<20)
    {
        cout<<"  "<<str+scur<<endl;
        cnt++;
    }
    for(int i=0;i<36;i++)
    {
        if(cur->next[i]!=NULL && cnt<20)
        {
            string x;
            x=i<26?'a'+i:'0'+(i-26);
            get(cur->next[i],scur+x);
        }
    }
}

void check(string st)
{
    cnt=0;
    node *cur=root;
    int i;
    for(i=0;i<st.size();i++)
    {
        int ind=(st[i]>='0' && st[i]<='9')?st[i]-'0'+26:st[i]-'a';
        if(cur->next[ind]!=NULL) cur=cur->next[ind];
        else break;
    }
    if(i==st.size()) get(cur,"");
}

int main()
{
    ll t,k,a,b,d,x,y,i,q,j,l,s,c,ans,mx=-1,mn=INT_MAX,ts=1;
    root=new node();
    string st;
    build("sun");
    while(cin>>st)
    {
        if(st[0]=='?')
        {
            str=st.substr(1);
            cout<<str<<endl;
            check(str);
        }
        else
        {
            build(st.substr(1));
        }
    }
    return 0;
}
/*
2
7 2
2 5 2
5 7 3
7 4
2 5 2
5 7 3
3 4 3
1 2 4
*/
