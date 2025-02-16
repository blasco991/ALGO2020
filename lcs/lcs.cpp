#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compare(vector<char> t1, vector<char> t2) {
    int i, j, counter, last_find;
    for (i = counter = last_find = 0; i < t1.size(); i++) {
        for (j = last_find; j < t2.size(); j++) {
            printf("\n%d\n%d\t%c == %c: %d\n", i, j, t1[i], t2[j], t2[j] == t1[i]);
            if (t2[j] == t1[i]) {
                j++;
                counter++;
                last_find = j;
                break;
            }
        }
    }
    return counter;
}

int solve(const vector<char> &t1, const vector<char> &t2) {
    int m1 = compare(t1, t2);
    cout << "\nm1: " << m1 << "\n\nsecond search" << endl;
    int m2 = compare(t2, t1);

    return max(m1, m2);
}

int main() {
    int lt1, lt2;
    vector<char> t1, t2;

    cin >> lt1;
    cin >> lt2;
    t1.resize(lt1);
    for (int i = 0; i < lt1; i++)
        cin >> t1[i];


    t2.resize(lt2);
    for (int i = 0; i < lt2; i++)
        cin >> t2[i];

#ifndef EVAL
    for (int i = 0; i < lt1; i++)
        cout << i << " ";
    cout << endl;
    for (auto c : t1)
        cout << c << " ";
    cout << endl << endl;
    for (int i = 0; i < lt2; i++)
        cout << i << " ";
    cout << endl;

    for (auto c : t2)
        cout << c << " ";
    cout << endl;
#endif

    cout << solve(t1, t2) << endl;
}
