#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#include <map>
#include <string>

using namespace std;
int d, s;
map<string, int> cache;

unsigned long long findNum(unsigned long long n) {

    string str = to_string(n);
    vector<int> digits;

    for (auto x : str)
        digits.push_back(x - '0');

    int c;
    if (cache.find(str.substr(str.size() - 1)) != cache.end())
        c = cache.at(str.substr(str.size() - 1)) + (str[0] - '0');
    else
        c = cache[str] = accumulate(digits.begin(), digits.end(), 0L);

    //printf("called %llu\t%d\n", n, c);

    if (c == s)
        return n;

    if (n + d < 0)
        return -1;

    return findNum(n + d);
}

int main() {

    cin >> d;
    cin >> s;

    cout << findNum(d) << endl;

    return 0;
}