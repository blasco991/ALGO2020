#include<cassert>
#include<iostream>
#include <cmath>       /* log2 */

using namespace std;

//##########################################
// BEGIN: modifica entro quest'area

int num_mosse(int n) {
    return (int) floor(log2(n)) + 1;
}

int mossa(int n) {
    assert(n > 0);
    return 1;
}

// END: modifica entro quest'area
// ################################################


int main() {
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
