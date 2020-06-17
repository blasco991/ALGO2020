#include <iostream>
#include <map>

using namespace std;

int N, B;
map<int, int> plates;

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++)
        cin >> plates[i];
#ifndef EVAL
    //for (auto &t : plates) std::cout << t.first << " " << t.second << endl;
#endif
    for (int spent = 0; spent < B;) {
        int max = plates.rbegin()->second;
        if (spent + max > B)
            return 0;
        spent += max;
        cout << max << endl;
        plates.erase(plates.rbegin()->first);
    }

    return 0;
}