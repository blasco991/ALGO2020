#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int N = 10000;
vector<set<int>> X;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    X.resize(1, {0});

    for (int i = 0, x; i < N; i++) {
        cin >> x;
        bool to_insert = true;
        for (int j = 0; j < X.size() && to_insert; j++)
            if (x > *(X[j].rbegin())) {
                X[j].insert(x);
                to_insert = false;
            }
        if (to_insert)
            X.resize(X.size() + 1, {x});
    }
#ifndef EVAL
    for (int i = 0; i < X.size(); i++, cout << endl)
        copy(X[i].begin(), X[i].end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif

    cout << X.size() << endl;

    return 0;
}