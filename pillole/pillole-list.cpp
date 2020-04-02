#include <iostream>

using namespace std;

string solve(int n, int m = 0, string r = "") {

    if(n==0 && m==0)
      return r + " ";

    return (n>0 ? solve(n - 1, m + 1, r + "I") : "") + (m>0 ? solve(n, m - 1, r + "M") : "");

}

long solveN(int n, int m = 0) {

    if(n==0 && m==0)
      return 0;

    return (n>0 ? 1 + solveN(n - 1, m + 1) : 0) + (m>0 ? 1 + solveN(n, m - 1) : 0);

}

int main() {
    int x;
    cin >> x;
    cout << solveN(x);
    return 0;
}
