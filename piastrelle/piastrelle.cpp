#include <iostream>
#include <fstream>

using namespace std;

string possible1(int n, string p);

string possible2(int n, string p);

string possible1(int n, string p) {

    if (n == 0)
        return p + "\n";

    return possible1(n - 1, p + "[O]") + possible2(n - 1, p + "[O]");
}

string possible2(int n, string p) {

    if (n == 2)
        return p + "[OOOO]\n";

    if (n > 2)
        return possible1(n - 2, p + "[OOOO]") + possible2(n - 2, p + "[OOOO]");

    return "";
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << possible1(n, "");
    cout << possible2(n, "");
    return 0;
}