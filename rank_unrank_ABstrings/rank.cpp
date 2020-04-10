#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int length, r;
string input;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    if (scanf("%d %d", &length, &r) == 2);
    else
        cin >> input;

    cout << 'A' - 64 << endl;

    cout << input << endl;
    cout << length << endl;
    cout << r << endl;

}