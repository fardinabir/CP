#include<bits/stdc++.h>
#define ll unsigned long long int
#define mx 10005

using namespace std;

int par[100005];

int find_par(int a)
{
    if(par[a]==a)
        return a;
    return par[a]=find_par(par[a]);
}

int _union(int a,int b)
{
    if(find_par(a)!=find_par(b))
    {
        par[find_par(a)]=find_par(b);
        return 1;
    }
    return 0;
}

int main()
{
    int a,b,c,i,n,j,k,t,l,m,id=1,xx,yy,ans;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    string st;
    scanf("%d\n\n",&t);
    while(t--)
    {
          getline(cin,st);
          n=st[0]-'A'+1;
          for(i=0;i<=n;i++)
              par[i]=i;
          ans=n;
          while(1)
          {
              if(!getline(cin,st) || st.empty())
                break;
              xx=st[0]-'A',yy=st[1]-'A';
              ans-=(_union(xx,yy));
          }
          printf("%d\n",ans);
          if(t>0)
            printf("\n");
          memset(par,0,sizeof par);
    }


    return 0;
}

/*
H
BA
EA
CE
CD
DF
GD
DH
DB
BG
EB
AH
HG
FG
FB
ED
CA

*/
