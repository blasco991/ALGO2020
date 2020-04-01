#include <algorithm>
#include <iterator>
#include <numeric>      // std::adjacent_difference
#include <vector>
#include <iostream>

using namespace std;

vector<long> X;
int N;

long solve() {

    long adj[N];
    sort(X.begin(), X.end());                                   // O(log n)
    adjacent_difference(X.begin(), X.end(), adj);               // O(n)
    for (int i = 0; i < N; i++)                                 // O(n)
        if (adj[i] == 0)
            return X[i];

    return 0;
}

int main() {
    scanf("%d", &N);
    X.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%ld", &X[i]);

    printf("%ld\n", solve());
}