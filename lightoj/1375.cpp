#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define MAX 3000000

ll phi[3000005],ans[3000005];

void totient()
{
    ll i,j,k;
    phi[1]=1;
    for(i=2;i<=MAX;i++)
    {
        if(!phi[i])
        {
            phi[i]=i-1;
            for(j=i+i;j<=MAX;j+=i)
            {
                phi[j]= phi[j]==0? j: phi[j];
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}

void pre_cal()
{
    totient();
    ll i,j,k;
    for(i=2;i<=MAX;i++)
    {
        for(j=i;j<=MAX;j+=i)
        {
            ans[j]+=(ll)(i*phi[i]/2 * j);
        }
    }
    for(i=2;i<=MAX;i++)
    {
        ans[i] += ans[i - 1];
    }
}

int main()
{
    ll tc,idd=0,b,s,n,nn,temp,r,i,p,k,q,c,sod,lob,hor;
    pre_cal();
    scanf("%llu",&tc);
    while(tc--)
    {
        scanf("%llu",&n);
        printf("Case %llu: ",++idd);
        printf("%llu\n",ans[n]);
    }
    return 0;
}
/*



15

2

3

4

6

8

10

12

15

18

20

21

24

25

27

29

*/

