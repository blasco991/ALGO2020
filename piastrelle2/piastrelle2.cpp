#include <iostream>
#include <fstream>

using namespace std;

int H(int n);

int G(int n);

void Hp(int n);

void Gp(int n);

int N, color;
int buffer[2][10];

int F(int n) {
    return n == 0 ? 1 : (n == 1 ? 2 : F(n - 1) + G(n - 1) + H(n - 2));
}

int G(int n) {
    return n == 0 ? 1 : F(n) + G(n - 1);
}

int H(int n) {
    return n == 0 ? 2 : F(n) + G(n);
}

void print() {
    for (int i = 0; i < N; ++i)
        cout << buffer[0][i];
    cout << endl;
    for (int i = 0; i < N; ++i)
        cout << buffer[1][i];
    cout << endl << endl;
}

int getColor(int size, int row, int n) {
    if (n == N - 1 && row != 1)
        return 1;

    for (int i = 1; i <= 3; i++) {
        if (size == 1) {
            if (buffer[row][n - 1] != i && buffer[(row + 1) % 2][n] != i)
                if (buffer[row][n + 1] != i || n == N)
                    return i;
        } else if (buffer[row][n - 1] != i && buffer[(row + 1) % 2][n] != i && buffer[(row + 1) % 2][n + 1] != i)
            if (buffer[row][n + 2] != i || n == N)
                return i;
    }

    return 0;
}

void Fp(int n) {
    if (n == 0)
        return print();

    if (n == 1) {
        //return 2;
        buffer[0][n % N] = getColor(1, 0, n);
        buffer[1][n % N] = getColor(1, 1, n);
        print();
        buffer[0][n % N] = buffer[1][n % N] = getColor(1, 0, n);
        return print();
    }

    buffer[0][n % N] = buffer[1][n % N] = getColor(1, 1, n);
    Fp(n - 1);
    buffer[0][n % N] = buffer[1][n % N] = 0;

    buffer[0][n % N] = getColor(1, 0, n);
    Gp(n - 1);
    buffer[0][n % N] = 0;

    buffer[0][n % N] = buffer[0][n + 1] = getColor(2, 0, n);
    Hp(n - 2);
    buffer[0][n % N] = buffer[0][n + 1] = 0;
}

void Gp(int n) {
    if (n == 0) {
        //return 1;
        buffer[1][n - 1] = getColor(1, 1, n - 1);
        return print();
    }
    buffer[0][n - 1] = buffer[1][n % N] = getColor(1, 1, n - 1);
    Fp(n);
    buffer[0][n - 1] = buffer[1][n % N] = 0;

    buffer[0][n % N] = getColor(1, 0, n % N);
    Gp(n - 1);
    buffer[0][n % N] = 0;
}

void Hp(int n) {
    if (n == 0) {
        //return 2;
        buffer[1][n - 1] = buffer[1][n - 2] = getColor(1, 0, n - 1);
        return print();
    }
    buffer[0][n - 1] = buffer[1][n % N] = getColor(1, 1, n - 1);
    Fp(n);
    buffer[0][n - 1] = buffer[1][n % N] = 0;

    buffer[0][n - 1] = getColor(1, 0, n - 1);
    Gp(n);
    buffer[0][n - 1] = 0;
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    N = n;
    cout << F(n) << endl << endl;
    Fp(n);

    return 0;
}