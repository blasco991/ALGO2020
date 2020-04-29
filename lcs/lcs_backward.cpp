#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lt1, lt2;
const int MAX = 1000;

vector<vector<int>> cache(MAX, vector<int>(MAX));
vector<char> t1, t2;

int solve(int i, int j) {
    if (i == -1 || j == -1) return 0;

    if (cache[i][j] != 0) return cache[i][j];

    if (t1[i] == t2[j])
        return cache[i][j] = 1 + solve(i - 1, j - 1);

    return cache[i][j] = max(solve(i - 1, j), solve(i, j - 1));
}

int main() {
    cin >> lt1;
    cin >> lt2;

    cache.resize(lt1);
    for (auto &i : cache)
        i.resize(lt2);

    t1.resize(lt1);
    for (int i = 0; i < lt1; i++)
        cin >> t1[i];

    t2.resize(lt2);
    for (int i = 0; i < lt2; i++)
        cin >> t2[i];

    cout << solve(lt1 - 1, lt2 - 1) << endl;
}
