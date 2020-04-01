#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long> A, B, i;

long solve() {

    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(i));

    return *max_element(i.begin(), i.end());
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    B.resize(N);
    for (int i = 0; i < N; i++)
        cin >> B[i];


    cout << solve() << endl;
}
