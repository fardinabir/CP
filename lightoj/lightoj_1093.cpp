#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int arr[100005];

int main() {
    int i,j,k,l,m,n,s,e,v,key,x,t,c=1;
    cin>>t;
    char ch;
    while(c<=t)
    {
        printf("Case %d: ",c++);
        scanf("%d %d",&n,&m);
        deque < pair <int,int> > dmin,dmax;
        int tmi=INT_MAX,tma=-1,mres=0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);

            while(arr[i]<dmin.front().first && dmin.size())
            {
                dmin.pop_front();
            }
            dmin.push_front({arr[i],i});
            if(i>=m-1)
            {
                tmi=dmin.back().first;
                if(dmin.back().second==i-m+1)
                {
                    dmin.pop_back();
                }
            }

            while(arr[i]>dmax.front().first && dmax.size())
            {
                dmax.pop_front();
            }
            dmax.push_front({arr[i],i});
            if(i>=m-1)
            {
                tma=dmax.back().first;
                if(dmax.back().second==i-m+1)
                {
                    dmax.pop_back();
                }
            }
            if(i>=m-1)
            {
                mres=max(mres,tma-tmi);
            }
        }
        printf("%d\n",mres);
    }
    return 0;
}
