#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N = 100000;
vector<int> inc;

int count_consec(int i, int j) {
    return *max_element(inc.begin() + i, inc.begin() + j);
}

void update_inc(int i = 0) {
    for (int prev = 0; i < N; i++) {
        inc[i] = inc[i] != 0 ? inc[i] + prev : 0;
        prev = inc[i];
    }
}

void flipBits(int i, int j) {
    for (int k = i; k < j; k++)
        inc[k] = inc[k] == 0 ? 1 : 0;
    update_inc(i - 1);
}

int main() {
    cin >> N;
    inc.resize(N);
    for (int i = 0; i < N; i++)
        cin >> inc[i];
    update_inc();

    int M;
    cin >> M;

    for (int k = 0, t, i, j; k < M; k++) {
        cin >> t >> i >> j;
        if (t == 0)
            cout << count_consec(i - 1, j - 1) << endl;
        else flipBits(i - 1, j);
#ifndef EVAL
        printf("%d %d %d\n", t, i, j);
        copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
        cout << endl << endl;
#endif
    }

}