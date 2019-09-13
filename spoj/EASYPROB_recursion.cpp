#include <bits/stdc++.h>

using namespace std;

void call(int n)
{
    int x;
    if(n==0)
    {
        printf("0");
        return;
    }
    while(log2(n))
    {
        printf("2");
        x=log2(n);
        if(x!=1)
        {
            printf("(");
            call(x);
            printf(")");
        }
        else
            printf("2");
        n-=(round(pow(2,x)));
        if(n>0)
            printf("+");
    }
}

int main()
{
    int n,i,j,k,l,m,s=0;
    cin>>n;
    call(n);
}
