///spoj brackets, segment tree

#include <bits/stdc++.h>

using namespace std;

struct st
{
    int open,close;
}node[120001];

int qind;
char arr[30100];
bool modify;

void update(int nn,int i,int j,int ind)
{
    if(j<ind-1 || i>ind-1)
        return;
    if(i==j && i+1==ind)
    {
        if(modify)
        {
            arr[i]= arr[i]=='('? ')' : '(' ;
            modify=false;
        }
        if(arr[i]=='(')
        {
            node[nn].open=1;node[nn].close=0;
        }
        else
        {
            node[nn].close=1;node[nn].open=0;
        }

        //cout<<i<<" - "<<j<<"    "<<node[nn].close<<" --- "<<node[nn].open<<endl;
        return;
    }
    int mid=(i+j)/2,x;

    update(2*nn,i,mid,ind);
    update(2*nn+1,mid+1,j,ind);

    x=min(node[2*nn].open,node[2*nn+1].close);
    node[nn].close=node[2*nn].close+node[2*nn+1].close-x;
    node[nn].open=node[2*nn].open-x+node[2*nn+1].open;

    //cout<<i<<" - "<<j<<"    "<<node[nn].close<<" --- "<<node[nn].open<<endl;

}



int main()
{
    int i,j,k,l,n,m,s=1;
    while(s<11)
    {
        printf("Test %d:\n",s++);
        scanf("%d",&n);
        scanf("%s",arr);
        for(i=1;i<=n;i++)
            update(1,0,n-1,i);

        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&k);
            if(k)
            {
                qind=k;
                modify=true;
                update(1,0,n-1,k);
            }
            else
            {
                if(node[1].open==0 && node[1].close==0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }

    return 0;
}
/*
16
((()()))()()((()
6
0
14
0
13
14
0
1
(
0
1
(
0
1
(
0
1
(
0
1
(
0
1
(
0
1
(
0
1
(
0
1
(
0


*/
