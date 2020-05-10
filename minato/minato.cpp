#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int N, M;
vector<vector<char>> m;
vector<vector<int>> cache;

int solve(int i, int j, int counter = 0) {

    if (cache[i][j] != -1) return cache[i][j];

    if (i == N - 1 && j == M - 1) return cache[i][j] = 1;

    if ((i + 1) < N && m[i + 1][j] == '*')
        counter += solve(i + 1, j);
    if ((j + 1) < M && m[i][j + 1] == '*')
        counter += solve(i, j + 1);

    return cache[i][j] = counter;
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char x;
    cin >> N;
    cin >> M;
    m.resize(N);
    cache.resize(N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> x;
            m[i].push_back(x);
            cache[i].push_back(-1);
        }

#ifndef EVAL
    cout << endl << N << " " << M << endl;
    for (int i = 0; i < N; i++, cout << endl)
        copy(m[i].begin(), m[i].end(), ostream_iterator<char>(cout, ""));
#endif
    cout << solve(0, 0) << endl;

    return 0;
}