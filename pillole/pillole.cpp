#include <iostream>

using namespace std;

string solve(int n, int m = 0, string r = "") {

    if(n==0 && m==0)
      return r + " ";

    return (n>0 ? solve(n - 1, m + 1, r + "I") : "") + (m>0 ? solve(n, m - 1, r + "M") : "");

}

int main() {
    int x;
    cin >> x;
    cout << solve(x);
    return 0;
}
