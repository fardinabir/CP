/// lightoj 1112

#include<bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int arr[100005],node[100005],n;

void update(int ind,int val)
{
    for(int i=ind;i<=n;i+=(i&-i))
        node[i]+=val;
}

int query(int ind)
{
    int ret=0;
    for(int i=ind;i>0;i-=(i&-i))
        ret+=node[i];
    return ret;
}

int main()
{
    int i,x,id=1,sum,s=0,m,y,z,f1,t,k,f2;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        printf("Case %d:\n",id++);
        for(i=1;i<=n;i++)
            update(i,arr[i]);
        while(k--)
        {
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d",&y);
                y++;
                s=query(y)-query(y-1);
                printf("%d\n",s);
                update(y,-s);
            }
            else if(x==2)
            {
                scanf("%d %d",&y,&z);
                update(y+1,z);
            }
            else
            {
                scanf("%d %d",&y,&z);
                y++,z++;
                printf("%d\n",query(z)-query(y-1));
            }
        }
        memset(node,0,sizeof node);
    }

    return 0;
}

/*
1

5 6

3 2 1 4 5

1 4

2 3 4

3 0 3

1 2

3 0 4

1 1

*/

