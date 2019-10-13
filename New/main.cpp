#include<bits/stdc++.h>

#define N 1000000
#define ll long double


using namespace std;

struct ss
{
    string name;
    int hp,ap,dp;
}sol[105];

struct id
{
    int i,j,k;
}tid;

vector <id> vc;
map <string,bool> mp;

bool checkWin(ss a,ss b)
{
    int aa=max(0,b.ap-a.dp),bb=max(0,a.ap-b.dp);
    if(aa==0 && bb)
    {
        return true;
    }
    if(aa!=0 && bb!=0 && (a.hp*bb)>(b.hp*aa))
        return true;
    return false;
}

int main()
{
    int i,j,k,l,n,a,b,c;
    cin>>n;
    string vis="";
    string name;
    for(i=0;i<n;i++ )
    {
        cin>>sol[i].name>>sol[i].hp>>sol[i].ap>>sol[i].dp;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==i)
                continue;
            for(k=0;k<n;k++)
            {
                vis="";
                if(k==j || k==i)
                    continue;
                if(checkWin(sol[i],sol[j]) && checkWin(sol[j],sol[k]) && checkWin(sol[k],sol[i]))
                {
                    tid.i=i,tid.j=j,tid.k=k;
                    vis+=(i);
                    vis+=(j);
                    vis+=(k);
                    sort(vis.begin(),vis.end());

                    if(!mp[vis])
                    {
                        vc.push_back(tid);
                        mp[vis]=1;
                    }
                }
            }

        }
    }


    cout<<vc.size()<<endl;
    for(i=0;i<vc.size();i++)
    {
        cout<<sol[vc[i].i].name<<" "<<sol[vc[i].j].name<<" "<<sol[vc[i].k].name<<endl;
    }

    return 0;
}
/*

5
TheResilient 160 40 10
TheStrong 90 60 10
TheTough 70 50 25
TheInvincible 10000 10000 10000
TheBrick 3 1 4159



5
TheStrong 90 60 10
TheInvincible 90 60 10
TheTough 90 60 10
TheBrick 90 60 10
TheResilient 90 60 10

*/
