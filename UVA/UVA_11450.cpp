#include<bits/stdc++.h>

using namespace std;

int mem[25][250],m,c;
int arr[25][25];

int calc(int val,int i)
{
    if(val>m)
        return -INT_MAX;
    if(i==c)
        return val;
    int &mx=mem[i][val];

    if(mx!=-1)
        return mx;

    for(int j=1;j<=arr[i][0];j++)
    {
        mx=max(mx,calc(val+arr[i][j],i+1));
    }

    return mx;
}

int main ()
{
    int t,i,j,k,ans;
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof mem);

        cin>>m>>c;
        for(i=0;i<c;i++)
        {
            scanf("%d",&arr[i][0]);
            for(j=1;j<=arr[i][0];j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        ans=calc(0,0);

        if(ans>=0)
            printf("%d\n",ans);
        else
            printf("no solution\n");


    }
    return 0;
}


/*

in tabular method

#include<bits/stdc++.h>

using namespace std;


int arr[25][25];


int main ()
{
    int mem[25][250],m,c,cnt;
    int t,i,j,k,ans;
    cin>>t;
    while(t--)
    {
        memset(mem,0,sizeof mem);

        cin>>m>>c;
        for(i=0;i<c;i++)
        {
            scanf("%d",&arr[i][0]);
            for(j=1;j<=arr[i][0];j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        for(i=0;i<c;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0)
                {
                    for(k=1;k<=arr[i][0];k++)
                    {
                        if(j==arr[i][k])
                            mem[i][j]=1;
                    }
                }
                else
                {
                    for(k=1;k<=arr[i][0];k++)
                    {
                        if(j>=arr[i][k] && mem[i-1][j-arr[i][k]]==1)
                            mem[i][j]=1;
                    }
                }
            }
        }

        for(i=m;i>=0;i--)
        {
            if(mem[c-1][i])
                break;
        }

        if(i>0)
            printf("%d\n",i);
        else
            printf("no solution\n");


    }
    return 0;
}


3
20 3
3 4 6 8
2 5 10
4 1 3 5 5

100 4
3 8 6 4
2 5 10
4 1 3 3 7
4 50 14 23 8

*/
