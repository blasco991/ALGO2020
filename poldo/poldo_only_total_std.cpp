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

    for (int i = 0, x; i < N; i++) {                                // O(n)
        cin >> x;
        if (any_of(X.begin(), X.end(), [x](int i) { return i <= x; })) {            // O(n)
            auto it = upper_bound(X.begin(), X.end(), x, greater_equal<int>());    // O(log n)
            *(it) = max(*(it), x);
        } else X.push_back(x);
    }
                                                                    // O(n^2 * log(n))
#ifndef EVAL
    copy(X.begin(), X.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif
    cout << X.size() << endl;
    return 0;
}