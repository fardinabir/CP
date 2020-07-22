#include<bits/stdc++.h>

using namespace std;

#define ll long long

int prime[100005],pcheck[100005],ind;

void seive(ll n)
{
    ll i,j,k;
    prime[ind++]=2;
    for(i=4;i<100000;i+=2)
    {
        pcheck[i]=1;
    }
    for(i=3;i<=100000;i+=2)
    {
        if(!pcheck[i])
        {
            prime[ind++]=i;
            if(i*i>100000)
            continue;
            for(j=i*i;j<=100000;j+=2*i)
            {
                pcheck[j]=1;
            }
        }
    }
}

int main ()
{
    int tc,idd=0,p,n,a,b,c,c1,c2,c3,t,id,d,l,r,num=1,k,x,i;
    seive(1000);
    scanf("%d",&tc);
    while(idd<tc){
        ind=0;
        scanf("%d",&a);
        printf("Case %d: %d =",++idd,a);
        int ans[100]={0},ind1;
        while(prime[ind]<=a)
        {
            b=prime[ind];
            while(a/b)
            {
                ans[ind]+=(a/b);
                b*=prime[ind];
            }
            ind++;
        }
        printf(" %d (%d)",prime[0],ans[0]);
        for(i=1;i<ind;i++)
        {
            printf(" * %d (%d)",prime[i],ans[i]);
        }
        printf("\n");
    }
    return 0;
}
/*

1
7 2
2 5 2
5 7 3

*/
