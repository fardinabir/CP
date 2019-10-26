#include<bits/stdc++.h>

using namespace std;

int main() {
	int t2 = 1, t3 = 1, t5 = 1,k, tmp, i,j,m,n,n3,n5,x;
	string st,stemp;
	map <pair<string,int>,set<int> > mp_col;
	vector < string > vc[10001];
	bool flag;
	set <int> :: iterator it,it2;
    while(cin>>n>>m)
    {
        getchar();
        for(i=0;i<n;i++)
        {
            getline(cin,st);
            istringstream ss(st);
            for(j=0;j<m;j++)
            {
                getline(ss,stemp,',');
                vc[i].push_back(stemp);
                if(!flag && !mp_col[{stemp,j}].empty())
                {
                    it=mp_col[{stemp,j}].begin();
                    while(it!=mp_col[{stemp,j}].end())
                    {
                        x=*it;
                        for(k=0;k<j;k++)
                        {
                            if(vc[x][k]==vc[i][k])
                            {
                                printf("NO\n%d %d\n%d %d\n",x+1,i+1,min(j,k)+1,max(j,k)+1);
                                flag=true;
                            }
                        }
                        it++;
                    }
                }
                mp_col[{stemp,j}].insert(i);
            }
        }
        mp_col.clear();
        for(i=0;i<n;i++)
            vc[i].clear();

        if(!flag)
        {
            printf("YES\n");
        }
        else
            flag=false;
    }
    return 0;
}
