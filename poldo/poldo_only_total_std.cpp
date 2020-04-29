#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector<int> X;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    X.resize(1, 0);

    for (int i = 0, x; i < N; i++) {
        cin >> x;
        if (all_of(X.cbegin(), X.cend(), [x](int i) { return i > x; }))
            X.push_back(x);
        else {
            auto it = upper_bound(X.begin(), X.end(), x, less_equal<int>());
            *(it) = max(*(it), x);
        }
    }
#ifndef EVAL
    copy(X.begin(), X.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif
    cout << X.size() << endl;
    return 0;
}