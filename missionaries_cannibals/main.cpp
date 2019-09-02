#include<bits/stdc++.h>

using namespace std;

struct Point
{
    int ml, cl, mr, cr, x;

}xx, yy, path[4][4][4][4][2], zz;

vector <Point> vt;
stack <Point> st;
int visited[4][4][4][4][2];

void F(int m1, int c1, int m2, int c2, int x)
{
    vt.clear();
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (i + j > 0 && i + j <= 2) {
                if (x == 0) {
                    xx.ml = m1 - i;
                    xx.cl = c1 - j;
                    xx.mr = m2 + i;
                    xx.cr = c2 + j;
                    xx.x = 1;
                }
                else {
                    xx.ml = m1 + i;
                    xx.cl = c1 + j;
                    xx.mr = m2 - i;
                    xx.cr = c2 - j;
                    xx.x = 0;
                }
                vt.push_back(xx);
            }
        }
    }
    return ;
}

int is_valid(int m1, int c1, int m2, int c2, int x)
{
    if ((m1 > 0 && c1 > m1) || (m2 > 0 && c2 > m2) || visited[m1][c1][m2][c2][x]) return 0;
    if (m1 < 0 || c1 < 0 || m2 < 0 || c2 < 0 || m1 > 3 || c1 > 3 || m2 > 3 || c2 > 3) return 0;
    return 1;
}

void bfs_sol()
{
    int M1, M2, C2, C1, X;
    queue <Point> q;
    zz.ml = 3; zz.cl = 3; zz.mr = 0; zz.cr = 0; zz.x = 0;
    visited[3][3][0][0][0] = 1;
    q.push(zz);
    while (!q.empty()) {
        zz = q.front();
        q.pop();

        F(zz.ml, zz.cl, zz.mr, zz.cr, zz.x);

        for (int i = 0; i < vt.size(); i++) {

            yy = vt[i];
            M1 = yy.ml; C1 = yy.cl; M2 = yy.mr; C2 = yy.cr; X = yy.x;

           if (is_valid(M1, C1, M2, C2, X)) {

                visited[M1][C1][M2][C2][X] = 1;

                path[M1][C1][M2][C2][X].ml = zz.ml;
                path[M1][C1][M2][C2][X].cl = zz.cl;
                path[M1][C1][M2][C2][X].mr = zz.mr;
                path[M1][C1][M2][C2][X].cr = zz.cr;
                path[M1][C1][M2][C2][X].x = zz.x;

                if (M1 == 0 && C1 == 0 && M2 == 3 && C2 == 3 && X) return;
                    q.push(yy);
            }

        }
    }
}

int main()
{
    int M1, C1, M2, C2, X;
    bfs_sol();
    yy.ml = 0; yy.cl = 0; yy.mr = 3; yy.cr = 3; yy.x = 1;
    while (1) {
        M1 = yy.ml; C1 = yy.cl; M2 = yy.mr; C2 = yy.cr; X = yy.x;
        st.push(yy);
        if (M1 == 3 && C1 == 3 && M2 == 0 && C2 == 0 & X == 0) break;
        yy.ml = path[M1][C1][M2][C2][X].ml;
        yy.cl = path[M1][C1][M2][C2][X].cl;
        yy.mr = path[M1][C1][M2][C2][X].mr;
        yy.cr = path[M1][C1][M2][C2][X].cr;
        yy.x = path[M1][C1][M2][C2][X].x;
    }
    cout <<"     M C  \t\t     M C  Boat Status(0-left, 1-Right)"<< endl;
    while (!st.empty()) {
        zz = st.top();
        st.pop();
        cout << "L :  "<<zz.ml << " " << zz.cl << "\t\tR :  " << zz.mr << " " << zz.cr << "\t" << zz.x << endl;
    }
    return 0;
}
