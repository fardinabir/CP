#include <iostream>

using namespace std;
int cnt;

void solve(int n,char from,char to,char aux)
{
    cnt++;
    if(n==1)
    {
        printf("Move %d from %c -- to %c\n",n,from,to);
        return;
    }
    solve(n-1,from,aux,to);
    printf("Move %d from %c -- to %c\n",n,from,to);
    solve(n-1,aux,to,from);
}

int main()
{
    int n;
    cin>>n;
    solve(n,'A','B','C');
    printf("\nSolved at %d moves\n",cnt);
    return 0;
}
