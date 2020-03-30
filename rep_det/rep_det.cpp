#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<long> X;
int N;

long solve() {

    unsigned int min = N;
    set<long> viewed;
    set<long>::iterator it;

    for (unsigned int i = 0; i < N - 1; viewed.insert(X[i++]))
        if (X[i] < X[min] || min == N) {
            it = viewed.find(X[i]);
            if (it != viewed.end())
                min = i;
        }

    /*
    for (unsigned int j = i + 1; j < N; j++)
        if (X[j] < X[min] || min == N)
            if (X[j] == X[i]) {
                min = i;
                break;
            }*/

    return (min == N) ? 0 : X[min];
}

int main() {
    scanf("%d", &N);
    X.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%ld", &X[i]);
    }

    printf("%ld\n", solve());
}
