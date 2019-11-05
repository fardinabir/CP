#include<bits/stdc++.h>
#define ll long long

using namespace std;

void func(int &a)
{
    a++;
    cout<<a<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        func(a);
        cout<<a<<endl;
    }
    return 0;
}
