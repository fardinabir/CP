#include<bits/stdc++.h>

#define N 1000000

using namespace std;

int mparr[200005];
int arr[100005][2];

int main()
{
    int t,m,n,i,j,a,b,s,id=1,q,val;
    cin>>t;
    map <int,int> mp;
    map <int,int> :: iterator it;
    vector <int> vc;
    while (t--)
    {
        val=2;
        scanf("%d %d",&n,&q);

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&arr[i][0],&arr[i][1]);
            vc.push_back(arr[i][0]);
            vc.push_back(arr[i][1]);
        }
        sort(vc.begin(),vc.end());
        for(i=0;i<vc.size();i++)
        {
            if(!mp[vc[i]])
            {
                mp[vc[i]]=val;
                val+=2;
            }
        }
        for(i=0;i<n;i++)
        {
            mparr[mp[arr[i][0]]]+=1;
            mparr[mp[arr[i][1]]+1]-=1;
        }
        for(i=1;i<=val;i++)
        {
            mparr[i]+=mparr[i-1];
        }
        printf("Case %d:\n",id++);
        while(q--)
        {
            scanf("%d",&a);
            it=mp.lower_bound(a);
            if(a!=(*it).first)
                printf("%d\n",mparr[(*it).second-1]);
            else
                printf("%d\n",mparr[(*it).second]);
        }

        memset(mparr,0,sizeof mparr);
        vc.clear();
        mp.clear();
    }
    return 0;
}
/*
2

5 4
6 12
8 8
10 12
8 11
0 12
11
12
2
20

5 4
6 12
8 8
10 12
8 11
0 12
11
12
2
20



*/
