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
    X.resize(1);
    cin >> X[0];
    copy(X.begin(), X.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (int i = 1, x; i < N; i++) {
        cin >> x;
        auto it = upper_bound(X.rbegin(), X.rend(), x);
        if (it == X.rend())
            X.resize(X.size() + 1, x);
        else *(it) = *(it) < x ? x : *(it);
    }
#ifndef EVAL
    copy(X.begin(), X.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif
    cout << X.size() << endl;
    return 0;
}