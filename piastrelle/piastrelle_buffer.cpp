#include <iostream>
#include <fstream>

using namespace std;

int N;
string buffer[25];

void possible1(int n);

void possible2(int n);

void print() {
    for (int i = 0; i < N; ++i)
        cout << buffer[i];
    cout << endl;
}

void possible1(int n) {

    if (n == 0)
        print();
    else {
        buffer[N - n] = "[O]";
        possible1(n - 1);

        buffer[N - n] = "[O]";
        possible2(n - 1);
    }
}

void possible2(int n) {

    if (n == 2) {
        buffer[N - n] = "[OO";
        buffer[N - n + 1] = "OO]";
        print();
    }
    if (n > 2) {
        buffer[N - n] = "[OO";
        buffer[N - n + 1] = "OO]";
        possible1(n - 2);

        buffer[N - n] = "[OO";
        buffer[N - n + 1] = "OO]";
        possible2(n - 2);
    }
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    N = n;
    possible1(n);
    possible2(n);

    return 0;
}