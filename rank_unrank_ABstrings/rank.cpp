#include <iostream>
#include <algorithm>

using namespace std;

long pow(int base, unsigned long pow) {
    long n = 1;
    if (pow != 0)
        for (int i = 1; i < pow; i++)          // O(p)
            n *= base;
    return n;
}

long ABstring2rank(string s) {
    long n = 0;
    for (int i = 0; i < s.length(); i++)                                     // O(n)
        n += s[i] - 'A' > 0 ? pow(2, s.length() - i) : 0;        // O(p)
    return n;                                                               // O(n*p)
}

string ABstring_of_len_and_rank(int n, int length) {
    string s;
    for (int i = 0; i < length; i++, n /= 2)                                // O(length)
        s += n % 2 == 1 ? 'B' : 'A';                                        // O(1)
    reverse(s.begin(), s.end());                                            // O(length)
    return s;                                                               // O(length)
}

int main() {
    int length, r;

    if (scanf("%d %d", &length, &r) == 2) {
        cout << ABstring_of_len_and_rank(r, length) << endl;
    } else {
        string input;
        cin >> input;
        cout << ABstring2rank(input) << endl;
    }

}