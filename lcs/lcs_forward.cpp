#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<char> t1, t2;
const int MAX = 1000;
int lt1, lt2, cache[MAX][MAX];

int solve(int i, int j) {
    if (cache[i][j] != 0) return cache[i][j];

    if (i == lt1 || j == lt2) return cache[i][j] = 0;

    if (t1[i] == t2[j])
        return cache[i][j] = 1 + solve(i + 1, j + 1);

    return cache[i][j] = max(solve(i + 1, j), solve(i, j + 1));

}

int main() {
    cin >> lt1;
    cin >> lt2;

    t1.resize(lt1);
    for (int i = 0; i < lt1; i++)
        cin >> t1[i];

    t2.resize(lt2);
    for (int i = 0; i < lt2; i++)
        cin >> t2[i];

    cout << solve(0, 0) << endl;
}
