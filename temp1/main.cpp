/// codemarshal sub b 17

#include<bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pi pair<string,int>
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mod 1000003
#define ex 1e-7


int arr[100005],node[400010];

void update(int nn,int i,int j,int s,int e,int x)
{
    if(j<s || i>e)
        return;
    if(i>=s && j<=e)
    {
        node[nn]=x;
        return;
    }
    int mid=(i+j)/2;
    update(2*nn,i,mid,s,e,x);
    update(2*nn+1,mid+1,j,s,e,x);
}

void print(int nn,int i,int j,int pp=1)
{
    if(i==j)
    {
        printf(" %d",(arr[i]*node[nn]*pp)%1000000007);
        return;
    }
    int mid=(i+j)/2,x=(pp*node[nn])/__gcd(pp,node[nn]);
    print(2*nn,i,mid,x);
    print(2*nn+1,mid+1,j,x);
}

int main ()
{
    long long int tc,idd=0,p,n,t,id,d,l,r,k,x,i;
    scanf("%d",&tc);
    while(idd<tc){

        scanf("%d %d",&n,&k);
        for(i=0;i<=n;i++)
            arr[i]=1;
        for(i=0;i<=3*n;i++)
            node[i]=1;

        while(k--)
        {
            scanf("%d %d %d",&l,&r,&x);
            update(1,1,n,l,r,x);
        }
        printf("Case %d:",++idd);
        print(1,1,n);
        printf("\n");
    }

    return 0;
}
/*

1
7 2
2 5 2
5 7 3

*/
