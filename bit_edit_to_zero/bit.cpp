#include<algorithm>
#include<iostream>
#include<cassert>

using namespace std;

string m1(string s) {
    s[s.size() - 1] = s[s.size() - 1] == '0' ? '1' : '0';
    return s;
}

string m2(string s) {
    for (unsigned i = s.size() - 1; i >= 0; i--)
        if (s[i] == '1') {
            s[i - 1] = s[i - 1] == '0' ? '1' : '0';
            return s;
        }
    return s;
}

int num_mosse(int n) {
    string target;

    for (int m = n; m > 0; m /= 2)
        target += m % 2 == 0 ? '0' : '1';
    reverse(target.begin(), target.end());

    for (string s(target.size(), '0'); s != target; n++)
        s = n % 2 == 0 ? m1(s) : m2(s);

    return n;
}

int mossa(int n) {
    assert(n > 0);
    return num_mosse(n) % 2 == 0 ? 2 : 1;
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int p, n;
    cin >> p >> n;
    assert(p >= 1);
    assert(p <= 2);
    assert(n >= 0);
    if (p == 1)
        cout << num_mosse(n) << endl;
    if (p == 2)
        cout << mossa(n) << endl;

    return 0;
}
