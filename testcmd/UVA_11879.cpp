#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main ()
{
    long long int tc,idd=0,p,n,a,b,c,c1,c2,c3,t,id,d,l,r,num=1,k,x,i;
    string st;
    while(cin>>st){
        if(st=="0")
            return 0;
        n=0,i=0;
        if(st[0]=='-')
            i++;
        while(i<st.size())
        {
            n=n*10+(st[i++]-48);
            n=n%17;
        }
        if(n==0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
