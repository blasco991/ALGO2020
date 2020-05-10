#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#include <map>

using namespace std;

map<string, int> cache;

int main() {

    int d, s;
    cin >> d;
    cin >> s;

    for (unsigned long long i = d; i < ULLONG_MAX; i += d) {
        cout << i << endl;
        vector<int> digits;

        string str = to_string(i);

        for (auto x : str)
            digits.push_back(x - '0');

        int c;
        if (cache.find(str.substr(str.size() - 1)) != cache.end())
            c = cache.at(str.substr(str.size() - 1)) + (str[0] - '0');
        else
            c = cache[str] = accumulate(digits.begin(), digits.end(), 0L);

        if (c == s) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}