#include <bits/stdc++.h>
#define ll long long int
#define test_case printf("Case %d:\n",id++);

using namespace std;

int time_dif(int h2,int m2,int h1,int m1)
{
    int mnt=0;
    if(h2<h1 || (h2==h1 && m2<m1))
        h2+=24;
    mnt+=(h2-h1)*60;   /// uva .................
    if(m2>=m1)
        mnt+=(m2-m1);
    else
        mnt-=(m1-m2);
    return mnt;
}

int main()
{
    int t,i,j,k,n,l,id=1;
    string st;
    cin>>t;
    while(t--)
    {
        int h,m,h1,m1,t1,mn=INT_MAX;
        scanf("%d %d:%d",&k,&h,&m);
        for(i=0;i<k;i++)
        {
            scanf("%d:%d %d",&h1,&m1,&t1);
            mn=min(mn,time_dif(h1,m1,h,m)+t1);
        }
        printf("Case %d: %d\n",id++,mn);
    }
    return 0;
}
/*
1
12 19:23
05:20 694
13:25 950
19:21 302
19:10 437
03:34 585
22:19 465
10:55 971
14:59 126
07:42 246
23:05 235
10:58 500
18:15 394


2
1 18:00
19:30 30
2 18:00
19:00 100
20:00 30
*/
