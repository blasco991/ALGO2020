#include <iostream>

using namespace std;


int main() {
    long long int g, n, i, l = 1;

    cin >> n;

    for (g = 0, i = -1; g < n; i++, l = g + 1)
        g = (n + l) / 2;

    cout << i;
    return 0;
}