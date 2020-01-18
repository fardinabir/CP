#include<bits/stdc++.h>

using namespace std;

int dp[25][25];
int mat[25][25];

int n, m;

int F(int i, int j)
{
    if (i == n + 1 || j == m + 1) return 0;

    int x1 = F(i + 1, j) + mat[i][j];
    int x2 = F(i, j + 1) + mat[i][j];

    return max(x1, x2);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + mat[i][j];
        }
    }
    cout << dp[n][m] << endl;
    cout << F(1, 1) << endl;
    return 0;
}
