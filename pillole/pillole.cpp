#include <iostream>

using namespace std;

const int N = 35;
long cache[N + 1][N + 1] = {{1}};

long solveN(int n, int m = 0) {
    return cache[n][m] != 0 ? cache[n][m] :
            cache[n][m] = (n > 0 ? solveN(n - 1, m + 1) : 0) + (m > 0 ? solveN(n, m - 1) : 0);
}

int main() {
    int x;
    cin >> x;
    cout << solveN(x) << endl;
    return 0;
}