#include<bits/stdc++.h>

#define N 1000000

using namespace std;

int main()
{
    string st;
    map <string,int> mp;
    map <string,int> :: iterator it;

    double s=0;
    int t,id=1,m,n,i,j,a;
    scanf ("%d", &t);
    getchar();
    getchar();

    while (t--) {
        s=0;
        while(getline(cin,st) && st!="")
        {
            mp[st]++;
            s++;
        }
        for(it=mp.begin();it!=mp.end();++it)
            cout << it->first << " " << fixed << setprecision(4) << (it->second)*100.0/s << '\n';
        if(t>0)
            printf("\n");
        mp.clear();
    }
    return 0;
}
