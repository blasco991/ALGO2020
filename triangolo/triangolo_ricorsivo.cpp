#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;
int m[MAX][MAX];
int cache[MAX][MAX];
int N;

int traverse(int i, int j) {
    if (cache[i][j] != -1)
        return cache[i][j];

    if (i == N - 1)
        return cache[i][j] = m[i][j];

    return cache[i][j] = m[i][j] + max(traverse(i + 1, j), traverse(i + 1, j + 1));

}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::fill(*cache, *cache + MAX * MAX, -1);

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

        cout << traverse(0, 0);

    }
    return 0;
}