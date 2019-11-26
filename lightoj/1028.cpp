#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, m, i, j, ans, prime[1000009], num[1000009]={0}, cnt, cs=1;

void seive(){
    for(i=3; i*i<=1000000; i+=2){
        if(num[i]==0){
            for(j=i*i; j<=1000000; j=j+(i*2)) num[j]=1;
        }
    }
    prime[0]=2;
    j=1;
    for(i=3; i<=1000000; i+=2){
        if(num[i]==0) prime[j++]=i;
    }
}

int main(){
    seive();
    scanf("%lld", &t);

    while(t--){
        cin>>n;
        ans=1;
        for(i=0; i<j&&prime[i]*prime[i]<=n; i++){
            cnt=0;
            while(n%prime[i]==0){
                cnt++;
                n=n/prime[i];
            }
            ans=ans*(cnt+1);
        }

        if(n!=1)ans=ans*2;
        cout<<"Case "<<cs++<<": "<<ans-1<<endl;

    }
    return 0;
}


