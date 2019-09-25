#include<bits/stdc++.h>

using namespace std;

vector <int> vc[50];
map<int,int> mp;
int n;

void print()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<":";
        for(int j=1;j<vc[i].size();j++)
            cout<<" "<<vc[i][j];
        cout<<endl;
    }
}

int main()
{
	int t,k, tmp, i,j,l,m,x1,x2;
	cin>>n;

	string st,stt,cmd,type;
	vector <int> :: iterator it,itt;
	for(i=0;i<n;i++)
    {
        vc[i].push_back(-1);
        vc[i].push_back(i);
        mp[i]=i;
    }
    getchar();
	while(getline(cin,st))
    {
        stringstream ss(st);
        ss>>cmd;
        if(cmd=="quit")
        {
            break;
        }
        ss>>x1;
        ss>>type;
        ss>>x2;
        if(mp[x1]==mp[x2])
        {
            continue;
        }

        if(cmd=="move")
        {
            j=mp[x1];
            it=vc[j].end()-1;
            while(*it!=x1)
            {
                vc[*it].push_back(*it);
                mp[*it]=*it;
                vc[j].erase(vc[j].end()-1);
                *it--;
            }
            vc[j].erase(vc[j].end()-1);
            if(type=="onto")
            {
                j=mp[x2];
                it=vc[j].end()-1;
                while(*it!=x2)
                {
                    vc[*it].push_back(*it);
                    mp[*it]=*it;
                    vc[j].erase(vc[j].end()-1);
                    *it--;
                }
                vc[j].push_back(x1);
            }
            else
            {
                vc[mp[x2]].push_back(x1);
            }
            mp[x1]=mp[x2];
        }
        else
        {
            if(type=="onto")
            {
                j=mp[x2];
                it=vc[j].end()-1;
                while(*it!=x2)
                {
                    vc[*it].push_back(*it);
                    mp[*it]=*it;
                    vc[j].erase(vc[j].end()-1);
                    *it--;
                }
                l=mp[x1];
                itt=find(vc[l].begin(),vc[l].end(),x1);
                vc[j].insert(it+1,itt,vc[l].end());
                vc[l].erase(itt,vc[l].end());
            }
            else
            {
                j=mp[x2];
                l=mp[x1];
                itt=find(vc[l].begin(),vc[l].end(),x1);
                vc[j].insert(vc[j].end(),itt,vc[l].end());
                vc[l].erase(itt,vc[l].end());
            }
            for(itt=vc[j].begin();itt!=vc[j].end();itt++)
            {
                mp[*itt]=j;
            }
            mp[x1]=mp[x2];
        }
    }
    print();
    return 0;
}
/*
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit
*/
