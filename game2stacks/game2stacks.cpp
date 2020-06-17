#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    if (n == m)
        cout << "0\n0" << endl;
    else if (n > m) {
        int k = n - m;
        cout << k << endl << "0" << endl;
    } else {
        int k = m - n;
        cout << "0" << endl << k << endl;
    }

    return 0;
}