#include <bits/stdc++.h>
#define LL long long
using namespace std;

vector <int> primes;
int p_check[100005];

void seive(int n)
{
    primes.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(!p_check[i])
        {
            primes.push_back(i);
            for(int j=i*i;j<=n;j+=(i+i))
            {
                p_check[j]=1;
            }
        }
    }
}


int main()
{
    int i,j,k,l,n,m,x,y,c,cc,t;
    seive(10000);
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=n;
        cc=1;
        for(i=0;primes[i]*primes[i]<=x && i<primes.size();i++)
        {
            y=primes[i];
            c=0;
            while(x%y==0)
            {
                x/=y;
                c++;
            }
            cc=max(cc,c);
        }
        cout<<cc<<endl;
    }

    return 0;
}
