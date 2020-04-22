#include <bits/stdc++.h>
#define mx 1000005
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

ll arr[mx],cal[mx],n,m;

int main()
{
    ll t,i,j,k,l,r,a,b,c=1,s,d,p,one=0,e,u,v,q,sum,id=1,x,y,sz;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        vector <ll> vc;
        test_case;
        for(i=0;i<m;i++)
        {
            ll mn=INT_MAX;
            scanf("%lld %lld",&l,&r);
            if(r-l>=1000)
            {
                printf("0\n");
            }
            else
            {
                for(j=l;j<=r;j++)
                    vc.push_back(arr[j]);
                sort(vc.begin(),vc.end());
                for(j=1;j<vc.size();j++)
                    mn=min(mn,vc[j]-vc[j-1]);
                printf("%lld\n",mn);
            }
            vc.clear();
        }
    }


    return 0;
}

/*

2

5 3

10 2 3 12 7

0 2

0 4

2 4

2 1

1 2

0 1

**/

