#include <bits/stdc++.h>
#define mx 1000005
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

ll cnt_zero[mx],n;
string arr;

int main()
{
    ll t,i,j,k,l,a,b,c=0,p,one=0,e,u,v,q,sum,id=1,x,y;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        cin>>arr;
        one=sum=0;  //fardinabirs.wordpress.com
        for(i=0;i<n;i++)
        {
            if(arr[i]=='1')
                one++;
            if(arr[i]=='0')
                cnt_zero[one]++; // counting zero after the one'th occurrence of 1
            if(one>=k)
                sum+=cnt_zero[one-k]+(k!=0);  //the number of zero between the before the starting point

        }
        cout<<sum<<endl;
        memset(cnt_zero,0,sizeof cnt_zero);
    }
    return 0;
}
