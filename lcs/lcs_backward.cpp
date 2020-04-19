#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lt1, lt2;
const int MAX = 1000;
vector<vector<int>> cache(MAX, vector<int>(MAX));
vector<char> t1, t2;

#ifndef EVAL

void printCache() {
    for (int i = 0; i < cache.size(); i++, cout << endl)
        for (int j : cache[i])
            cout << j << " ";
}

#endif

int solve(int i, int j) {

    if (i == 0 || j == 0)
        return 0;

    if (cache[i][j] != 0)
        return cache[i][j];

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

#ifndef EVAL
/*
    for (int i = 0; i < lt1; i++)
        cout << i << " ";
    cout << endl;
    for (auto c : t1)
        cout << c << " ";
    cout << endl << endl;
    for (int i = 0; i < lt2; i++)
        cout << i << " ";
    cout << endl;
    for (auto c : t2)
        cout << c << " ";
    cout << endl;*/
#endif

    cout << solve(lt1 - 1, lt2 - 1) << endl;
    printCache();

}
