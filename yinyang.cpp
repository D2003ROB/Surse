#include <bits/stdc++.h>

using namespace std;

void linii(int a[102][102], int n, int m, int l1, int l2) {
    for (int j = 1; j <= m + 1; j++) {
        int aux = a[l1][j];
        a[l1][j] = a[l2][j];
        a[l2][j] = aux;
    }
}
void coloane(int a[102][102], int n, int m, int c1, int c2) {
    for (int i = 1; i <= n + 1; i++) {
        int aux = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = aux;
    }
}
int rs(int a[102][102], int n, int m, int l1, int l2) {
    return (a[l1][m + 1] > a[l2][m + 1]);
}
int cs(int a[102][102], int n, int m, int c1, int c2) {
    return (a[n + 1][c1] > a[n + 1][c2]);
}
void tipar(int a[102][102], int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

}
int main() {
    ifstream f("yinyang.in");
    ofstream g("yinyang.out");
    int a[102][102], n, m, i, j, ok, k = 0, s;
    char c;
    f >> n >> m;
    for (i = 1; i <= n; i++) {
        s = 0;
        for (j = 1; j <= m; j++) {
            f >> a[i][j];
            s = s + a[i][j];
        }
        a[i][m + 1] = s;

    }
    for (j = 1; j <= m; j++) {
        s = 0;
        for (i = 1; i <= n; i++) {
            s = s + a[i][j];
        }
        a[n + 1][j] = s;
    }
    do {
        ok = 0;
        for (i = 1; i <= n - 1; i++)
            if (rs(a, n, m, i, i + 1)) {
                linii(a, n, m, i, i + 1);
                ok = 1;
                k++;
            }

    }
    while (ok);
    do {
        ok = 0;
        for (j = 1; j <= m - 1; j++)
            if (cs(a, n, m, j, j + 1)) {
                coloane(a, n, m, j, j + 1);
                ok = 1;
                k++;
            }

    }

    while (ok);
    bool oki = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (a[i][j] > a[i][j + 1])
                oki = true;
    }
    if (oki)
        g << -1;
    else g << k;
    f.close();
    g.close();
    return 0;
}
/// N + R