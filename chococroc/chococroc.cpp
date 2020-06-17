#include <iostream>
#include <cmath>

using namespace std;

int is_L(int x, int y) {
    double result = log((x + 1) / (y + 1)) / log(2);
    double intpart;

    return modf(result, &intpart) == 0.0;
}

int main() {

    int q, n, m;
    cin >> q >> m >> n;
    int mx = max(m, n), mn = min(m, n);

    int matrix[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << is_L(i, j) << " ";
        }
        cout << endl;
    }

    if (n == m)
        cout << "2" << endl;
    else if (q == 0)
        cout << "1" << endl;
    else if (m > n)
        cout << "1\n" << mx - (mx - mn) << endl << mn << endl;
    else
        cout << "1\n" << mn << endl << mx - (mx - mn) << endl;

    return 0;
}