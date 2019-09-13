///spoj easyprob - recursion

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
    while(n>0)
    {
        printf("2");
        x=log2(n);
        if(x!=1)
        {
            printf("(");
            call(x);
            printf(")");
        }
        n-=(round(pow(2,x)));
        if(n>0)
            printf("+");
    }
}

int main()
{
    int n,i,j,k,l,m,s=0;
    int arr[7]={137, 1315, 73, 136, 255, 1384, 16385};
    for(i=0;i<7;i++)
    {
        cout<<arr[i]<<"=";
        call(arr[i]);
        cout<<endl;
    }
    return 0;
}
