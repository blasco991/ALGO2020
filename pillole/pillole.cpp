#include <iostream>

using namespace std;

long solve(int n, int m = 0) {

    if(n==0 && m==0)
      return 1;

    return (n>0 ? solve(n - 1, m + 1) : 0) + (m>0 ? solve(n, m - 1) : 0);

}

int main() {
    int x;
    cin >> x;
    cout << solve(x);
    return 0;
}
