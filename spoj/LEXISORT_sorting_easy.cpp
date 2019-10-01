#include <bits/stdc++.h>
using namespace std;
string arr[50000];
int main()
{
    int k,i,n;

    scanf("%d", &k);
    while(k--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr+n);
        for(i = 0; i < n; i++)
            cout << arr[i] << endl;
    }
    return 0;
}
