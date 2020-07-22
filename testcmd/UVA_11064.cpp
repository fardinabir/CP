#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mx 46341
bool check[100000];
int phi[100000];
vector <ll> prime;

void seive()
{
    prime.push_back(2);
    for(ll i=3;i<=mx;i+=2)
    {
        if(!check[i])
        {
            prime.push_back(i);
            for(ll j=i*i;j<mx;j+=(i+i))
                check[j]=true;
        }

    }
}

void totient()
{
    int i,j,k;
    phi[1]=1;
    for(i=2;i<mx;i++)
    {
        if(!phi[i])
        {
            phi[i]=i-1;
            for(j=i+i;j<mx;j+=i)
            {
                phi[j] = phi[j]==0 ? j : phi[j];
                phi[j] -= phi[j]/i;
            }
        }
    }
}


void nod_phi(int n,int &phi,int &nod)
{
    int res=1,cnt,res_phi=n;
    for(int i=0;i<prime.size() && prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            res*=(cnt+1);

            res_phi-=(res_phi/prime[i]);
        }

    }
    if(n>1)
    {
        res*=2;
        res_phi-=(res_phi/n);
    }

    nod=res;
    phi=res_phi;
}

int main()
{
    int i,j,k,l,n;
    //totient();
    seive();
    while(scanf("%d",&n)!=EOF)
    {
        nod_phi(n,k,l);
        printf("%d\n",n-k-l+1);
    }
    return 0;
}
