#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
vector<long> t1, t2;

long solve() {

    set<long> v;
    for (int i = N - 1; i > 0; i--) {

        if (!v.insert(t1[i]).second && find(t2.rbegin(), t2.rend(), t1[i]) != t2.rend())
            return t1[i];
        if (!v.insert(t2[i]).second && find(t1.rbegin(), t1.rend(), t2[i]) != t1.rend())
            return t2[i];
    }

    return 0;
}

int main() {
    cin >> N;
    t1.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> t1[i];
    }

    t2.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> t2[i];
    }

    cout << solve() << endl;
}
