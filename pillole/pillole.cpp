#include <iostream>

using namespace std;

string eatI(int n, int p);

string eatM(int n, int p);

string eatI(int n, int p) {

    return "I" + eatI(n - 1, p) + "I" + eatM(n - 1, p);
}

string eatM(int n, int p) {


    return "M" + eatI(n - 1, p) + eatM(n - 1, p);
}

string solve(int n, int m = 0, string r = "") {
    cout << n << " " << m << endl;

    string eatI = (n > 0 ? solve(n - 1, m + 1, r + "I") : "I" + r);

    string eatM = (m > 0 ? solve(n, m - 1, r + "M") : "I" + r);


    return eatI + eatM;
}

int main() {
    int x;
    cin >> x;
    cout << solve(x - 1);
    return 0;
}
