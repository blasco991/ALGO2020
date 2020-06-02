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
        //cout << i << endl;

        unsigned long long sum = 0;
        for (unsigned long long k = i; k > 0; k /= 10)
            sum += k % 10;

        //cout << sum << endl << endl;

        if (sum == s) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}