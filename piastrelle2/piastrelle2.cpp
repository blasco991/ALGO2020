#include <iostream>
#include <fstream>

using namespace std;

int H(int n);

int G(int n);

void Hp(int n);

void Gp(int n);

int N;
int cache[2][10];

int F(int n) {
    return n == 0 ? 1 : (n == 1 ? 2 : F(n - 1) + G(n - 1) + H(n - 2));
}

int G(int n) {
    return n == 0 ? 1 : F(n) + G(n - 1);
}

int H(int n) {
    return n == 0 ? 2 : F(n) + G(n);
}

void Fp(int n) {
    if (n == 0)
        return;
    if (n == 1) {

        return 2;
    }

    return F(n - 1) + G(n - 1) + H(n - 2);
}

void Gp(int n) {
    if (n == 0)
        return 1;
    return F(n) + G(n - 1);
}

void Hp(int n) {
    if (n == 0)
        return 2;
    return F(n) + G(n);
}

void print() {
    for (int i = 0; i < N; ++i)
        cout << cache[0][i];
    cout << endl;
    for (int i = 0; i < N; ++i)
        cout << cache[1][i];
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    N = n;
    cout << F(n) << endl;
    print();
    return 0;
}