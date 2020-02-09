#include <bits/stdc++.h>

using namespace std;

int a[102][102];
void algFill(int i, int j, int zone)

{
    a[i][j] = zone;
    if (a[i - 1][j] == 1)
        algFill(i - 1, j, zone);
    if (a[i][j + 1] == 1)
        algFill(i, j + 1, zone);
    if (a[i + 1][j] == 1)
        algFill(i + 1, j, zone);
    if (a[i][j - 1] == 1)
        algFill(i, j - 1, zone);
}
int main() {
    ifstream f("fill.in");
    ofstream g("fill.out");
    int n, m, zone = 0;
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1) {
                zone++;
                algFill(i, j, zone + 1);
            }
    g << zone;
    return 0;
}