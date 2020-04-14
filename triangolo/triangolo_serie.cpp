#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

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
        string line, token;
        getline(file, line);
        N = atoi(line.c_str());
        m.resize(N);

        getline(file, line);
        m[0][0] = atoi(line.c_str());;
        m[0].resize(1);

        for (int i = 1, j = 0; getline(file, line); i++, j = 0) {             // per ogni livello del triangolo
            stringstream ss(line);
            double k = 0;
            for (; getline(ss, token, ' '); k = k + (0.5)) {          // per ogni numero del livello
                int x = atoi(token.c_str());
                cout << k << " ";
                if (j == 0) {
                    m[i][j] = x;// + m[i - 1][k];
                    j++;
                } else if ((j + 1) / 2 == m[i - 1].size()) {
                    m[i][j] = x;// + m[i - 1][k];
                    j++;
                } else {
                    m[i][j] = x;// + m[i - 1][k];
                    j++;
                    m[i][j++] = x;// + m[i - 1][k + 1];
                    k += 0.5;
                }
            }
            cout << endl;
            m[i].resize(j);
        }
        file.close();

        cout << endl;
        for (int i = 0; i < m.size(); i++, cout << endl)
            for (int j = 0; j < m[i].size(); j++)
                cout << m[i][j] << " ";
        cout << endl;

    }
    return 0;
}

/*

 */