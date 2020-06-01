#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N;
vector<int> inc;

int count_consec(int i, int j) {
    int max_c = 0;
    for (int counter = 0; i < j; i++) {
        if (inc[i] == 1) {
            max_c = max(max_c, ++counter);
        } else counter = 0;
    }
    return max_c;
}

void flipBits(int i, int j) {
    for (int k = i; k < j; k++)
        inc[k] = inc[k] == 0 ? 1 : 0;
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N;
    inc.resize(N);
    for (int i = 0; i < N; i++)
        cin >> inc[i];

    int M;
    cin >> M;

    for (int k = 0, t, i, j; k < M; k++) {
        cin >> t >> i >> j;
#ifndef EVAL
        printf("%d %d %d\n", t, i, j);
        copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
#endif
        i--;
        if (t == 0)
            cout << count_consec(i, j) << endl;
        else flipBits(i, j);
#ifndef EVAL
        cout << endl;
#endif
    }

}