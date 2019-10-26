#include<bits/stdc++.h>

using namespace std;

map <set<int>,int> smap;
map <int,set<int> > valmap;

int mapping(set <int> sett)
{
    int x;
    if(smap[sett])
        return smap[sett];
    x=smap.size();
    valmap[x]=sett;
    smap[sett]=x;
    return x;
}

int main()
{
	int t,k, tmp, i=1,j,l,m,n,x1,x2;
	scanf("%d",&n);
	string st,stt;
	int set1,set2,set3;
    vector <string> vc1,vc2,vc3;
    set <int> setint;
	set <string> ::  iterator it;
	while(n--)
    {
        scanf("%d",&m);
        stack <int > stck;
        while(m--)
        {
            cin>>st;
            if(st=="PUSH")
            {
                stck.push(mapping(set<int>()));
            }
            else if(st=="DUP")
            {
                stck.push(stck.top());
            }
            else if(st=="ADD")
            {
                set1=stck.top();
                stck.pop();
                set2=stck.top();
                stck.pop();
                setint=valmap[set2];
                setint.insert(set1);
                stck.push(mapping(setint));
            }
            else if(st=="UNION")
            {
                set1=stck.top();
                stck.pop();
                set2=stck.top();
                stck.pop();
                set_union(valmap[set1].begin(),valmap[set1].end(),valmap[set2].begin(),valmap[set2].end(),inserter(valmap[set3], valmap[set3].begin() ));
                stck.push(mapping(valmap[set3]));
                valmap[set3].clear();
            }
            else if(st=="INTERSECT")
            {
                set1=stck.top();
                stck.pop();
                set2=stck.top();
                stck.pop();
                set_intersection(valmap[set1].begin(),valmap[set1].end(),valmap[set2].begin(),valmap[set2].end(),inserter(valmap[set3], valmap[set3].begin() ));
                stck.push(mapping(valmap[set3]));
                valmap[set3].clear();
            }
            x1=stck.top();
            printf("%d\n",valmap[x1].size());
        }
        printf("***\n");
    }
    return 0;
}
/*

2
9
PUSH
DUP
ADD
PUSH
ADD
DUP
ADD
DUP
UNION
5
PUSH
PUSH
ADD
PUSH
INTERSECT
*/
