#include <bits/stdc++.h>
#define mx 100000
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

ll arr[200005],n;

int main()
{
    //ll t,i,j,k,l,a,b,c=0,p,d=1,e,u,v,q,sum,id=1,x,y;
    int k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    cout<<min(c*d,min(k*l/nl,p/np))/n;
    return 0;
}
