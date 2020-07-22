#include<bits/stdc++.h>

using namespace std;

#define ULL unsigned long long

const int N = 100005;
const ULL hs = 3797;

char in[N];

ULL F[N], L[N], R[N];

ULL seg1(int x, int y)
{
    return L[y] - F[y - x + 1] * L[x - 1];
}

ULL seg2(int x, int y)
{
    return R[x] - F[y - x + 1] * R[y + 1];
}

int main()
{
    int n, lo, hi, mid, ans, mx, x, y, id=0, t;
    F[0] = 1;
    for (int i = 1; i < N; i++) {
        F[i] = F[i - 1] * hs;
    }
    scanf ("%d", &t);
    while (t--) {
        scanf ("%s", in);

        n = strlen(in);

        memset(L, 0, sizeof L);
        memset(R, 0, sizeof R);

        L[0] = 0;
        for (int i = 0; i < n; i++) {
            L[i + 1] = L[i] * hs + in[i];
        }
        R[n + 1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            R[i + 1] = R[i + 2] * hs + in[i];
        }
        x = n;
        for (int i = 2; i < n; i++) {
            if (seg1(i, n)==seg2(i, n)) {
                x = i;
                break;
            }
        }
        printf("%s ", in);
        if (n == 1) printf("%s\n", in);
        else {
            for (int i = x-1; i >= 1; i--) {
                printf("%c", in[i-1]);
            }
            printf("\n");
        }
    }
    return 0;
}
