#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 10000005

bool chk[10000005];

vector <int> prime;

void seive()
{
    int i,j,k;
    prime.push_back(2);

    for(i=3;i<=MAX;i+=2)
    {
        if(!chk[i])
        {
            prime.push_back(i);
            for(j=i*i;j<=MAX;j+=2*i)
            {
                chk[j]=1;
            }
        }

    }
}

int main()
{
    ll tc,idd=0,b,s,n,nn,temp,r,i,p,k,q,c,ans,sod,lob,hor;
    scanf("%lld",&tc);
    seive();
    while(tc--)
    {
        scanf("%lld",&n);
//        if(!n)
//            return 0;
        printf("Case %lld: ",++idd);
        ans=1;
        for(i=0;prime[i]*prime[i]<=n;i++)
        {
            if(n%prime[i]==0)
            {
                c=0;
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    c++;
                }
                ans*=(2*c+1);
            }
        }
        if(n>1)
            ans*=3;

        printf("%lld\n",ans);
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
