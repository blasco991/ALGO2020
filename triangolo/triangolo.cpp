#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;
vector<vector<int>> m(MAX, std::vector<int>(MAX));
int N;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ifstream file("input.txt");
    if (file.is_open()) {
        string line;
        getline(file, line);
        N = atoi(line.c_str());
        m.resize(N);

        for (int i = 0, j = 0; getline(file, line); m[i].resize(i + 1), i++) {  // O(lines)
            string token;
            stringstream ss(line);
            for (j = 0; getline(ss, token, ' '); j++)                           // O(N)
                m[i][j] = atoi(token.c_str());
        }                                                                               // O(N*lines)
        file.close();

        for (int i = m.size() - 1; i > 0; i--)                                              // O(lines)
            for (int j = 0; j < m[i - 1].size(); j++)                                       // O(N)
                m[i - 1][j] += max(m[i][j], m[i][j + 1]);                                   // O(1)

        cout << m[0][0];                                                                // O(2*N*line)
    }
    return 0;
}