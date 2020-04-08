#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector<int> X;

int possible() {
    vector<int> pot(X.size(), 0);

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++)
            if (X[j] < X[i])
                pot[i]++;
    }

    return N - count(pot.begin(), pot.end(), 0);
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    X.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    cout << possible();
}