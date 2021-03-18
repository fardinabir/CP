#include <bits/stdc++.h>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

string st[105];
int vis[105][105];

void dfs(int x,int y)
{
    if(vis[x][y]==1)
        return;
    vis[x][y]=1;
    if(x>0 && st[x-1][y]=='@')
        dfs(x-1,y);
    if(x>0 && st[x-1][y+1]=='@')
        dfs(x-1,y+1);
    if(st[x][y+1]=='@')
        dfs(x,y+1);
    if(st[x+1][y+1]=='@')
        dfs(x+1,y+1);
    if(st[x+1][y]=='@')
        dfs(x+1,y);
    if(y>0 && st[x+1][y-1]=='@')
        dfs(x+1,y-1);
    if(y>0 && st[x][y-1]=='@')
        dfs(x,y-1);
    if(x>0 && y>0 && st[x-1][y-1]=='@')
        dfs(x-1,y-1);
}

int main()
{
    int m,t,i,j,k,c,n,l,id=1;
    while(1)
    {
        c=0;
        cin>>n>>m;
        if(m==0)
            return 0;
        for(i=0;i<n;i++)
            cin>>st[i];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(st[i][j]=='@' && vis[i][j]==0)
                {
                    c++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",c);
        memset(vis,0,sizeof vis);
    }
    return 0;
}
/*
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
*/
