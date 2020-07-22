/// uva 524

#include <bits/stdc++.h>

using namespace std;

int cnt,i,n;
bool flag[21];

deque <int> vc[10000];
deque <int> vct;

bool is_prime(int n)
{
    if(n==2 || n==3 || n==5 || (n%2!=0 && n%3!=0 && n%5!=0))
        return true;
    return false;
}

void solve(int pos)
{
    if(pos==n)
    {
        if(is_prime(vct[n-1]+vct[0]))
        {
            printf("%d",vct[0]);
            for(int i=1;i<vct.size();i++){
                printf(" %d",vct[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(!flag[i] && is_prime(vct[pos-1]+i))
        {
            vct.push_back(i);
            flag[i]=true;
            solve(pos+1);
            flag[i]=false;
            vct.pop_back();
        }
    }
}

int main()
{
    int i,j,k,l,m,s=0,c=0,id=0;
    bool f=0;
    while(cin>>n)
    {
        if(f){
            printf("\n");
        }
        f=1;
        memset(flag,false,21);
        vct.push_back(1);
        printf("Case %d:\n",++id);
        solve(1);
        vct.clear();

    }
    return 0;
}
