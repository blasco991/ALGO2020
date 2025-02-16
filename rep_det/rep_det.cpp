#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int N;
vector<long> X;

long solve() {

    unsigned int min = N;
    set<long> viewed;

    for (unsigned int i = 0; i < N; viewed.insert(X[i++]))    // O(n)
        if (X[i] < X[min] || min == N)
            if (viewed.find(X[i]) != viewed.end())    // O(log n)
                min = i;

    return (min == N) ? 0 : X[min];     // O(n * log n)
}

int main() {
    scanf("%d", &N);
    X.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%ld", &X[i]);
    }

    printf("%ld\n", solve());
}