#include<bits/stdc++.h>

#define N 1000000

using namespace std;

map <string,vector <string> >  mp_relation;
map <string,vector <string> > :: iterator it;
unordered_map <string,bool> unmap;

bool check(string n)
{
    if(unmap[n])
        return false;
    unmap[n]=true;
    for(int i=0;i<mp_relation[n].size();i++)
    {
        if(!check(mp_relation[n][i]))
            return false;
    }
    unmap[n]=false;
    return true;
}

int main()
{
    int t,id=1,m,n,i,j,val,fg;
    string  st1,st2;
    scanf ("%d", &t);

    while (t--)
    {
        val=1;
        fg=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>st1>>st2;

            mp_relation[st2].push_back(st1);
        }
        printf("Case %d: ",id++);
        for(it = mp_relation.begin();it!=mp_relation.end(); it++ )
        {
            if(!check(it->first))
            {
                fg=1;
                printf("No\n");
                break;
            }
            unmap.clear();
        }
        if(!fg)
            printf("Yes\n");

        mp_relation.clear();
        unmap.clear();
    }
    return 0;
}
