#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ifstream f("input.txt");
    if (f.is_open()) {
        string line, token;
        getline(f, line);
        vector<vector<int>> m(2, vector<int>(atoi(line.c_str())));
        getline(f, line);
        m[0][1] = m[0][0] = atoi(line.c_str());

        for (int i = 1, j = 0, x; getline(f, line); i++, j = 0) {
            for (stringstream ss(line); getline(ss, token, ' '); j++) {
                x = atoi(token.c_str());
                if (j == 0)
                    m[1][j] = x + m[0][j];
                else if (j == i)
                    m[1][j] = x + m[0][j - 1];
                else
                    m[1][j] = x + max(m[0][j - 1], m[0][j]);
            }
            std::rotate(m.begin(), m.begin() + 1, m.end());
        }
        f.close();

        cout << *max_element(m[0].begin(), m[0].end()) << endl;
#ifndef EVAL
        for (int i = 0; i < m.size(); i++, cout << endl)
            for (int j : m[i])
                cout << j << " ";
#endif
    }
    return 0;
}