#include <bits/stdc++.h>

using namespace std;

struct point
{
    int ml,cl,mr,cr,x;
},xx,yy,path[4][4][4][2],temp;

vector <int> vct;

stack <point> st;

point visited[4][4][4][2];

void state_generator(point parents)
{
    for(int i=0,i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            if(i+j>0 && i+j<=2 && parents.x=0)
            {
                xx.ml=parents.ml-i;
                xx.mr=parents.mr+i;
                xx.cl=parents.cl-j;
                xx.cr=parents.cr+j;
                xx.x=1;
            }
            if(i+j>0 && i+j<=2 && parents.x=1)
            {
                xx.ml=parents.ml+i;
                xx.mr=parents.mr-i;
                xx.cl=parents.cl+j;
                xx.cr=parents.cr-j;
                xx.x=0;
            }
            vct.push_back(xx);
        }
    }
    vct.clear();
}

bool is_valid(point ts)
{

    if((ts.ml > 0 && ts.cl > ts.ml) || (ts.mr > 0 && ts.cr > ts.ml) || visited[ts.ml][ts.cl][ts.mr][ts.cr][ts.x])
        return false;
    if(ts.ml<0 || ts.mr<0 || ts.cl<0 || ts.cr<0 || ts.ml>3 || ts.mr>3 || ts.cl>3 || ts.cr>3)
        return false;
}

void BFS()
{
    int m1,m2,c1,c2;
    queue <point> qu;
    temp.ml=3,temp.cl=3,temp.cr=0,temp.mr=0,temp.x=0;
    visited[3][3][0][0][0]=1;

    qu.push(temp);

    while(!qu.empty())
    {
        temp=qu.front();
        qu.pop();

        state_genarator(temp);

    }
}

int main()
{
    int i,j,k,l,s=0;
    BFS();
    return 0;
}
