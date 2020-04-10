#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector<int> X;

int canEat(int i) {
    if (i == N)
        return 0;

    return (X[i] > X[i + 1] ? 1 : 0) + canEat(i + 1);

}

int possible(int n) {
    int ps[N];

    for (int i = 0; i < N; i++)
        ps[i] = canEat(i);

    return count(ps, ps + N, 0);
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

    cout << possible(N);
}