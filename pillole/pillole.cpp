#include <iostream>

using namespace std;

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
