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

    for (int i = 0, j, x; i < N; i++) { ;
        bool to_insert = true;
        for (j = 0, cin >> x; j < X.size() && to_insert; j++)
            if (x >= X[j]) {
                X[j] = x;
                to_insert = false;
            }

        if (to_insert)
            X.push_back(x);
    }
#ifndef EVAL
    copy(X.begin(), X.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif
    cout << X.size() << endl;
    return 0;
}