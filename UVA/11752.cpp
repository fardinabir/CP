#include <bits/stdc++.h>
#define ll  long long unsigned


using namespace std;

int prime[45]={4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,34,33,34,35,36,38,39,40,42,44,45,46,48,49,50,52,51,54,55,56,57,58,60,62,63};
set <ll> st;

ll pw(ll b,ll p)
{
    ll ans=1;
    while(p--)
    {
        ans*=b;
    }
    return ans;
}

int main()
{
    ll i,j,a,b,k,d,n,idd=0,m=0,flag,ans=0,t,temp, mxx;
    st.insert(1);
    mxx = pw(2, 64) - 1;
    for(i=2; ;i++)
    {
        t=-1,m=mxx;
        while(m)
        {
            m/=i;
            t++;
        }
        if(t<4)
            break;
        for(j=0;prime[j]<=t && j<45;j++)
        {
            st.insert(pw(i,prime[j]));
        }
    }
    //return 0;
    for(auto it=st.begin();it!=st.end();++it)
    {
        printf("%llu\n",*it);
    }
    return 0;
}
