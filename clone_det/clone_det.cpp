#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
vector<long> A, B;

long solve() {

    set<long> v;
    for (int i = N - 1; i > 0; i--) {

        if (!v.insert(A[i]).second && find(B.rbegin(), B.rend(), A[i]) != B.rend())
            return A[i];
        if (!v.insert(B[i]).second && find(A.rbegin(), A.rend(), B[i]) != A.rend())
            return B[i];
    }

    return 0;
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    B.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    cout << solve() << endl;
}
