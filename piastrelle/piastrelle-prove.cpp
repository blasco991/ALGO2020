#include <iostream>

using namespace std;

string possible1(int n, string p);

string possible2(int n, string p);

string possible1(int n, string p) {
    cout << n << " p1" << endl;

    if (n == 1) {
        cout << p + "[o]\n";
    }

    if (n > 1)
        return possible1(n - 1, "[o]") + (n > 2 ? "[o]" + possible2(n - 1, "[o]") : "");

    return "\n";
}

string possible2(int n, string p) {
    cout << n << " p2" << endl;

    if (n == 2) {
        cout << endl;
        return p + "[OOOO]\n";
    }

    if (n > 2)
        return p + "[OOOO]" + possible1(n - 2, p) + p + (n > 3 ? "[OOOO]" + possible2(n - 2, p) : "");

    return "\n";
}

string possible(int n) {
    cout << n << endl << endl;

    string one = possible1(n, "");

    string two = possible2(n, "");

    return one + two;
}

int main() {
    int n;

    cin >> n;
    cout << endl;

    for (int i = 1; i <= n; i++)
        cout << possible(i) << endl;


    return 0;
}