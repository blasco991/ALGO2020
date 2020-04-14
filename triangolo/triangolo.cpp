#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;
int m[MAX][MAX];
int N;
vector<int> accs(MAX);

void traverse(int acc, int i, int j) {
    if (i < N - 1) {
        traverse(acc + m[i][j], i + 1, j);
        traverse(acc + m[i][j], i + 1, j + 1);
    } else if (accs[j] < acc + m[i][j])
        accs[j] = acc + m[i][j];
}

int max(int n) {
    accs.resize(n);
    traverse(0, 0, 0);

    return *max_element(accs.begin(), accs.end());
}

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

        for (int i = 0; getline(file, line); i++) {
            string token;
            stringstream ss(line);
            for (int j = 0; getline(ss, token, ' '); j++)
                m[i][j] = atoi(token.c_str());
        }
        file.close();


        cout << max(N) << endl;

    }
    return 0;
}