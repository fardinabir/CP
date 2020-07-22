#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main ()
{
    ll tc,idd=0,p,n,a,b,c,c1,c2,c3,t,id,d,l,r,num=1,k,x,i;
    string st;
    seive();
    scanf("%lld",&tc);
    while(idd<tc){
        cin>>st;
        scanf("%lld",&a);
        printf("Case %lld: ",++idd);
        n=0,i=0;
        if(st[0]=='-')
            i++;
        while(i<st.size())
        {
            n=n*10+(st[i++]-48);
            n=n%a;
        }
        if(n==0)
            printf("divisible\n");
        else
            printf("not divisible\n");
    }
    return 0;
}
/*

1
7 2
2 5 2
5 7 3

*/
