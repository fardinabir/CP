#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define monty            main
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define MOD              1000000007
#define no_op           happy()
#define fast_cin         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define UNIQUE(v)        (v).erase(unique((v).begin(),(v).end()),(v).end())
#define POPCOUNT         __builtin_popcountll
#define RIGHTMOST        __builtin_ctzll
#define LEFTMOST(x)      (63-__builtin_clzll((x)))
#define NUMDIGIT(x,y)    (((vlong)(log10((x))/log10((y))))+1)
#define NORM(x)          if(x>=mod) x-=mod;if(x<0) x+=mod;
#define ODD(x)           (((x)&1)==0?(0):(1))
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define LINE_PRINT_CASE  printf("Case %d:\n",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define Exit             no_op
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define D(x)        	 cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define DD(x,y)          cerr << __LINE__ << ": " << #x << " = " << x << "   " << #y << " = " << y << '\n'
#define DDD(x,y,z)       cerr << __LINE__ << ": " << #x << " = " << x << "   " << #y << " = " << y << "   " << #z << " = " << z << '\n'
#define DBG              cerr << __LINE__ << ": Hi" << '\n'

using namespace std;

char h='*';

int i;

void birt();

void treat()
{
    while(1)
    {
         cout<<"\n\n\n\n\n\t\t\t      Say treat !???\n\n\n";
         Sleep(400);
    }
}

int next()
{
    return cout<<"\t\t       | "<<h<<" "<<h<<" "<<h<<" "<<h<<"  Monty  "<<h<<" "<<h<<" "<<h<<" "<<h<<" |\n",1;
}

void day()
{
     cout<<"\t\t       | "<<h<<"   "<<h<<"     BIRTHDAY    "<<h<<" |\n";
     system("color F");
     Sleep(400);
     cout<<"\t\t       |"<<h<<"  "<<h<<"     "<<h<<"    "<<h<<"     "<<h<<"   "<<h<<"|\n";

     system("color D");
     Sleep(800);
}

void next2()
{
     next();
     system("color 4");
     Sleep(800);
     system("color F");
     cout<<"_______________________|_________________________|__________________________\n";

     cout<<"\n\n\t       ";
     for(i=0;i<42;i++)
     cout<<"_";
     cout<<"\n\n\n\n\n";
     system("pause");
     treat();
}

void happy()
{
     int i;
     cout<<"\t\t";
     cout<<"\n\n";
     cout<<"\t\t";
     system("color F");
     cout<<"life is nothing but problem solving, wishing you accepted verdict in all your problems"<<endl;
     Sleep(5000);
     system("cls");

     cout<<"\t\t";

     cout<<"\n\n";
     system("color 5E");

     Sleep(400);
     system("color F");
     cout<<"\t\t\t\ti i i i i\n";
     system("color A");
     Sleep(400);
     cout<<"\t\t\t\ti i i i i\n";
     system("color BD");
     Sleep(200);
     system("color 2D");
     Sleep(400);
     system("color 6");
     cout<<"\t\t\t      __i_i_i_i_i__\n";
     birt();
     next2();
}

void birt()
{
     system("color D");
     Sleep(800);
     system("color 1");
     cout<<"\t\t\t     |"<<h<<"           "<<h<<"|\n";
     system("color 5");
     Sleep(400);
     system("color E");
     cout<<"\t\t\t   __| "<<h<<"   ---   "<<h<<" |__\n";
     system("color 6");
     Sleep(400);
     cout<<"\t\t\t  | "<<h<<"   "<<h<<"       "<<h<<"   "<<h<<" |\n";
     system("color F");
     Sleep(400);
     cout<<"\t\t\t__|"<<h<<"   HAPPY     "<<h<<"   "<<h<<"|__\n";
     system("color 9");
     Sleep(700);
     day();
}


monty()
{
     Exit;
}
