/// uva 439, knights move

#include <bits/stdc++.h>

using namespace std;

int start_col,start_row,end_col,end_row,board[8][8],cost[8][8];
int fx[8]={2,1,-1,-2,-2,-1,1,2};
int fy[8]={1,2,2,1,-1,-2,-2,-1};

pair < int, int > pt;

int bfs(int xx,int yy)
{
    queue < pair < int, int > > qu;
    qu.push({xx,yy});
    board[xx][yy]=1;
    while(!qu.empty())
    {
        pt=qu.front();
        qu.pop();
        int x=pt.first,y=pt.second;

        if(x==end_row && y==end_col)
            return cost[x][y];

        for(int i=0;i<8;i++)
        {
            if(x+fx[i]<8 && y+fy[i]<8 && x+fx[i]>=0 && y+fy[i]>=0 && !board[x+fx[i]][fy[i]+y])
            {
                board[x+fx[i]][y+fy[i]]=true;
                cost[x+fx[i]][y+fy[i]]=cost[x][y]+1;
                qu.push({x+fx[i],y+fy[i]});
            }
        }
    }
}



int main()
{
    int i,j,k,cnt;
    string s1,s2;
    while(cin>>s1>>s2)
    {
        start_col=s1[0]-'a';
        start_row=s1[1]-49;
        end_col=s2[0]-'a';
        end_row=s2[1]-49;

        cnt=bfs(start_row,start_col);
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<cnt<<" knight moves."<<endl;
        memset(board,0,sizeof(board));
        memset(cost,0,sizeof(board));
    }
    return 0;
}
/*

e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

*/
