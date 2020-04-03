#include <iostream>

using namespace std;

unsigned long long cache[35][35] = {1};

unsigned long long solveN(int n, int m = 0) {
    return cache[n][m] != 0 ? cache[n][m] :
            cache[n][m] = (n > 0 ? solveN(n - 1, m + 1) : 0) + (m > 0 ? solveN(n, m - 1) : 0);
}

int main() {
    int x;
    cin >> x;
    cout << solveN(x);
    return 0;
}