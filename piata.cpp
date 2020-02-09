#include <bits/stdc++.h>

using namespace std;

short Freq[40001];

ifstream f("piata.in");
ofstream g("piata.out");

int sumacifre(int nr) {
    int s = 0;
    while(nr) {
        s += nr % 10;
        nr /= 10;
    }
    nr = s;
    return nr;
}
int n, mi, mj, ni, nj, smax, x;
int main()
{
    f >> n;
    f >> mi >> mj >>  ni >> nj;
    
    for(int i = 1; i <= n; i++) {
        Freq[i] = sumacifre(i);
    }

    for(int i = mi; i <= ni; i++) {
        for(int j = mj; j <= nj; j++) {
            if(j >= i) {
                x = j - i + 1;
            } else {
                x = n - i + j + 1;
            }
            if(x == 0) x = n;
            smax += Freq[x];
        }
    }
    g << smax;
    return 0;
}
