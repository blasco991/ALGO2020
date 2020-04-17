#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;
vector<vector<int>> m(MAX, std::vector<int>(MAX));

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    ifstream f("input.txt");
    if (f.is_open()) {
        string line, token;
        getline(f, line);
        m.resize(N = atoi(line.c_str()));

        for (int i = 0, j = 0, x; getline(f, line); i++, j = 0) {
            for (stringstream ss(line); getline(ss, token, ' '); j++) {
                x = atoi(token.c_str());
                if (i == 0)
                    m[i] = {{x, j++}};
                else if (j == 0)
                    m[i][j] = x + m[i - 1][j];
                else if (j == i)
                    m[i][j] = x + m[i - 1][j - 1];
                else
                    m[i][j] = x + max(m[i - 1][j - 1], m[i - 1][j]);
            }
            m[i].resize(j);
        }
        f.close();

        cout << *max_element(m[N - 1].begin(), m[N - 1].end()) << endl;
#ifndef EVAL
        for (int i = 0; i < m.size(); i++, cout << endl)
            for (int j : m[i])
                cout << j << " ";
#endif
    }
    return 0;
}