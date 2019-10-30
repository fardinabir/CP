#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000003

bool chk[1000005];

vector <ll> prime;

void seive()
{
    ll i,j,lim;
    prime.push_back(2);
    for(i=3;i<MAX;i+=2)
    {
        if(!chk[i])
        {
            prime.push_back(i);
            for(j=i*i;j<=MAX;j+=2*i)
                chk[j]=1;
        }
    }
}

int main()
{

}
