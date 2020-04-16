#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long> t1, t2, i;

long solve() {

    set_intersection(t1.begin(), t1.end(), t2.begin(), t2.end(), back_inserter(i));

    return *max_element(i.begin(), i.end());
}

int main() {
    cin >> N;
    t1.resize(N);
    for (int i = 0; i < N; i++)
        cin >> t1[i];

    t2.resize(N);
    for (int i = 0; i < N; i++)
        cin >> t2[i];


    cout << solve() << endl;
}
