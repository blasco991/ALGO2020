#include <iostream>

using namespace std;

int main() {
    string x;
    for (string y; !cin.eof();) {
        cin >> y;
        x += " " + y;
    }
    cout << x;
    return 0;
}
