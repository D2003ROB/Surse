#include <bits/stdc++.h>

using namespace std;

int matrix[801][801], ap[100001];

int main() {
    
    ifstream f("amedie.in");
    ofstream g("amedie.out");

    int n, m, q, del, deleted = 0;

    f >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f >> matrix[i][j];
            ap[matrix[i][j]]++;
        }
    }

    char c;
    for(int i = 1; i <= q; i++) {
        f >> c;

        if(c == 'L') {
            f >> del;
            for(int j = 1; j <= n; j++) {
                if(matrix[del][j]) {
                    ap[matrix[del][j]]--;
                    deleted++;
                    matrix[del][j] = 0;
                }
            }
        } else if(c == 'C') {
            f >> del;
            for(int i = 1; i <= n; i++) {
                if(matrix[i][del]) {
                    ap[matrix[i][del]]--;
                    deleted++;
                    matrix[i][del] = 0;
                }
            }
        } else {
            bool found = false;
            int sum = 0;
            for(int i = 1; i <= 100000; i++) {
                sum += ap[i];
                if(sum >= (n * m - deleted) / 2 + (n * m - deleted) % 2) {
                    g << i << endl;
                    break;
                }
            }
        }
    }
    
}