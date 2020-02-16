#include <bits/stdc++.h>

using namespace std;

int arr[1000000],ast,aendd;

bool cal(int i,int j)
{
    if((j-i)==(aendd-ast))
        return i<ast;
    return (j-i)>=(aendd-ast);
}

int main()
{
    int i,j,k,l,s=0,cnt,id=0,n,t,cum[1000]={0},mx=0,st,endd;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n--;
        s=0,ast=0,st=0,aendd=-1,mx=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0;i<n;i++)
        {
            s+=arr[i];
            if(s<0)
            {
                s=0;
                st=i+1;
            }

            if(s>mx)
            {
                mx=s,ast=st,aendd=i;
            }
            else if(s==mx)
            {
                if((i-st)==(aendd-ast))
                {
                    ast=st,aendd=i;
                }
            }
        }
        if(mx>0)
            printf("The nicest part of route %d is between stops %d and %d\n",++id,ast+1,aendd+2);
        else
            printf("Route %d has no nice parts\n",++id);
    }
}
/*
3
3 -1 6
10 4 -5 4 -3 4 4 -4 4 -5
4 -2 -3 -4

*/
