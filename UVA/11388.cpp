#include <bits/stdc++.h>

using namespace std;

int main(){
    int lcm,gcd,t;
    cin>>t;
    while(t--){
        scanf("%d%d",&gcd,&lcm);
        if(lcm%gcd)
            printf("-1\n");
        else
            printf("%d %d\n",gcd,lcm);
    }
    return 0;
}
